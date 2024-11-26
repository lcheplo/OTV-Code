//This code works with standard wheels

// Motor Driver 1 (back motors)
const int ENA = 9;  // PWM speed control for back Motors
const int IN1 = 2;  // Back Right Motor Forward
const int IN2 = 3;  // Back Right Motor Backward
const int IN3 = 4;  // Rear Left Motor Forward
const int IN4 = 5;  // Rear Left Motor Backward

// Motor Driver 2 (front motors)
const int ENB = 10; // PWM speed control for front Motors
const int IN5 = 6;  // Front left Motor Forward
const int IN6 = 7;  // Front Right Motor Backward
const int IN7 = 8;  // front Right Motor Forward
const int IN8 = 11; // front Right Motor Backward

// Set speed
const int motorSpeed = 100;

void setup() {
  // Set motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(ENB, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

}

void loop() {
  moveForward(); //move forward indefinitely
}

void moveForward() {
  // Enable the motors with forward direction
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      
      digitalWrite(IN5, HIGH);
      digitalWrite(IN6, LOW);
      digitalWrite(IN8, LOW);
      digitalWrite(IN7, HIGH);
  
  // Set motor speed
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}
