/*
** Created by glastis
** Date: 13-Jan-20
** Contact: developers@glastis.com
*/

#ifndef EXTRUDEUSE_ESP_CONNEXION_H
#define EXTRUDEUSE_ESP_CONNEXION_H

#define SERVER_PORT                     80u

const char  *WIFI_SSID =                "REPLACE_WITH_YOUR_SSID";
const char  *WIFI_PASS =                "REPLACE_WITH_YOUR_PASSWORD";


int                                     wait_connection(unsigned int timeout);
void                                    init_connection();

#endif //EXTRUDEUSE_ESP_CONNEXION_H
