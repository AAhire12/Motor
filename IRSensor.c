#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <ctype.h>

#define IR_SENSOR	15
#define PI 3.1415926535

int main(int argc, char const *argv[])
{   
    if(wiringPiSetup() == -1){ //when initialize wiring failed, print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}


    struct timespec startTime;
    struct timespec endTime;
    clock_gettime(CLOCK_REALTIME, &startTime);

    //Number of pulses
    long n=0;

    //pulses per revolution
    int N=20;



    pinMode(IR_SENSOR,INPUT);
    int count=0;
    while(count<5000){
        // printf("This is the input from the IR Sensor %d\n",digitalRead(IR_SENSOR));
        if(digitalRead(IR_SENSOR)==1){
            n++;
        }
    count++;
    }

    /**
     * Calculates the time taken to execute the program. Should be
     * */
    clock_gettime(CLOCK_REALTIME, &endTime);
    time_t sec = endTime.tv_sec - startTime.tv_sec;
    long n_sec = endTime.tv_nsec - startTime.tv_nsec;

    if (endTime.tv_nsec < startTime.tv_nsec)
        {
        --sec;
        n_sec = n_sec + 1000000000L;
        }

    printf("Total Time was %ld.%09ld seconds\n", sec, n_sec);

    
    long angularSpeed= (2* PI * n )/(N * sec);


    printf("The angular speed is %lu\n",angularSpeed);


    return 0;
}
