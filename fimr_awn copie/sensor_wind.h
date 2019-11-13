/*
 * 
 * 
 * 
 *                        FICHIER DE CONFIGURATION SENSOR_WIND
 * 
 * 
 */

#include "Arduino.h"

// ----------- PIN ANEMOMETRE ----------------------
#define PIN_ANEMO 3


// ----------- CAPTEUR VENT ---------------------


#define TIME_ANLYS 15000
#define VAR_CORRETION 0
#define PERIM_ANEMO 0.256
#define ACTION_SPEED_WIND 60

void event_sensor_wind(int *nbrsRotation=0);
