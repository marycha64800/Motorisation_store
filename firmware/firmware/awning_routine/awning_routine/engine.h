/*
***********************************************************************************************


									Module des moteurs



************************************************************************************************
*/

#ifndef ENGINE_H_
#define ENGINE_H_

#include "Arduino.h"

class Engine
{
public:
	Engine(byte, byte, byte, byte, byte, byte);
	
	template <unsigned N>
	struct Data_error
	{
		bool error = false;
		char mess[N];
		byte bip_code;
		int value_error;
	};

	using Error_feature = Data_error<20>;
	void forward();									// ouverture
	void backward();								// fermeture
	void init();									// initialisation du moteur
	Error_feature sensor_error(char*, byte, int);	// revoie les eventuels dysfonctionnement 

	bool sens_close;								// store ranger 
	bool sens_open;									// store deployer

	

private:
	byte _enable_pin;
	byte _dir_forward_pin;
	byte _dir_backward_pin;
	byte _sens_closed_pin;							// capteur du store ranger
	byte _sens_open_pin;							// cateur du store dployer
	byte _delay_var_speed;

	void _speed_up(byte, byte);
	void _speed_down(byte);

};






#endif // !ENGINE_H_

