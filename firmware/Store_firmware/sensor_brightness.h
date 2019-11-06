/*Nicolas Fauché 25/02/2019
 * 
 * 
 * 
 *              FICHIER DE CONFIGURATION DES CAPTEUR DE LUMINERE
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */



//-------------- PIN SENSOR LUMINOSITE ----------
#define PIN_SENSOR_EAST A1
#define PIN_SENSOR_MID A2
#define PIN_SENSOR_WEST A3
//#define TRIGGER_POINT 500


int where_s_sun(int sensor_east, int sensor_mid, int sensor_west);
