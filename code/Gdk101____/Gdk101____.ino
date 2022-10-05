#include <C305_Steam_Air_GDK101_GAMMA.h>

SteamGDK101 gdk101;

void setup(){
  Serial.begin(115200);
  gdk101.begin();
}

void loop(){
  gdk101.read();
  gdk101.display();
  delay(2000);
}
