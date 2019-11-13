/*Nicolas Fauché 23/02/2019
 * 
 *                                FICHIER DE CONFIGURATION DES MOTEURS                
 *    
 *  Toutes les valeur peuvent etre modifiées. 
 *  
 *  -speed var: modifie le delay dans variation de vitesse et par consequent la vitesse d'accelartion et de deceleration 
 *  -nb_engines: nombres de moteurs.
 *  -adjust_voltage: modifie la tension de depart et la tension d'approche pour percuter les capteurs
 *  -nb_loop_speed: valeur calculer en fonction des pararmetre precedent
 *  -time_in_one_loop : temps dans une boucle. compense les depart succesif
 *  -time_in_loop: temps que le programme sera en pause pendant lexecution des boucles 
 *  
 *  FONCTION STOP EST EN SECURITÉ. FAIRE LE MONTAGE ELECTRIQUE OU LE SWITCH COUPE DIR_FORWARD OU DIR_BACWARD
 */




#include"Arduino.h"



// ----- AUTRE CONFIGURATION --------
#define SPEED_VAR 37                                                       // Modifier la vitesse d'accelaration et de ralentisseent 
#define NB_ENGINES 4
#define ADJUST_VOLTAGE 127                                                 // TENSION DE DEPART ET D'APPROCHE  DES MOTEURS 
#define NB_LOOP_SPEED_VAR (255 - ADJUST_VOLTAGE)
#define TIME_LOOP_ONE_LOOP (NB_LOOP_SPEED_VAR * SPEED_VAR)
#define TIME_IN_LOOP TIME_LOOP_ONE_LOOP*2


// -----------MOTEUR 1 CONFIG -------

#define PIN_ENABLE_M1 11

#define MOVE_ENGINE_OPEN_M1 30
#define MOVE_ENGINE_CLOSE_M1 31

#define PIN_SENSOR_M1_EXT 22
#define PIN_SENSOR_M1_INT 26
#define MOVE_TIME_M1 60000                                                        // NOMARLEMENT DEPLACEMENT DE 1m15s 

// ----------MOTEUR 2 CONFIG --------

#define PIN_ENABLE_M2 12

#define MOVE_ENGINE_OPEN_M2 32
#define MOVE_ENGINE_CLOSE_M2 33

#define PIN_SENSOR_M2_EXT 23
#define PIN_SENSOR_M2_INT 27
#define MOVE_TIME_M2 40000                                                        // NOMALEMENT DEPLACEMENT DE 51S 


//---------- MOTEUR 3 CONFIG ---------


#define PIN_ENABLE_M3 11
#define MOVE_ENGINE_OPEN_M3 34
#define MOVE_ENGINE_CLOSE_M3 35

#define PIN_SENSOR_M3_EXT 24
#define PIN_SENSOR_M3_INT 28
#define MOVE_TIME_M3 40000  


// --------- MOTEUR 4 CONFIG -----------

#define PIN_ENABLE_M4 10
#define MOVE_ENGINE_OPEN_M4 36
#define MOVE_ENGINE_CLOSE_M4 37

#define PIN_SENSOR_M4_EXT 25
#define PIN_SENSOR_M4_INT 2
#define MOVE_TIME_M4 40000  



// prototype de fonction 

typedef struct Engine Engine ;
struct Engine
{
  int ctrl_velocity;
  int dir_forward;
  int dir_backward;
  int sensor_forward;
  int sensor_backward;
  unsigned long travel_time;
};
void engine_speed_variation(int enab, int dir);
void engine_stop(int* sens1, int*enab_1, int* sens2, int*enab_2, int* sens3, int*enab_3, int* sens4, int*enab_4);
void engine_move(Engine *m1,Engine *m2,Engine *m3,Engine *m4); 
void engine_move_solo(Engine *eng);
