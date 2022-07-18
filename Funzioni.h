#ifndef funzioni_h
#define funzioni_h
#include <WiFiClientSecure.h>

/* funzioni wifi */
void init_wifi(const char* ssid, const char* password, int baudrate); // connette l'esp al wifi + debug
String https_request(String url, char* host, int httpsPort, char* fingerprint, WiFiClientSecure client); // richiesta https sicura con verifica del certificato
String https_request_ins(String url, char* host, int httpsPort, WiFiClientSecure client);
/* funzioni ethereum */
#endif funzioni_h
