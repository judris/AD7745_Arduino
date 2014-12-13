//used for debugging
 byte addressRead()
{
  Wire.beginTransmission(Address);
    
  Wire.write(0x00);
  
  Wire.endTransmission();
  
  Wire.requestFrom(Address, 20);
  
  while(Wire.available() == 0);
  
  byte Status = Wire.read();
  byte Cap_Data_H = Wire.read();
  byte Cap_Data_M = Wire.read();
  byte Cap_Data_L = Wire.read();
  byte VT_Data_H = Wire.read();
  byte VT_Data_M = Wire.read();
  byte VT_Data_L = Wire.read();
  byte Cap_Setup = Wire.read();
  byte VT_Setup = Wire.read();
  byte EXC_Setup = Wire.read();
  byte Configuration = Wire.read();
  byte Cap_DAC_A = Wire.read();
  byte Cap_DAC_B = Wire.read();
  byte Cap_Offset_H = Wire.read();
  byte Cap_Offset_L = Wire.read();
  byte Cap_Gain_H = Wire.read();
  byte Cap_Gain_L = Wire.read();
  byte Volt_Gain_H = Wire.read();
  byte Volt_Gain_L = Wire.read();
  
  Serial.print("Status");
  Serial.println(Status, BIN);
  
  Serial.print("Cap_Data_H");
  Serial.println(Cap_Data_H, BIN);
  
  Serial.print("Cap_Data_M");
  Serial.println(Cap_Data_M, BIN);
  
  Serial.print("Cap_Data_L");
  Serial.println(Cap_Data_L, BIN);
  
  Serial.print("VT_Data_H");
  Serial.println(VT_Data_H, BIN);
  
  Serial.print("VT_Data_M");
  Serial.println(VT_Data_M, BIN);
  
  Serial.print("VT_Data_L");
  Serial.println(VT_Data_L, BIN);
  
  Serial.print("Cap_Setup");
  Serial.println(Cap_Setup, BIN);
  
  Serial.print("VT_Setup");
  Serial.println(VT_Setup, BIN);
  
  Serial.print("EXC_Setup");
  Serial.println(EXC_Setup, BIN);
  
  Serial.print("Configuration");
  Serial.println(Configuration, BIN);
  
  Serial.print("Cap_DAC_A");
  Serial.println(Cap_DAC_A, BIN);
  
  Serial.print("Cap_DAC_B");
  Serial.println(Cap_DAC_B, BIN);
  
  Serial.print("Cap_Offset_H");
  Serial.println(Cap_Offset_H, BIN);
  
  Serial.print("Cap_Offset_L");
  Serial.println(Cap_Offset_L, BIN);
  
  Serial.print("Cap_Gain_H");
  Serial.println(Cap_Gain_H, BIN);
  
  Serial.print("Cap_Gain_L");
  Serial.println(Cap_Gain_L, BIN);
  
  Serial.print("Volt_Gain_H");
  Serial.println(Volt_Gain_H, BIN);
  
  Serial.print("Volt_Gain_L");
  Serial.println(Volt_Gain_L, BIN);
}

//sets up continuous reading of the AD7745
byte continuous()
{
 Wire.beginTransmission(Address);
  
  Wire.write(StatusAddress);
//  Wire.write(CapDataM);
//  Wire.write(CapDataL);
//  Wire.write(CapDataL);
  
  Wire.endTransmission(); 
}

//Used to check if the AD7745 capacitive conversion has been completed
byte statusRead(){
  Wire.beginTransmission(Address);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.requestFrom(Address, 1);
  while(Wire.available() == 0);
  byte Status = Wire.read();
//  Serial.print("Status");
//  Serial.println(Status, BIN);
}
