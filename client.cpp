/*
** Created by glastis
** Date: 14-Jan-20
** Contact: developers@glastis.com
*/

#include <ESP8266WiFi.h>
#include <cstdlib>
#import "temperature.h"
#include "client.h"

static void                         send_main_page(WiFiClient &client);
static void                         send_temp(WiFiClient &client);

const t_route route_list[] =        {
                                    { (char *) "/", &send_main_page }
                                    { (char *) "/temperature/get", &send_temp }
                                    { (char *) "/temperature/set", &set_temp }
                                    { (char *) "/motor1/set", &set_temp }
                                    { (char *) "/motor1/get", &set_temp }
                                    { nullptr, nullptr }
                                    };


String                              header;
unsigned long                       currentTime = millis();
unsigned long                       previousTime = 0;
const long                          timeoutTime = 2000;

static void                         send_header(WiFiClient &client, const char *status)
{
    client.print("HTTP/1.1 ");
    client.println(status);
    client.println("Content-type:text/html");
    client.println("Connection: close");
    client.println();
}

static void                         send_main_page(WiFiClient &client, int param)
{
    send_header(client, HTTP_OK);
    client.println();
    client.println();
}

static void                         send_temp(WiFiClient &client, int param)
{
    send_header(client, HTTP_OK);
    client.println();
    client.println();
}

static int                          get_param(const char *url)
{
    unsigned int                    i;

    i = 0;
    while (url[i] && url[i] != '?')
    {
        ++i;
    }
    if (url[i])
    {
        ++i;
    }
    return atoi(&url[i]);
}

static void                         send_not_found(WiFiClient &client)
{
    send_header(client, HTTP_NOT_FOUND);
}

static void                         route(WiFiClient &client)
{
    unsigned int                    i;

    i = 0;
    while (route_list[i].name)
    {
        if (header.indexOf(route_list[i].name) >= 0)
        {
            route_list[i].route_callback(client, get_param(route_list[i].name));
            return;
        }
        ++i;
    }
    send_not_found(client);
}

void                                handle_client()
{
    WiFiClient client = server.available();

    if (client)
    {
        Serial.println("New Client.");
        String currentLine = "";
        currentTime = millis();
        previousTime = currentTime;
        while (client.connected() && currentTime - previousTime <= timeoutTime)
        {
            currentTime = millis();
            if (client.available())
            {
                char c = client.read();
                Serial.write(c);
                header += c;
                if (c == '\n')
                {
                    if (currentLine.length() == 0)
                    {
                        route(client);
                        break;
                    }
                    else
                    {
                        currentLine = "";
                    }
                }
                else if (c != '\r')
                {
                    currentLine += c;
                }
            }
        }
        header = "";
        client.stop();
        Serial.println("Client disconnected.");
        Serial.println("");
    }
}