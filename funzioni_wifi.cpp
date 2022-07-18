#include "Funzioni.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>


void init_wifi(const char* ssid, const char* password, int baudrate) {
  Serial.begin(baudrate); //default baud rate for esp12e
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); // establish connection with mentioned Host
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  // Print out the Local IP assigned by the router to ESP8266
}

String https_request(String url, char* host, int httpsPort, char* fingerprint, WiFiClientSecure client) {

  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) { // establishing connection with the server(api.github.com) at port 443
    Serial.println("connection failed");

  }

  if (client.verify(fingerprint, host)) { // verfying fingerprint with the server
    Serial.println("certificate matches");
  } else {
    Serial.println("certificate doesn't match");
  }

  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  while (client.connected()) { // until the client is connected, read out the response
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }

    return String(client.readString());

  }

  String https_request_ins(String url, char* host, int httpsPort, WiFiClientSecure client) {
    client.setInsecure();
    Serial.print("connecting to ");
    Serial.println(host);
    if (!client.connect(host, httpsPort)) {
      Serial.println("connection failed");

    }



    Serial.print("requesting URL: ");
    Serial.println(url);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "User-Agent: BuildFailureDetectorESP8266\r\n" +
                 "Connection: close\r\n\r\n");

    while (client.connected()) { // until the client is connected, read out the response
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        Serial.println("headers received");
        break;
      }
    }

    return String(client.readString());

  }
