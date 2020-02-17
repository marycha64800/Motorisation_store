/*
***********************************************************************************************


							Page de configation du systeme 



************************************************************************************************
*/

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

/*
_________________________________________________________________________________________________



							Zone de configuration 



__________________________________________________________________________________________________
*/


#define MAX_SPEED_WIND 60							//Vitesse a laquelle on rentre les stores
#define CALIB_SENS_WIND 0							// Coef pour ajuster les valeurs du capteur













//___________________________________________________________________________________________________
//***************************************************************************************************



#include "sensor.h"
#include "engine.h"

const uint8_t PIN_WIND_SENSOR = 4;



WindSenor Sensor_wind(PIN_WIND_SENSOR, MAX_SPEED_WIND, CALIB_SENS_WIND);







#endif // !CONFIGURATION_H_

