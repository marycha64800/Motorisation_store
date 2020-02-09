/*
 * 
 * 
 * 
 * 
 * 
 *                      FONCTION DU MODE AUTOMATIQUE 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */




#include"ctrl_command.h"



int automatic_command(unsigned long* prv_m, int *cmd_wind, int *cmd_sun, int *cmd_t_h)
{
  if(*cmd_wind && millis() - *prv_m >= 600000)
  {
    *prv_m = millis();
    if(*cmd_sun == 10 || *cmd_sun == 11 || *cmd_sun == 01)
    {
      if(*cmd_t_h)
      {
        return 1;
      }
      else
      {
        return 0;
      }

    }
    else if(*cmd_sun == 0 ) 
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
}

