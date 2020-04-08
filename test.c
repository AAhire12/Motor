/**********************************************************************
* Filename    : Motor.c
* Description : Controlling a motor with pulse width modulation 
* Author      : Ankush Ahire 
* E-mail      : aahire@mail.sfsu.edu
Student ID: 920107107
**********************************************************************/

#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define Motor4Pin1		13
#define Motor4Pin2		14
#define Motor4Enable	12
#define Motor3Pin1		2
#define Motor3Pin2		3
#define Motor3Enable	26
#define Motor2Pin1		4
#define Motor2Pin2		5
#define Motor2Enable	6
#define Motor1Pin1		2
#define Motor1Pin2		3
#define Motor1Enable	0

void startAndStopPulse();


int main(void){
	int i;
	if(wiringPiSetup() == -1){ //when initialize wiring failed, print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	//Initializing Pins  
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
	
	softPwmCreate(Motor1Enable,1,100);
	softPwmCreate(Motor2Enable,1,100);
	softPwmCreate(Motor3Enable,1,100);
	softPwmCreate(Motor4Enable,1,100);


	//Intensity of motors for pusle width modulation
	int intensity;


	while(1){
		printf("Clockwise\n");
		
		//Setting direction of wheels
		digitalWrite(Motor1Pin1, HIGH);
		digitalWrite(Motor1Pin2, LOW);
		digitalWrite(Motor2Pin1, HIGH);
		digitalWrite(Motor2Pin2, LOW);
		digitalWrite(Motor3Pin1, HIGH);
		digitalWrite(Motor3Pin2, LOW);
		digitalWrite(Motor4Pin1, HIGH);
		digitalWrite(Motor4Pin2, LOW);

		startAndStopPulse();
		
	

		printf("Anti-clockwise\n");
	//Setting direction of wheels
		digitalWrite(Motor1Pin1, LOW);
		digitalWrite(Motor1Pin2, HIGH);
		digitalWrite(Motor2Pin1, LOW);
		digitalWrite(Motor2Pin2, HIGH);
		digitalWrite(Motor3Pin1, LOW);
		digitalWrite(Motor3Pin2, HIGH);
		digitalWrite(Motor4Pin1, LOW);
		digitalWrite(Motor4Pin2, HIGH);

		startAndStopPulse();


	}
	return 0;
}


void startAndStopPulse(){

for (intensity = 0; intensity < 101; intensity++)
		{
		  softPwmWrite (Motor1Enable, intensity);
		  softPwmWrite (Motor2Enable, intensity);
		  softPwmWrite (Motor3Enable, intensity);
		  softPwmWrite (Motor4Enable, intensity);
		  delay (10) ;
		}


		
		delay(3000);
		
		//Slow the motors down to a stop
		for (intensity = 100; intensity >= 0; intensity--)
		{
		  softPwmWrite (Motor1Enable, intensity);
		  softPwmWrite (Motor2Enable, intensity);
		  softPwmWrite (Motor3Enable, intensity);
		  softPwmWrite (Motor4Enable, intensity);
		  delay (10);
		}
		delay(3000);

}