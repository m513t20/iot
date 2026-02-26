#include "Config.h"
#include "WIFI.h"
#include "Server.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  init_WIFI(WIFI_START_MODE_CLIENT);
  init_server();
}

void loop() {
  // put your main code here, to run repeatedly:

  server.handleClient();
  // delay(500);
  // Serial.print("our id is: ");
  // Serial.println(id());
}
