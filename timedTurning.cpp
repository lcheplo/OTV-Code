#include "Enes100.h"

//This code works with standard AND mecanum wheels

// Motor Driver 1 (back motors)
const int ENA = 6; // PWM speed control for back Motors
const int ENC = 7;
const int IN1 = 5;  // Back Right Motor Forward
const int IN2 = 4;  // Back Right Motor Backward
const int IN3 = 3;  // Rear Left Motor Forward
const int IN4 = 2;  // Rear Left Motor Backward

// Motor Driver 2 (front motors)
const int ENB = 12; // PWM speed control for front Motors
const int END = 13; 
const int IN5 = 11;  // Front left Motor Forward
const int IN6 = 10;  // Front Right Motor Backward
const int IN7 = 9;  // front Right Motor Forward
const int IN8 = 8; // front Right Motor Backward

// Set speed
const int motorSpeed = 255;
const int stop = 0;

void setup() {

  // Enes100.begin("Miko Sharks", WATER, 402, 13, 12);
  //   Serial.begin(9600);
   
  //   Enes100.println("Starting driving");


  // Set motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(ENC, OUTPUT);
  pinMode(END, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

}

void loop() {


    //turns left
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      
      digitalWrite(IN5, LOW);
      digitalWrite(IN6, HIGH);
      digitalWrite(IN7, HIGH);
      digitalWrite(IN8, LOW);

      analogWrite(ENA, motorSpeed);
      analogWrite(ENB, motorSpeed);
      analogWrite(ENC, motorSpeed);
      analogWrite(END, motorSpeed);

      delay(1500);

      /*
      digitalWrite(IN2, HIGH);
      digitalWrite(IN1, LOW);
      digitalWrite(IN4, LOW);
      digitalWrite(IN3, HIGH);
      
      digitalWrite(IN6, LOW);
      digitalWrite(IN5, HIGH);
      digitalWrite(IN8, HIGH);
      digitalWrite(IN7, LOW);
      */

      digitalWrite(IN1, 0);
      digitalWrite(IN2, 0);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 0);
      
      digitalWrite(IN5, 0);
      digitalWrite(IN6, 0);
      digitalWrite(IN7, 0);
      digitalWrite(IN8, 0);

      analogWrite(ENA, stop);
      analogWrite(ENB, stop);
      analogWrite(ENC, stop);
      analogWrite(END, stop);

      delay(2000);

}

void turn() {
      //turns left indefinitely
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      
      digitalWrite(IN5, LOW);
      digitalWrite(IN6, HIGH);
      digitalWrite(IN7, HIGH);
      digitalWrite(IN8, LOW);
      
      // Set motor speed
      analogWrite(ENA, motorSpeed);
      analogWrite(ENB, motorSpeed);

      digitalWrite(IN1, 0);
      digitalWrite(IN2, 0);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 0);
      
      digitalWrite(IN5, 0);
      digitalWrite(IN6, 0);
      digitalWrite(IN7, 0);
      digitalWrite(IN8, 0);
  
}
