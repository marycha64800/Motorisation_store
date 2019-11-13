/*Nicolas Fauché 1/03/2019
 * 
 * 
 * 
 * 
 * 
 *                    FIHCIER DE CONFIGURATION DE LA TELECOMANDE
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */



#include"Arduino.h"

#define PIN_REMOTE_RCV 3




enum{BACKWARD = 100, FORWARD = 200, ENG1=1, ENG2=2, ENG3=3, ENG4=4};
int analys_order_select(unsigned long remote_mess);


