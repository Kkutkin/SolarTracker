#include <Servo.h>
 
int servoPinA     = 9;
int servoPinG     = 10; 
int ldrleftop     = A0;
int ldrrightop    = A1;
int ldrleftdown   = A2;
int ldrrightdown  = A3;
int sleep         = 100;
int MinAngle      = 1;
int MaxAngle      = 179;
int AzAngle       = 1;
int GradAngle     = 1;
int ldazimuth     = 0;
int ldgradient     = 0;
int Tolerance     = 10;

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
ldazimuth = (analogRead(ldrleftop) - analogRead(ldrrightop));
ldgradient = (analogRead(ldrleftdown) - analogRead(ldrrightdown));
Serial.print(F("Value read ldazimuth:"));
Serial.println(ldazimuth);
//Serial.print(F("Value read ldgradient:"));
//Serial.println(ldgradient);

delay(sleep);
//driving azimuth motor
if (( ldazimuth < 0) && (ldazimuth < -Tolerance)) {
  //then < 0 go to the left
  if (AzAngle > 1) {
    AzAngle =  AzAngle -1;
  }
  azimuth.write(AzAngle);
}
else if ((ldazimuth > 0) &&  (ldazimuth > Tolerance)) {
  // then > 0 go to the right
   if (AzAngle < 179) {
    AzAngle =  AzAngle +1;
  }
  azimuth.write(AzAngle);
}
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
