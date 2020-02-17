/*
***********************************************************************************************


									Module des capteurs 



************************************************************************************************
*/

#ifndef SENSOR_H_
#define SENSOR_H_


#include "Arduino.h"

class Sensor
{
	/*
		Class commune a tout les capteurs 
			- initialisation 
			- renvoie une erreur si le fonctionnemnt semble incoherent 
	
	*/
protected:

	byte _pin;
	int _user_setting;								// reglage de l'utilisateur module de configuration    
	float _coef_calib;

public:
	Sensor(byte, byte, float);

	template <unsigned N>
	struct Data_error
	{
		bool error = false;
		char mess[N];
		byte bip_code;
		int value_error;
	};

	using Error_feature = Data_error<20>;
	void init();									// initialisation du capteur 
	Error_feature sensor_error(char*, byte, int);	// revoie les eventuels dysfonctionnement 

};

/*________________________________________________________________________________________________


									Capteur vitesse vent

___________________________________________________________________________________________________
*/

class WindSenor : public Sensor
{
public:
	WindSenor(byte, byte, float);
	bool check();									// controle si le capteur bascule
	float read();
	float speed_wind;

private:
	void _convert_in_value();
};

/*________________________________________________________________________________________________


									Capteur luminosité

___________________________________________________________________________________________________
*/

class BrightnessSensor : Sensor
{
public:
	BrightnessSensor(byte, byte, float);
	

private:

};






#endif // !SENSOR_H_
