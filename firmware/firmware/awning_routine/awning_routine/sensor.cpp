



#include"sensor.h"






Sensor::Sensor(byte pin, byte set_sens,float calb=0)
{
	_pin = pin;
	_user_setting = set_sens;
	_coef_calib = calb;
}

void Sensor::init()
{
	pinMode(_pin, INPUT);
}



Sensor::Error_feature Sensor::sensor_error(char* mess_err, byte bip_code, int val=0)
{
	Error_feature error;

	error.error = true;
	sprintf(error.mess, "Err: %s", *mess_err);
	error.bip_code = bip_code;
	error.value_error = val;

	return error;
}

/*________________________________________________________________________________________________


									Capteur vitesse vent
					 
___________________________________________________________________________________________________
*/

WindSenor::WindSenor(byte pin , byte set_sens, float calb=0) :  Sensor(pin, set_sens, calb)
{

}

bool WindSenor::check()
{
	_convert_in_value();
	if (speed_wind >= _user_setting) { return true; }				// le capteur a basculer
	return false;
}

float WindSenor::read()
{
	
	return analogRead(_pin);
}

void WindSenor::_convert_in_value()
{
  
	if(_coef_calib != 0)
	{ 
		speed_wind = read() / _coef_calib; 
		if (speed_wind < 0 || speed_wind > 300)
		{ 
		  char mess[] = "Wind Calib";
		  sensor_error(mess, 1, speed_wind); 
		}
	}
	else  
	{ 
	  char mess[] = "Coef Calib";
	  sensor_error(mess, 1, _coef_calib); }
	
}

/*________________________________________________________________________________________________


									Capteur Luminosite

___________________________________________________________________________________________________
*/

BrightnessSensor::BrightnessSensor(byte pin, byte set_sens, float calb=0) : Sensor(pin, set_sens, calb)
{

}
