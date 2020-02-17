/*
***********************************************************************************
 Name:		awning_routine.ino
 Created:	07/02/2020 13:11:03
 Author:	Marycha


                                MAIN 


************************************************************************************
*/


#include "configuration.h"





void setup() 
{

    Serial.begin(9600);

}


void loop() 
{
    Serial.println(Sensor_wind.speed_wind);
}
