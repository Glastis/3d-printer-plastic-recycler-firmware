#include <ESP8266WiFi.h>

// Current time

void setup()
{
    Serial.begin(115200);
    // Print local IP address and start web server
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    server.begin();
}

void loop()
{
    handle_client();
}