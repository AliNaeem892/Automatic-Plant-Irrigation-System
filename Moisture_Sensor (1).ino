#include <LiquidCrystal.h>  
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 

int sensor_pin = A0; 
int output_value;

int pump = 8;

void setup() {
  lcd.begin(16, 2);  
  lcd.clear();  
  lcd.setCursor(0, 0);  
  lcd.print("     Welcome    "); 
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  pinMode(sensor_pin, INPUT);
  pinMode(pump, OUTPUT);digitalWrite(pump, HIGH);
  delay(1000);
  lcd.clear(); 
  }

void loop() {
output_value= analogRead(sensor_pin);
output_value = map(output_value,0,1023,100,0);

if(output_value<35){digitalWrite(pump, LOW);}
if(output_value>70){digitalWrite(pump, HIGH);}

lcd.setCursor(0, 0);  
lcd.print("    Moisture"); 
lcd.setCursor(7, 1);  
lcd.print(output_value); 
lcd.print(" %   "); 

delay(100);
}
