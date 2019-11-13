/*
 * 
 * 
 * 
 * 
 * 
 *                    FICHIER DE FONCTION REMOTE CONTROL
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/

#include"remote_control.h"





int analys_order_select(unsigned long remote_mess) 
{
  switch(remote_mess)
  {
    case 17:
      return ENG1;
      break;
    case 2065:
      return ENG2;
      break;
    case 1041:
      return ENG3;
      break;
    case 3089:
      return ENG4;
      break;
    case 2257:
       return FORWARD;
       break;
     case 209:
      return BACKWARD;
    default:
      return 600;
      
  }
}
