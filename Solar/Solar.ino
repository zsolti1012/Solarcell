/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include "Solarplant.h";

/*
int pos = 0;    // variable to store the servo position

int leftport=A6;
int rightport=A7;
int upport=A5;
int downport=A4;
leftright.attach(9);
  updown.attach(10);//
*/

Solarplant plant1(9,10,
                   A6,A7,A5,A4);


Solarplant plant2(6,5,
                  A2,A3,A0,A1);




void setup() {

  plant1.Enable();
  plant1.StartPosition();
  plant2.Enable();
  plant2.StartPosition();
  

  
}

void loop() {
  
plant1.Move();

plant2.Move();

  
}
