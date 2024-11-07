#include <Arduino.h>

const int pin = GPIO_NUM_36;
double airspeed;
const float offset = .90; // Voltage at zero pressure (CHECK ALL THESE)
const float scaleFactor = 1000; // Pressure per volt 
const float airDensity = 1.225; // Air density in kg/m^3 (standard at sea level)


void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

void loop() {
  double raw_voltage = analogRead(pin);
  double voltage = (raw_voltage / 4095.0) * 2.5;

  float pressure = (voltage - offset) * scaleFactor; // Differential pressure in Pa (Pascal)

  float airspeed = sqrt((2 * pressure) / airDensity); // Airspeed in m/s


  Serial.print("Voltage: ");
  Serial.println(voltage);
  Serial.print("Airspeed: ");
  Serial.print(airspeed);
  Serial.println(" m/s");
  delay(200);
}
