#include <Servo.h>
 
int servoPinA     = 9;
int servoPinG     = 10; 
int ldrleftop     = A0;
int ldrrightop    = A1;
int ldrleftdown   = A2;
int ldrrightdown  = A3;
int sleep         = 200;
int MinAngle      = 1;
int MaxAngle      = 179;
int AzAngle       = 1;
int GradAngle     = 1;
int ldazimuth     = 0;
int ldgradient    = 0;
int diffazgd      = 0;
int Tolerance     = 10;

Servo azimuth; 
Servo gradient;  
 

 
void setup()
{
  Serial.begin(9600);  
  azimuth.attach(servoPinA);
  gradient.attach(servoPinG);
  azimuth.write(AzAngle);
  gradient.write(GradAngle);
}
 
 
void loop()
{
ldazimuth = (analogRead(ldrleftop) - analogRead(ldrrightop));
ldgradient = (analogRead(ldrleftdown) - analogRead(ldrrightdown));
diffazgd = ldazimuth - ldgradient;
//Serial.print(F("Value read ldrleftdown:"));
//Serial.println(analogRead(ldrleftdown));
//Serial.print(F("Value read ldrrightdown:"));
//Serial.println(analogRead(ldrrightdown));
Serial.print(F("Value read ldazimuth:"));
Serial.print(ldazimuth);
Serial.print(F(" Value read ldgradient:"));
Serial.print(ldgradient);
Serial.print(F(" Value read diffazgd:"));
Serial.println(diffazgd);
delay(sleep);

//driving azimuth motor
if (( ldazimuth < 0) && (ldazimuth < -Tolerance)) {
  //then < 0 go to the left
  if (AzAngle > MinAngle) {
    
    AzAngle =  AzAngle -1;
  }
  azimuth.write(AzAngle);
}
else if ((ldazimuth > 0) &&  (ldazimuth > Tolerance)) {
  // then > 0 go to the right
   if (AzAngle < MaxAngle) {
    AzAngle =  AzAngle +1;
  }
  azimuth.write(AzAngle);
}
// driving gradient motor

if (( diffazgd < 0) && (diffazgd < -Tolerance)) {
//  //then < 0 go to the left
  if (GradAngle > MinAngle) {
    
    GradAngle =  GradAngle -1;
  }
  gradient.write(GradAngle);
}
else if ((diffazgd > 0) &&  (diffazgd > Tolerance)) {
  // then > 0 go to the right
   if (GradAngle < MaxAngle) {
    GradAngle =  GradAngle +1;
  }
 gradient.write(GradAngle);
}
}
