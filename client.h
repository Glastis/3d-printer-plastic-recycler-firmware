/*
** Created by glastis
** Date: 14-Jan-20
** Contact: developers@glastis.com
*/

#ifndef EXTRUDEUSE_ESP_CLIENT_H
#define EXTRUDEUSE_ESP_CLIENT_H

const char *HTTP_NOT_FOUND =        "404 Not Found";
const char *HTTP_OK =               "200 OK";

struct                              s_route
{
    char                            *name;
    void                            (*route_callback)(WiFiClient &client, int param);
};

typedef struct s_route              t_route;

void                                handle_client();

#endif //EXTRUDEUSE_ESP_CLIENT_H
