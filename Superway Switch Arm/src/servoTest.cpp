/*  Servo test w/button interupts
 *   Version: 1 
 *   Written by: Jake Espinoza
 *   November 4, 2020
 *   
 *  This code uses a button to control when the servo moves
 *  
 *  Written in VSCode with PlatformIO extension
 * 
 *  if using Arduino IDE, install ESP32 board libraries following this guide:
 *  https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/  
 */

#include <Arduino.h> // probably don't need this for arduino ide
#include <Servo.h>
#include <Stepper.h>

// SETUP FOR SERVO
Servo servo;

#define SERVO_PIN 6  // change as needed 
#define BUTTON_PIN 3 // change as needed 

// FOR STANDARD SERVO (180 deg sweep)
#define SERVO_LEFT 60
#define SERVO_RIGHT 120

bool position = 0; // 0 left, 1 right


void setup() {
  
  servo.attach(SERVO_PIN);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), move, FALLING);

  delay(250);
  servo.write(SERVO_LEFT); // sends servo to 60 deg
  delay(250);
  wiggle(5); // wiggles to show that setup is complete

}

void loop() {
  delay(100);
}

void wiggle(byte wiggleAngle){
  byte currentPos = servo.read();
  byte leftPos = currentPos + wiggleAngle;
  byte rightPos = currentPos - wiggleAngle;

  for(int i = 0; i <= 5; i++)
  {
    servo.write(leftPos);
    delay(100);
    servo.write(rightPos);
    delay(100);
  }
  servo.write(currentPos);
}

void move(){
  if(position)
  {
    servo.write(SERVO_RIGHT);
    position = 1;
  }
  else
  {
    servo.write(SERVO_LEFT);
    position = 0;
  }
  
}