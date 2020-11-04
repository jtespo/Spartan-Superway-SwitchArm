/*  Servo and Stepper test code
 *   Version: 1 
 *   Written by: Jake Espinoza
 *   October 30, 2020
 *   
 *  This code is just for testing the motors and boards   
 *  
 *  if using Arduino IDE, install ESP32 board libraries following this guide:
 *  https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/  
 */

#include <Servo.h>
#include <Stepper.h>

// SETUP FOR SERVO
Servo servo;

#define SERVO_PIN 6 // change as needed 

// FOR STANDARD SERVO (180 deg sweep)
#define SERVO_NEUTRAL 90
#define SERVO_LEFT 60
#define SERVO_RIGHT 120

/*// SETUP FOR STEPPER (delete block comment here and line 34)
// UNCOMMENT THE CORRECT NUMBER OF STEPS FOR CHOSEN MOTOR
#define STEPS 200 // 1.8 deg steps (200 step/rev)
//#define STEPS 400 // 0.9 deg steps (400 step/rev)

Stepper stepper(STEPS, 2, 3, 4, 5); // change numbers to pins the stepper is connected to

#define STEPPER_ANGLE 30 // degrees either way
*/

void setup() {
  
  servo.attach(SERVO_PIN);
//  stepper.setSpeed(120); // speed in RPM

  delay(1000);

  servo.write(SERVO_NEUTRAL); // sends servo to 90 deg position

}

void loop() {
  delay(1000);
  
  // SERVO section. Just moves between 2 positions back and forth
  servo.write(SERVO_LEFT);
  delay(1000);
  servo.write(SERVO_RIGHT);


  // STEPPER. Same as above
//  stepper.step(STEPPER_ANGLE / (360/STEPS));
//  delay(1000);
//  stepper.step(-2 * (STEPPER_ANGLE/(360/STEPS)));
  
}
