
/*
    HTTP over TLS (HTTPS) example sketch

    This example demonstrates how to use
    WiFiClientSecure class to access HTTPS API.
    We fetch and display the status of
    esp8266/Arduino project continuous integration
    build.

    Created by Ivan Grokhotkov, 2015.
    This example is in public domain.

  .  Code explained and commented by Sachin Soni

     For tutorial of this code, watch out this video
     https://youtu.be/dsmMzS3Qvg0

    visit
    http://www.techiesms.com
    for IoT project tutorials.

          #techiesms
    explore | learn | share
*/

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include "Secrets.h"
#include "Funzioni.h"

const char* ssid = SSID; // Name of the Host
const char* password = PASSWORD; // Password of the corresponding Host

String url = "";
char* host = "";
const int httpsPort = 443;

WiFiClientSecure client;

void setup() {
  init_wifi(ssid, password, 9600);
}

void loop() {

}
