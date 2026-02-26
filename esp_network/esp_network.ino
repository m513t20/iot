#include "Config.h"
#include "WIFI.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  init_WIFI(WIFI_START_MODE_CLIENT);
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(500);
  Serial.print("our id is: ");
  Serial.println(id());
}
