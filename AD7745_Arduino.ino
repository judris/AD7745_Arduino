#include <Wire.h> //I2C library

double capacitance = 0; //capacitance reading

int DataReady = B0000; //

int StatusAddress = 0x00;
int CapDataH = 0x01;
int CapDataM = 0x02;
int CapDataL = 0x03;
int Address = B1001000;

int CapSetup = 0x07;        //capacitive channel setup address
int ExcSetup = 0x09;        //excitation setup address
int ConfigSetup = 0x0A;     //configuration setup addrss
int CapDacAReg = 0x0B;      //Capacitive DAC setup address
int CapGainRegH = 0x0F;     //Cap gain high adress 
int CapGainRegL = 0x10;     //Cap gain high adress 
int CapOffsetH = 0x0D;      //Cap Offset high adress 
int CapOffsetL = 0x0E;      //Cap gain Offset adress 

int CapChanProp = B10100000;    //capacitive channel properties
int ExcProp = B01100011;        //excitation properties
int ConfigProp = B00111001;     //configuration properties
int CapDacProp = B0;            //Capacitive DAC setup properties
int CapGainPropH = B01011101;   //cap gain properties high
int CapGainPropL = B10111101;   //cap gain properties low
int CapOffsetPropH = B01110111; //cap offset properties high
int CapOffsetPropL = B00011010; //cap Offset properties low


void setup()
{
 Serial.begin(9600);
 Wire.begin();

 Configuration(); //determine configuration properties in AD7745
 
 Excitation(); //determine the excitation properties of the AD7745
 
 CapInput(); //Capacitive input properties
 
 CapDacARegister(); //Capacitive data aquisition properties
 CapOffsetHighAdjust(); //The adjustment of the offset (mainly used in differential mode)
 CapOffsetLowAdjust();  //The adjustment of the offset (mainly used in differential mode)
 
// addressRead(); //Reads address and provides binary value (used for debugging)
 
 continuous(); //sets up continuous reading of the AD7745
 
// CapGainHighAdjust(); //used for adjusting the gain of AD7745
// CapGainLowAdjust();   //used for adjusting the gain of AD7745

delay(15); // delay before the loop starts

}

void loop()
{
  statusRead(); //reads the status of the AD7745
  if (statusRead() &0 == DataReady) { //if the capacitive conversion has been completed
//  addressRead();
  dataRead(); //read the data from capacitive registers of AD7745
  }
}
