/*
  File:    godzilla_api.h
  Purpose: This file provides implementations for the basic functions
           of Godzilla.
*/

#define WHEEL_DIAMETER 4.32 // Mesuared in centimeter.
#define CAR_RADIUS 7.5      // Mesuared in centimeter.
#define WHEEL_RADIUS 2.16   // Mesuared in centimeter.

#define LOW_POWER 25
#define MEDIUM_POWER 50
#define HIGH_POWER 75
#define MAXIMUM_POWER 100

#define MOTOR_LEFT OUT_A
#define MOTOR_RIGHT OUT_B
#define MOTOR_ARM OUT_B
#define BOTH_MOTORS OUT_AC

mutex moveMutex;

const int COMPLETE_TURN = 360; // Measured in degrees.
const int HALF_TURN = 180;     // Measured in degrees.

const bool SYNCHRONIZED = true;
const bool DESYNCHRONIZED = false;

const bool STOP = true;
const bool NOT_STOP = false;

/* TODO: Comment for documentation to this function. */
sub move_forward( int distance ) {
    float quantity_rounds =
          ( COMPLETE_TURN * distance )/ ( PI * WHEEL_DIAMETER );
    
    RotateMotor( BOTH_MOTORS, HIGH_POWER, quantity_rounds );
}

/* TODO: Comment for documentation to this function. */
sub move_back( int distance ) {
    float quantities_turns_wheel =
          ( COMPLETE_TURN * distance * ( -1 ) )/ ( PI * WHEEL_DIAMETER );

    RotateMotor( BOTH_MOTORS, HIGH_POWER, quantities_turns_wheel );
}

/* TODO: Comment for documentation to this function. */
sub turn_right( int angle ) {
    int lc = ( angle * PI * CAR_RADIUS )/ HALF_TURN; // Measured in centimeter.
    int degree2 = ( HALF_TURN * lc )/ ( PI * WHEEL_RADIUS );

    RotateMotorEx( BOTH_MOTORS, HIGH_POWER, degree2, 100, SYNCHRONIZED, NOT_STOP );
}

/* TODO: Comment for documentation to this function. */
sub turn_left( int angle ) {
    int  lc = ( angle * PI * CAR_RADIUS )/ HALF_TURN; // Measured in centimeter.
    int degree2 = ( HALF_TURN * lc )/ ( PI * WHEEL_RADIUS );

    RotateMotorEx( BOTH_MOTORS, HIGH_POWER, degree2, -100, SYNCHRONIZED, NOT_STOP );
}

/* TODO: Comment for documentation to this function. */
task rotate_wheel_right() {
     Acquire( moveMutex );
     RotateMotor( MOTOR_RIGHT, HIGH_POWER, 550 );

     Release( moveMutex );
}

/* TODO: Comment for documentation to this function. */
task rotate_wheel_left() {
     Acquire( moveMutex );
     RotateMotor( MOTOR_LEFT, HIGH_POWER, -550 );

     Release( moveMutex );
}

