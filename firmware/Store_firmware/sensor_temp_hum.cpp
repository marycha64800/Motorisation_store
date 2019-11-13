/*
 * 
 * 
 * 
 * 
 *              FICHIER DE FONCTION TEMPERATURE ET HUMIDITE
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */




#include"sensor_temp_hum.h"

 int weather(float temp, float hum)
 {
    if(temp>ACTION_TEMP && hum<ACTION_HUM)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  
 }

