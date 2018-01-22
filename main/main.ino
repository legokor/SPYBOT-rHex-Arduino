
#include <Servo.h>

//-------------------------------------------------------------- variables ----------------------------------------
int buttonPin = 0;
int buttonCompareValue = 1023/2; // values: 0-1023

// create servo variables for the motors
Servo motor1; // left  1
Servo motor2; // left  2
Servo motor3; // left  3
Servo motor4; // right 1
Servo motor5; // right 2
Servo motor6; // right 3

//-------------------------------------------------------------- setup --------------------------------------------
void setup() {
  // put your setup code here, to run once:

  // attach servos to pins
  attachServos();
  
  motorsStop();
  
  delay(3000);
  motorsFwd();
  delay(1000);
  motorsStop();

  delay(10000);
  motorsFwd();
  delay(10000);
  motorsStop();
  
}

//-------------------------------------------------------------- loop ----------------------------------------------
void loop() {
  // put your main code here, to run repeatedly:


  
}

//-------------------------------------------------------------- functions -----------------------------------------

// returns 1 if button analog value is higher tan compare value
int readBtn(){
  if (analogRead(buttonPin) > buttonCompareValue) {
    delay(100);
    if (analogRead(buttonPin) > buttonCompareValue) {
      return 1;
    }
  }
  return 0;
}

// stops all motors
void motorsStop() {
  motor1.write(91);   //stable stop
  motor2.write(115);  //stable stop
  motor3.write(91);   //stable stop
  motor4.write(92);   //stable stop
  motor5.write(91);   //stable stop
  motor6.write(93);   //stable stop
}

// rotate all motors forward
void motorsFwd(){
  motorsStop();
  delay(20);
  motor1.write(1);
  motor2.write(1);
  motor3.write(1);
  motor4.write(179);
  motor5.write(179);
  motor6.write(179);
}




// attaches servos to pins
void attachServos() {
  motor1.attach(2);
  motor2.attach(3);
  motor3.attach(4);
  motor4.attach(5);
  motor5.attach(6);
  motor6.attach(7);
}






