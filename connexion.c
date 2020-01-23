/*
** Created by glastis
** Date: 13-Jan-20
** Contact: developers@glastis.com
*/

#include <ESP8266WiFi.h>
#include "connexion.h"

WiFiServer server(SERVER_PORT);

int                 wait_connection(unsigned int timeout)
{
    unsigned int    i;

    i = 0;
    while ((timeout == 0 || i < timeout) && WiFi.status() != WL_CONNECTED)
    {
        ++i;
        delay(1000);
    }
}

void                init_connection()
{
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    wait_connection(0);
}