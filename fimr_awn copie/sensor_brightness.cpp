/*
 * 
 * 
 * 
 *            FICHIER DE FONCTION DES CAPTEUR DE LUMINOSITÉ
 * 
 * 
 * 
 * 
 */

#include"sensor_brightness.h"

 int where_s_sun(int sensor_east, int sensor_mid, int sensor_west)
 {
 
  if(digitalRead(sensor_east)==1 && digitalRead(sensor_mid)==1 && digitalRead(sensor_west)==1)
  {
    return FULL_SUN;
  }
  else if(digitalRead(sensor_east)==1 && digitalRead(sensor_mid)==0 && digitalRead(sensor_west)==0)
  {
    return SUN_RISING;
  }
  else if(digitalRead(sensor_east)==0 && digitalRead(sensor_mid)==0 && digitalRead(sensor_west)==1)
  {
    return SUNSET;
  }
  else if(digitalRead(sensor_east)==0 && digitalRead(sensor_mid)==0 && digitalRead(sensor_west)==0)
  {
    return NIGHT;
  }
 }

