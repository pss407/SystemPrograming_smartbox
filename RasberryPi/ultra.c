#include <wiringPi.h>
#include <stdio.h>

#define HCIN  1
#define HCOUT 0

int main(void){

    float dist,s,e;

    if(wiringPiSetup()==-1)
        return 0;

    pinMode(HCIN, INPUT);
    pinMode(HCOUT, OUTPUT);
    
    while(1){
        digitalWrite(HCOUT, LOW);
        digitalWrite(HCOUT, HIGH);
        delayMicroseconds(10);
        digitalWrite(HCOUT, LOW);

        while(digitalRead(HCIN)==LOW)
            s=micros();
        while(digitalRead(HCIN)==HIGH)
            e=micros();
        dist = (e-s)/58;
        //printf("distance %f\n",dist);

        if(dist<=5.0){
            printf("5cm내 물체감지\n");
            delay(1000);
            }
        delay(1000);
    }
    return 0;
}
