#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define IR_SENSOR	15

int main(int argc, char const *argv[])
{   
    pinMode(IR_SENSOR,INPUT);

    while(1){

        printf("This is the input from the IR Sensor %d",digitalRead(IR_SENSOR));

    }


    return 0;
}
