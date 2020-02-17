#include "engine.h"

Engine::Engine(byte enbl, byte dir_back, byte dir_forw, byte sens_closd, byte sens_open, byte speed_var=37)
{
	_enable_pin = enbl;
	_dir_forward_pin = dir_forw;
	_dir_backward_pin = dir_back;
	_sens_closed_pin = sens_closd;
	_sens_open_pin = sens_open;
	_delay_var_speed = speed_var;
}

void Engine::init()
{
	pinMode(_dir_forward_pin, OUTPUT);
	pinMode(_dir_backward_pin, OUTPUT);
	pinMode(_enable_pin, OUTPUT);
	pinMode(_sens_open_pin, INPUT);
	pinMode(_sens_closed_pin, INPUT);
	

}

void Engine::_speed_up(byte pin_dir, byte enb)
{
	digitalWrite(pin_dir, HIGH);
	for (byte i = 127; i < 256; i++)
	{
		analogWrite(enb, i);
		delay(_delay_var_speed);
	}

}

void Engine::_speed_down(byte enb)
{
	
	for (byte i = 255; i > 127; i--)
	{
		analogWrite(enb, i);
		delay(_delay_var_speed);
	}
}

