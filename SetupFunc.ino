void Configuration()
{
 Wire.beginTransmission(Address);
    
  Wire.write(ConfigSetup);
  
  Wire.write(ConfigProp);
  
  Wire.endTransmission();
}

void CapGainHighAdjust()
{
 Wire.beginTransmission(Address);
    
  Wire.write(CapGainRegH);
  
  Wire.write(CapGainPropH);
  
  Wire.endTransmission();
}

void CapGainLowAdjust()
{
 Wire.beginTransmission(Address);
    
  Wire.write(CapGainRegL);
  
  Wire.write(CapGainPropL);
  
  Wire.endTransmission();
}

void Excitation()
{
  Wire.beginTransmission(Address);
    
  Wire.write(ExcSetup);
  
  Wire.write(ExcProp);
  
  Wire.endTransmission();
}

void CapInput()
{
 Wire.beginTransmission(Address);
    
  Wire.write(CapSetup);
  
  Wire.write(CapChanProp);
  
  Wire.endTransmission();
}  
void CapDacARegister()
{
  Wire.beginTransmission(Address);
    
  Wire.write(CapDacAReg);
  
  Wire.write(CapDacProp);
  
  Wire.endTransmission();
}

void CapOffsetHighAdjust()
{
 Wire.beginTransmission(Address);
    
  Wire.write(CapOffsetH);
  
  Wire.write(CapOffsetPropH);
  
  Wire.endTransmission();
}

void CapOffsetLowAdjust()
{
 Wire.beginTransmission(Address);
    
  Wire.write(CapOffsetL);
  
  Wire.write(CapOffsetPropL);
  
  Wire.endTransmission();
}
