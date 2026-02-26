#include "Config.h"
#include "WIFI.h"
#include "Server.h"
#include "MQTT.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  init_WIFI(WIFI_START_MODE_CLIENT);
  init_server();
  init_MQTT();
  mqtt_cli.subscribe("esp8266/command");
}

void loop() {
  // put your main code here, to run repeatedly:

  server.handleClient();
  mqtt_cli.loop();
  // delay(500);
  // Serial.print("our id is: ");
  // Serial.println(id());
}
