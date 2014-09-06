/*
  File:    godzilla_api.h
  Purpose: This file provides implementations for the basic functions
           of Godzilla.
*/

#define LOW_POWER 25
#define MEDIUM_POWER 50
#define HIGH_POWER 75
#define MAX_POWER 100

#define FORWARD 1
#define BACKWARD -1

#define TURN_LEFT 1
#define TURN_RIGHT -1

const float CAR_RADIUS = 7.50;       // Measured in centimeter
const float WHEEL_RADIUS = 2.16;
const float WHEEL_DIAMETER = 4.32;   // Measured in centimeter

const int COMPLETE_TURN = 360;      // Measured in degrees.
const int HALF_TURN = 180;          // Measured in degrees.

const int BOTH_MOTORS = OUT_AC;
const int MOTOR_RIGHT = OUT_A;
const int MOTOR_LEFT = OUT_C;
const int MOTOR_ARM = OUT_B;

const bool SYNCHRONIZED = true;
const bool DESYNCHRONIZED = false;

const bool DO_STOP = true;
const bool NOT_STOP = false;

/* Moves car forward or backward */
sub move(const int distance,const int power,const int direction){
  float amount_turns = 
    ( COMPLETE_TURN * distance * direction )/ ( PI * WHEEL_DIAMETER );

  RotateMotor( BOTH_MOTORS, power, amount_turns );
}

/* TODO: Comment for documentation to this function. */
sub turn(const int angle,const int power,const int direction){
  int car_arc = ( angle * PI * CAR_RADIUS )/ HALF_TURN; // Measured in centimeter
  int amount_turns = 
    ( HALF_TURN * car_arc )/ ( PI * WHEEL_RADIUS ); // Measured in centimeter

  RotateMotorEx( BOTH_MOTORS, power, amount_turns, 100 * direction, SYNCHRONIZED, NOT_STOP );
}

