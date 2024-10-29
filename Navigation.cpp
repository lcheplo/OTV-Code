//This code works with standard wheels

// Motor Driver 1 (Front Left and Rear Left Motors)
const int ENA = 9;  // PWM speed control for Left Motors
const int IN1 = 2;  // Front Left Motor Forward
const int IN2 = 3;  // Front Left Motor Backward
const int IN3 = 4;  // Rear Left Motor Forward
const int IN4 = 5;  // Rear Left Motor Backward

// Motor Driver 2 (Front Right and Rear Right Motors)
const int ENB = 10; // PWM speed control for Right Motors
const int IN5 = 6;  // Front Right Motor Forward
const int IN6 = 7;  // Front Right Motor Backward
const int IN7 = 8;  // Rear Right Motor Forward
const int IN8 = 11; // Rear Right Motor Backward

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
  digitalWrite(IN1, HIGH);  // Front Left Motor Forward
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);  // Rear Left Motor Forward
  digitalWrite(IN4, LOW);
  
  digitalWrite(IN5, HIGH);  // Front Right Motor Forward
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);  // Rear Right Motor Forward
  digitalWrite(IN8, LOW);
  
  // Set motor speed
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}
