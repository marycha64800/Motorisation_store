/*
 * 
 * 
 * 
 * 
 * 
 * 
 *                  FICHIER INITIALISATION 
 * 
 * 
 * 
 * 
 * 
 * 
 */




#include <Adafruit_Sensor.h>
#include <DHT_U.h>
#include <DHT.h>
#include <IRremote.h>
#include <Arduino.h>

#include"remote_control.h"
#include"engine_control.h"
#include"error_control.h"
#include"sensor_brightness.h"
#include"sensor_temp_hum.h"
#include"sensor_wind.h"
#include"ctrl_command.h"

// ------------------- PROTOTYPE DE FONCTION --------------------

enum{BACKWARD = 100, FORWARD = 200, ENG1=1, ENG2=2, ENG3=3, ENG4=4};
enum{SUN_RISING = 10, FULL_SUN = 11, SUNSET = 01, NIGHT = 0};
void event();






