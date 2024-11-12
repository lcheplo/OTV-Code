#include "Arduino.h"
#include "Enes100.h"
#include "Tank.h"



void setup() {
    Enes100.begin("Simulator", Water, 3, 8, 9);
    Tank.begin();
   
    Enes100.println("Starting driving");
}

void loop() {
   
    while(Enes100.getTheta() <= 2.9){
        Tank.setLeftMotorPWM(-75);
        Tank.setRightMotorPWM(75);
    }
    Tank.setLeftMotorPWM(0);
    Tank.setRightMotorPWM(0);
   
    delay(2000);
   
   
   
    while(Enes100.getTheta() <= -1.75){
        Tank.setLeftMotorPWM(-75);
        Tank.setRightMotorPWM(75);
    }
   
    Tank.setLeftMotorPWM(0);
    Tank.setRightMotorPWM(0);
   
    delay(10000);
    Enes100.print("X = "); Enes100.println(Enes100.getX());
    Enes100.print("Y = "); Enes100.println(Enes100.getY());
    Enes100.print("Theta = "); Enes100.println(Enes100.getTheta());
}
