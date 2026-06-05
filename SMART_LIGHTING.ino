// SMART LIGHTING USING LDR

/*A Smart Lighting System is an automated lighting solution 
that controls a light source based on the surrounding light intensity.
This project uses a Light Dependent Resistor (LDR) and an Arduino UNO
to automatically switch an LED ON during low-light conditions and 
OFF when sufficient light is available.*/

//Author - P.shanmukha Chaitanya

const int ldrPin = A0;  // LDR sensor connected to Analog pin A0
const int ledPin = 13;  // LED or Relay connected to Digital pin 13
int threshold = 500;    // Light threshold (adjust based on your environment)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600); // Start serial monitor to read LDR values
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Read the ADC value from ldr (0 to 1023)
  Serial.println(ldrValue);          // Print value to Serial Monitor

  // If it is dark (sensor value drops below threshold)
  if (ldrValue < threshold) {
    digitalWrite(ledPin, HIGH); // Turn the light ON
  } 
  // If it is bright 
  else {
    digitalWrite(ledPin, LOW);  // Turn the light OFF
  }

  delay(500); // delay for 500 milli seconds for better accuracy.
  
}
