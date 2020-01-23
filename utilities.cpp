/*
** Created by Glastis on 16/01/20.
*/

#include "utilities.h"
#include <EEPROM.h>

int addr = 0;

int                                     eeprom_write(int address, )
{
    EEPROM.write(addr, val);
    if (EEPROM.commit())
    {
        Serial.println("EEPROM successfully committed");
    } else {
        Serial.println("ERROR! EEPROM commit failed");
    }
}


void setup() {
    Serial.begin(115200);
    EEPROM.begin(512);
}

void loop() {
    // need to divide by 4 because analog inputs range from
    // 0 to 1023 and each byte of the EEPROM can only hold a
    // value from 0 to 255.
    int val = analogRead(A0) / 4;

    // write the value to the appropriate byte of the EEPROM.
    // these values will remain there when the board is
    // turned off.


    // advance to the next address.  there are 512 bytes in
    // the EEPROM, so go back to 0 when we hit 512.
    // save all changes to the flash.
    addr = addr + 1;
    if (addr == 512) {
        addr = 0;

    }

    delay(100);
}
