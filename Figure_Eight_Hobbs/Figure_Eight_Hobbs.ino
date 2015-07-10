/* B3_TimedForward.ino
   Drive the TWO-WHEELED Bread Board Bot (BBbot, B^3)
   straight ahead for specified time and then stop
   
   Intially commented out code will impliment a a short 
   reverse brake on the motors. 

   Arduino: Arduino Mega 256 v3 Clone
   Motor Shield: Adafruit assembled Motor Shield for Arduino v2
   ---->  http://www.adafruit.com/products/1438

   Programmer: Dave Eslinger (DLE); June 3, 2015
   Major revisions:  
         6/7/2015, DLE: Cleaned it up for GoSciTech
         7/4/2015 DLE renamed

*/
#include <Wire.h>
#include <Adafruit_MotorShield.h> 
#include <math.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Define Constants(in all caps)
const byte TESTSPEED = 75;

// Define 'ports' for motors.
const byte LEFT_MOTOR_PORT = 3;
const byte RIGHT_MOTOR_PORT = 1;
// Create pointers to motor control objects
Adafruit_DCMotor *motorLeft = AFMS.getMotor(LEFT_MOTOR_PORT);
Adafruit_DCMotor *motorRight = AFMS.getMotor(RIGHT_MOTOR_PORT);

void setup(void){
  AFMS.begin();  // create with the default frequency 1.6KHz
  // Turn off all motors
  motorLeft->run(RELEASE);
  motorRight->run(RELEASE);
}

void loop(void){
  // Drive forward for 1 second at X/255 (~60% power)
  int duration = 1000;
  byte speed = 125;
  
  
  
  
  motorLeft->setSpeed(50);
  motorRight->setSpeed(90);
  
  motorLeft->run(FORWARD);
  motorRight->run(FORWARD);
  
  delay(9000);
  

  
  motorLeft->setSpeed(90);
  motorRight->setSpeed(50);
  
  motorLeft->run(FORWARD);
  motorRight->run(FORWARD);
  
  delay(9000);
  
  motorLeft->run(RELEASE);
  motorRight->run(RELEASE);
  
  delay(2000);
  
  
  
  motorLeft->setSpeed(50);
  motorRight->setSpeed(90);
  
  motorLeft->run(FORWARD);
  motorRight->run(FORWARD);
  
  delay(9000);
  

  
  motorLeft->setSpeed(90);
  motorRight->setSpeed(50);
  
  motorLeft->run(FORWARD);
  motorRight->run(FORWARD);
  
  delay(9000);
  
  motorLeft->run(RELEASE);
  motorRight->run(RELEASE);
  
  delay(2000);
  

  while (1) {};
}

void allStop(int direction) {
  motorLeft->setSpeed(90);
  motorRight->setSpeed(50);
  if (direction == FORWARD) {
   motorLeft->run(RELEASE);
    motorRight->run(RELEASE);
  }
  else {
    motorLeft->run(RELEASE);
   motorRight->run(RELEASE);
  }
  delay(1000);
  motorLeft->run(RELEASE);
  motorRight->run(RELEASE);
  return;
}

