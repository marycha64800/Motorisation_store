




#include"luminosite.h"


void setup() 
{
  pinMode(PIN_SENSOR_EAST, INPUT);
  pinMode(PIN_SENSOR_MID, INPUT);
  pinMode(PIN_SENSOR_WEST, INPUT);

  
}

void loop() 
{
 
  int sun_is = where_s_sun(PIN_SENSOR_EAST, PIN_SENSOR_MID, PIN_SENSOR_WEST);

}
