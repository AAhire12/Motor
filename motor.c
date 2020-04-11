/*************************************************************** 
 * Class:  CSC-615-01 Spring2020
 * Name: Ibraheem Chaudry
 * Student ID: 917227459 
 * Project:Assignment 3 - Motors & Motor Shield 
 * File: motor.c
 * Description: Motor control functions for raspberryPi motorshield model
 ****************************************************************/

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <softPwm.h>

#define Motor1Pin1		2 //13
#define Motor1Pin2		3 //15
#define Motor1Enable	0

#define Motor2Pin1		4 //18  
#define Motor2Pin2		5 //16  
#define Motor2Enable	6 //22

#define Motor3Pin1		14  //23
#define Motor3Pin2		13 //21
#define Motor3Enable	12 //19

#define Motor4Pin1		10 //26
#define Motor4Pin2		11 //24
#define Motor4Enable	26 //32

#define MaxSpeed        25
#define MinSpeed        0

//Initialize Motor Pins
void initMotors();

//To reset pins on program exit
void resetPins();

//Inialize individual motors to move forward
void initMotor1F();
void initMotor2F();
void initMotor3F();
void initMotor4F();

//Inialize individual motors to move backward
void initMotor1B();
void initMotor2B();
void initMotor3B();
void initMotor4B();

//Initalize all motors to move forward
void initMotorsF();

//Initalize all motors to move backward
void initMotorsB();

void accelerate();
void brake();
void moveForward();
void moveBackward ();
void turnRight();
void turnLeft();
void stop();

//interrupt handler
void interruptHandler(){
    printf("The interrupt handler was called. Its time to cleanup.\n");
    printf("Slowing down the motors...\n");
    brake();

    printf("Resetting the pins to input\n");
    resetPins();

    printf("Pins cleaned..Making a clean exit!");
    exit(0);
}

int main(void){
    signal(SIGINT,interruptHandler);

	int i;
	if(wiringPiSetup() == -1){ //when initialize wiring failed, print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}

    initMotors();
	
    //Settings for pulse width modulation
    softPwmCreate(Motor1Enable,MinSpeed,MaxSpeed);	
	softPwmCreate(Motor2Enable,MinSpeed,MaxSpeed);
	softPwmCreate(Motor3Enable,MinSpeed,MaxSpeed);
	softPwmCreate(Motor4Enable,MinSpeed,MaxSpeed);

    //Loop for function calls on motor
    
    // initMotorsB();
    moveBackward();

	while(1){ 

	}
	return 0;
}

void initMotors(){
    //Initializing all motor to output  
	pinMode(Motor1Pin1, OUTPUT);
	pinMode(Motor1Pin2, OUTPUT);
	pinMode(Motor1Enable, OUTPUT);

	pinMode(Motor2Pin1, OUTPUT);
	pinMode(Motor2Pin2, OUTPUT);
	pinMode(Motor2Enable, OUTPUT);
	
	pinMode(Motor3Pin1, OUTPUT);
	pinMode(Motor3Pin2, OUTPUT);
	pinMode(Motor3Enable, OUTPUT);
	
	pinMode(Motor4Pin1, OUTPUT);
	pinMode(Motor4Pin2, OUTPUT);
	pinMode(Motor4Enable, OUTPUT);
}

void resetPins(){
    //Reset pins to input 
	pinMode(Motor1Pin1, INPUT);
	pinMode(Motor1Pin2, INPUT);
	pinMode(Motor1Enable, INPUT);

	pinMode(Motor2Pin1, INPUT);
	pinMode(Motor2Pin2, INPUT);
	pinMode(Motor2Enable, INPUT);
	
	pinMode(Motor3Pin1, INPUT);
	pinMode(Motor3Pin2, INPUT);
	pinMode(Motor3Enable, INPUT);
	
	pinMode(Motor4Pin1, INPUT);
	pinMode(Motor4Pin2, INPUT);
	pinMode(Motor4Enable, INPUT);
}

/**
 *Initialize motor pins to set DC motors to move car forwards 
 */
void initMotorsF(){
   initMotor1F();
   initMotor2F();
   initMotor3F();
   initMotor4F();
}

/**
 *Initialize motor pins to set DC motors to move car backwards 
 */
void initMotorsB(){
    initMotor1B();
    initMotor2B();
    initMotor3B();
    initMotor4B();
}

/**
 * Accelerate gradually to maximum speed
 */
void accelerate(){
    //Intensity of motors for accelerating 
    //This is done using pulse width modulation 
	int intensity;

    //Slowly accelerate the motors
    for (intensity = MinSpeed; intensity < MaxSpeed; intensity++)
		{
		  softPwmWrite (Motor1Enable, intensity);
		  softPwmWrite (Motor2Enable, intensity);
		  softPwmWrite (Motor3Enable, intensity);
		  softPwmWrite (Motor4Enable, intensity);
		  delay (50) ;
		}
}

/**
 * Deccelerate gradually to minimum speed
 */
void brake(){
    //Intensity of motors from which to start braking from
    //This is done using pulse width modulation
    int intensity;

    //Slow the motors down to a stop
    for (intensity = MaxSpeed; intensity >= MinSpeed; intensity--)
		{
		  softPwmWrite (Motor1Enable, intensity);
		  softPwmWrite (Motor2Enable, intensity);
		  softPwmWrite (Motor3Enable, intensity);
		  softPwmWrite (Motor4Enable, intensity);
		  delay (50);
		}

}

void stop(){
    //TO DO if needed
}

void moveForward(){
    printf("Clockwise\n");
   
    //Initiliaze motors to move forwards
    initMotorsF();

    //Accelerate
    accelerate();
}

void moveBackward(){
    printf("Anti-clockwise\n");

    //Initiliaze motors to move backwards
    initMotorsB();

    //Accelerate
    accelerate();
}

void turnRight(){
    //TODO
}

void turnLeft(){
    //TODO
}

/**
 * Functions to initialize each separate motor to run in the forward direction
 */
void initMotor1F(){
    digitalWrite(Motor1Pin1, HIGH);
    digitalWrite(Motor1Pin2, LOW);  
}

void initMotor2F(){
    digitalWrite(Motor2Pin1, HIGH);
    digitalWrite(Motor2Pin2, LOW);
}
void initMotor3F(){
    digitalWrite(Motor3Pin1, HIGH);
    digitalWrite(Motor3Pin2, LOW);
}

void initMotor4F(){
    digitalWrite(Motor4Pin1, HIGH);
    digitalWrite(Motor4Pin2, LOW);
}


/**
 * Functions to initialize each separate motor to run in the backwards direction
 */
void initMotor1B(){
    digitalWrite(Motor1Pin1, LOW);
    digitalWrite(Motor1Pin2, HIGH);    
}

void initMotor2B(){
    digitalWrite(Motor2Pin1, LOW);
    digitalWrite(Motor2Pin2, HIGH);
}

void initMotor3B(){
    digitalWrite(Motor3Pin1, LOW);
    digitalWrite(Motor3Pin2, HIGH);
}

void initMotor4B(){
    digitalWrite(Motor4Pin1, LOW);
    digitalWrite(Motor4Pin2, HIGH);
}

