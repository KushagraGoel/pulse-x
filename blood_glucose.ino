#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
const int soil =  A0;   
int ir1state=0;
int ir2state=0;
int vout=0;
int xout=0;
int yout=0;
int zout=0;
void setup()
{
pinMode(soil,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
delay(500);
}
void loop()
{
ir1state=analogRead(soil);
ir2state=(8*10^-5)*ir1state^2;
xout=0.1873*ir1state;
yout=ir2state+xout+46.131;
vout=yout*(-1);
zout=vout/100;
Serial.println(ir1state);
Serial.println(ir2state);
Serial.print("GLUCOSE LEVEL\n");
Serial.print("GLUCOSE in mg/dl: ");
Serial.println(zout);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("GLUCOSE LEVEL");
lcd.setCursor(0,1);
lcd.print("MONITOR SYSTEM");
delay(1000);

if ((ir1state<=300)&&(ir1state>=20))
{    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("GLUCOSE LEVEL");
   lcd.setCursor(0,1);
   lcd.print("MONITOR SYSTEM");
   delay(1000);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("GLUCOSE in mg/dl:");
   lcd.setCursor(0,1);
   lcd.print(zout);
   delay(2000);
}
else
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("GLUCOSE LEVEL");
lcd.setCursor(0,1);
lcd.print("MONITOR SYSTEM");
delay(1000);
}
}
