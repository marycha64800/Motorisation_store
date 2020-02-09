/*
 * 
 * 
 * 
 * 
 * 
 * 
 *                          fichier de fonction anemometre
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include"Arduino.h"
#include "sensor_wind.h"

void event_sensor_wind(int *nbrsRotation=0)
{
   *nbrsRotation = *nbrsRotation +1;

}

int ctrl_wind(double *sp_wind, int *nb_r , unsigned long * prev_mill)
{
  
  if (millis() - *prev_mill >=TIME_ANLYS)
   {
      
      double speed_metr_min = ((*nb_r*4)*PERIM_ANEMO)+VAR_CORRETION;//distance m x min
      *sp_wind = (speed_metr_min*60)/1000;// distance km x h
      *nb_r = 0;
      *prev_mill=millis();
      
      if(*sp_wind < ACTION_SPEED_WIND)
      {
        return 1;
      }
      else
      {
        return 0;
      }
   }
  
}
