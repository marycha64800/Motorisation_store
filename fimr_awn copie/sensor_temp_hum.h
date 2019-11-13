/*
 * 
 * 
 * 
 *                        FICHIER DE CONFIGURATION SENSOR TEMPERATURE_HUMIDITE
 * 
 * 
 */
#include"Arduino.h"
#include <Adafruit_Sensor.h>
#include <DHT_U.h>
#include <DHT.h>



// ---------- CARACTERISTIQUE CAPTEUR ----------------
#define PIN_SENSOR_TEMP_HUM A0


#define DHTTYPE DHT11
#define ACTION_TEMP 27
#define ACTION_HUM 80

DHT dht(PIN_SENSOR_TEMP_HUM,DHTTYPE);
