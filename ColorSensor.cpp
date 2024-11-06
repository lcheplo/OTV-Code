//Define Color Sensor Pins
int S0 = A0;
int S1 = A1;
int S2 = A2;
int S3 = A3;
int out = A4;

// Variables for Color Pulse Width Measurements
int frequency = 0;

int redPW = 0;
int greenPW = 0;
int bluePW = 0;

void setup ()  {

  Serial.begin(9600);

  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  //Set Sensor output as input
  pinMode(S0, INPUT);

  //Set Pulse width scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

}

// Function to read Red Pulse Widths
int getRedPW() {
  //Set Sensor to read Red only
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // Define integer to represent Pulse Width
  frequency = pulseIn(out, LOW);
  return frequency;

}
// Function to read Green Pulse Widths (green)
int getGreenPW() {
  // Set Sensor to read Yellow only
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  //Define integer to represent Pulse Width
  frequency = pulseIn(out, LOW);
  return frequency;

}
//Function to read Blue Pulse Widths
int getBluePW() {
  //Set sensor to read Blue only
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(out, LOW);
  return frequency;
}

void loop() {
  //Read Red Pulse Width
  redPW = getRedPW();

  //Delay to stabilize sensor
  delay(100);

  //Read Yellow Pulse Width
  greenPW = getGreenPW();

  //Delay to stabilize sensor
  delay (100);

  //Read Blue Pulse Width
  bluePW = getBluePW();

  //Delay to stabilize sensor
  delay (100);

  //Attempt to determine pollutant colors
  if (bluePW < redPW && bluePW < greenPW) {
    Serial.println("Blue");
  }

  else if (redPW < bluePW && redPW < greenPW) {

    if (redPW < bluePW && greenPW < bluePW) {
      Serial.println("Yellow/Green");
    }

    else if (redPW < greenPW && bluePW < greenPW && redPW > 60) {
      Serial.println("Purple");
    }

    else {
      Serial.println("Red");
    }
  }


  //write individual RGB values to Serial monitor
  /*
    Serial.print("Red PW = ");
    Serial.print(redPW, DEC);
    Serial.print("- Green PW = ");
    Serial.print(greenPW, DEC);
    Serial.print("- Blue PW = ");
    Serial.println(bluePW, DEC);
  */

}
