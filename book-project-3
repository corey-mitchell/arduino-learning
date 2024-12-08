const int sensorPin = A0;  // Create sensorPin constant 
float baseTemp = 20.0;     // Create baseTemp variable

void setup() {
  Serial.begin(9600);                                 // Open a serial port for logging
  int firstRead = analogRead(sensorPin);              // Check initial sensor value
  float firstReadVolts = (firstRead / 1024.0) * 5.0;  // Get initial voltage from initial value
  baseTemp = (firstReadVolts - .5) * 100;             // Set the baseTemp to the current room temperature

  for (int pin = 2; pin < 5; pin++) {                 // Set pins 2 - 4 to OUTPUT with a value of LOW (off)
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  };
}

void loop() {
  int sensorVal = analogRead(sensorPin);        // Check value of sensor
  Serial.print(sensorVal);                      // Print sensor value
  float voltage =  (sensorVal / 1024.0) * 5.0;  // Get sensor voltage
  Serial.print(", Voltage: ");                  // Print sensor voltage
  Serial.print(voltage);
  float temperature = (voltage - .5) * 100;     // Get temperature from voltage
  Serial.print(", Degrees (C): ");
  Serial.println(temperature);                  // Print temperature


  if(temperature >= baseTemp + 2.0) {           // If temperature is more than 2 degrees above base line
    digitalWrite(2, HIGH);                      // Turn on first light
  } else {                                      // Else
    digitalWrite(2, LOW);                       // Turn off first light
  };
  
  if (temperature >= baseTemp + 4.0) {          // If temperature is more than 4 degrees above base line
    digitalWrite(3, HIGH);                      // Turn on second light
  } else {                                      // Else
    digitalWrite(3, LOW);                       // Turn off second light
  };
  
  if (temperature >= baseTemp + 6.0) {          // If temperature is more than 6 degrees above base line
    digitalWrite(4, HIGH);                      // Turn on third light
  } else {                                      // Else
    digitalWrite(4, LOW);                       // Turn off third light
  };

  delay(1);
}
