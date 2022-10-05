#include "HX711.h"
HX711 scale;
float calibration_factor = -52000;
void setup() {
Serial.begin(9600);
scale.begin(2,3); //dt 2 sck3
scale.set_scale();
scale.tare(); //Reset the scale to 0
}
void loop() {
scale.set_scale(calibration_factor);
Serial.print(scale.get_units());
Serial.println(" kg");
delay(500);
}
