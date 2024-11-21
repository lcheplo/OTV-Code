#include <Enes100.h>

// Defines Ultrasonic pins
int trig1=32;
int echo1=34;

//Defines Ultrasonic Variables 
long timeInMicro1;
long distanceInCm1;


void setup() {

    Serial.begin(9600);
    //Declares Ultrasonic pins as Input/Output
    pinMode(11, OUTPUT);
    pinMode(10, INPUT);
    
    Serial.println("Start of program");
}

void loop() {


    //Code to trigger the trigger pin 11
    digitalWrite(trig1,LOW);
    delayMicroseconds(2);
    digitalWrite(trig1,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig1,LOW);

    //Echo code to get inputs
    timeInMicro1= pulseIn(echo1,HIGH);
    //timeInMicro2= pulseIn(echo2,HIGH);

    //Speed of Sound programming
    distanceInCm1= timeInMicro1 * .034 / 2;
    //distanceInCm2= timeInMicro2/ 29 /2;

    Serial.println(distanceInCm1);
    //Serial.println(distanceInCm2);
    delay(100);


}
