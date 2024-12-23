const int greenLEDPin = 9;     // Create constant for green LED pin
const int redLEDPin = 10;      // Create constant for red LED pin
const int blueLEDPin = 11;     // Create constant for blue LED pin

const int redSensorPin = A0;   // Create constant for red Sensor pin
const int greenSensorPin = A1; // Create constant for green Sensor pin
const int blueSensorPin = A2;  // Create constant for blue Sensor pin

int redValue = 0;              // Create variable for red LED pin value
int greenValue = 0;            // Create variable for green LED pin value
int blueValue = 0;             // Create variable for blue LED pin value

int redSensorValue = 0;        // Create variable for red Sensor pin value
int greenSensorValue = 0;      // Create variable for green Sensor pin value
int blueSensorValue = 0;       // Create variable for blue Sensor pin value

void setup() {
  Serial.begin(9600);           // Open a serial port for logging
  pinMode(greenLEDPin, OUTPUT); // Set green LED pin to OUTPUT
  pinMode(redLEDPin, OUTPUT);   // Set red LED pin to OUTPUT
  pinMode(blueLEDPin, OUTPUT);  // SET blue LED pin to OUTPUT
};

void loop() {
  redSensorValue = analogRead(redSensorPin);      // Read current red Sensor pin analog value
  delay(5);                                       // Wait 5 milliseconds because the ADC takes a millisecond to work
  greenSensorValue = analogRead(greenSensorPin);  // Read current green Sensor pin analog value
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);    // Read current blue Sensor pin analog value

  Serial.print("Raw sensor values:\tRed: ");      // Print Raw Sensor values
  Serial.print(redSensorValue);
  Serial.print("\tGreen: ");
  Serial.print(greenSensorValue);
  Serial.print("\tBlue: ");
  Serial.println(blueSensorValue);

  redValue = redSensorValue / 4;                  // Convert sensor values to analogWrite digestable values
  greenValue = greenSensorValue / 4;              // Because the current value is in a range of 0-1024 and
  blueValue = blueSensorValue / 4;                // analogWrite only accepts a range of 0-255

  Serial.print("Mapped sensor values:\tRed: ");   // Print Mapped Sensor values
  Serial.print(redValue);
  Serial.print("\tGreen: ");
  Serial.print(greenValue);
  Serial.print("\tBlue: ");
  Serial.println(blueValue);

  analogWrite(redLEDPin, redValue);               // Write redValue to redLEDPin
  analogWrite(greenLEDPin, greenValue);           // Write greenValue to greenLEDPin
  analogWrite(blueLEDPin, blueValue);             // Write blueValue to blueLEDPin
};