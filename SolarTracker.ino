#include <Servo.h>
 
int servoPinA     = 9;
int servoPinG     = 10; 
int ldrleftop     = A0;
int ldrrightop    = A1;
int ldrleftdown   = A2;
int ldrrightdown  = A3;
int sleep         = 1000;
Servo azimuth; 
Servo gradient;  
 

 
void setup()
{
  Serial.begin(9600);  
  azimuth.attach(servoPinA);
  gradient.attach(servoPinG);
}
 
 
void loop()
{
  // Redaing value from analog Pin
  int valueldrleftop  = analogRead(ldrleftop);
  int valueldrrightop = analogRead(ldrrightop);
//  int valueldrleftdown  = analogRead(ldrleftdown);
//  int valueldrrightdown = analogRead(ldrrightdown);

Serial.print(F("Value read ldrleftop:"));
Serial.println(valueldrleftop);
Serial.print(F("Value read ldrrightop:"));
Serial.println(valueldrrightop);
delay(sleep);
//control the servo's direction and the position of the motor

//   azimuth.write(1);      // Turn SG90 servo Left to 1 degrees
//    gradient.write(1);      // Turn SG90 servo Left to 1 degrees
//   delay(10000); 
//   azimuth.write(45);      // Turn SG90 servo Left to 45 degrees
//   gradient.write(45);      // Turn SG90 servo Left to 45 degrees
//   delay(10000);          // Wait 10 seconds
//   azimuth.write(90);      // Turn SG90 servo back to 90 degrees (center position)
//   gradient.write(90);      // Turn SG90 servo back to 90 degrees (center position)
//   delay(10000);          // Wait 10 seconds
//   azimuth.write(135);     // Turn SG90 servo Right to 135 degrees
//   gradient.write(135);     // Turn SG90 servo Right to 135 degrees
//   delay(10000);          // Wait 10 seconds
//   azimuth.write(179);      // Turn SG90 servo back to 179 degrees (center position)
//   gradient.write(179);      // Turn SG90 servo back to 179 degrees (center position)
//   delay(10000);
 

 
 
}
