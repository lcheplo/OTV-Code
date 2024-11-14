#include "Arduino.h"
#include "Enes100.h"
#include "Tank.h"



void setup() {
    Enes100.begin("Simulator", WATER, 3, 8, 9);
    Tank.begin();
   
    Enes100.println("Starting driving");
   
    double absoluteRange = .03;
    double startY = Enes100.getY();
   
    //change orientation to face opposite side of arena
    if(startY == 1.45){
        while(Enes100.getTheta() > (-HALF_PI+absoluteRange) || Enes100.getTheta() < (-HALF_PI-absoluteRange)){
            Tank.setLeftMotorPWM(50);
            Tank.setRightMotorPWM(-50);
        }
    }
   
    //change orientation to face opposite side of arena
    else if (startY == .55){
        while(Enes100.getTheta() > (HALF_PI+absoluteRange) || Enes100.getTheta() < (HALF_PI-absoluteRange)){
            Tank.setLeftMotorPWM(50);
            Tank.setRightMotorPWM(-50);
        }
    }
   
    //navigate to 1.45 if starting at 0.55
    if(startY == 0.55){
        while(Enes100.getY() < 1.4){
            Tank.setLeftMotorPWM(100);
            Tank.setRightMotorPWM(100);
        }
    }
   
    //navigate to opposite end of arena if starting at 1.45
    else if(startY == 1.45){
        while(Enes100.getY() > .5){
            Tank.setLeftMotorPWM(100);
            Tank.setRightMotorPWM(100);
        }
    }
   
   /*
    //turn to 0 deg after completing mission to start loop section
    while(Enes100.getTheta() > 0-absoluteRange || Enes100.getTheta() < 0+absoluteRange){
        Tank.setLeftMotorPWM(50);
        Tank.setRightMotorPWM(-50);
    }
    */
   
    Tank.setLeftMotorPWM(0);
    Tank.setRightMotorPWM(0);
    delay(3000);
   
}

void loop() {
   
    delay(1000);
    Enes100.print("X = "); Enes100.println(Enes100.getX());
    Enes100.print("Y = "); Enes100.println(Enes100.getY());
    Enes100.print("Theta = "); Enes100.println(Enes100.getTheta());
}
