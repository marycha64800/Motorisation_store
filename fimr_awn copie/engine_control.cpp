/*
 * 
 * 
 * 
 * 
 *                                        FICHIER FONTION DES MOTEURS 
 * 
 * 
 * 
 * 
 * 
 * 
 */










#include"engine_control.h"




void engine_speed_variation(int enab, int dir)
{  
  int i;
  if(dir)
  {
    for(i=127; i<256; i++)
    {
      analogWrite(enab, i);
      Serial.print("ACCELARATION à:");
      Serial.println(i);
      delay(SPEED_VAR);
    }
    
  }
  else if(dir==0)
  {
    for(i=255; i>127; i--)
    {
      analogWrite(enab, i);
      Serial.print("DECELERATION à:");
      Serial.println(i);
      delay(SPEED_VAR);
    }
  }
}





void engine_stop(int* sens1, int*enab_1, int* sens2, int*enab_2, int* sens3, int*enab_3, int* sens4, int*enab_4)
{
  int awning_stop = 0; 
  
  while(awning_stop != 1)
  {
    if(digitalRead(*sens1) != 0)
     {
       analogWrite(*enab_1,LOW);                                                                                            // a modifier pour 4 moteurs
       Serial.print("CAPTEUR TROUVE 1");
     }
     else if(digitalRead(*sens2) != 0)
     {
      analogWrite(*enab_2,LOW); 
     }
     else if(digitalRead(*sens3) != 0)
     {
      analogWrite(*enab_3,LOW); 
     }
     else if(digitalRead(*sens4) != 0)
     {
      analogWrite(*enab_4,LOW); 
     }
     else if(digitalRead(*sens1) != 0 && digitalRead(*sens2) != 0 && digitalRead(*sens3) != 0 && digitalRead(*sens4) != 0)
     {
      awning_stop = 1; 
     }
     Serial.println("ATTENTE DU CAPTEUR DE FERMETURE");
  }
}




void engine_move(Engine *m1,Engine *m2,Engine *m3,Engine *m4) 
{
  Serial.println("DEMARAGE DE LA SEQUENCE DE MOUVEMENT ");
  unsigned long previousTime = millis(); 
  unsigned long interval;
  
  int check_interval_m1 = 0;
  int check_interval_m2 = 0;
  int check_interval_m3 = 0;
  int check_interval_m4 = 0;
  int engine_slow_ok = 0;
  
  unsigned int time_already_done = TIME_IN_LOOP;
  unsigned int time_in_one_loop = TIME_LOOP_ONE_LOOP;
  
  Serial.print("temps deja effectuee:");
  Serial.print(time_already_done);
  
  engine_speed_variation(m1->ctrl_velocity,1);                                                                                                                  //demarage des moteurs avec avec une acceleration defini en configuation dans gestion.h 
  engine_speed_variation(m2->ctrl_velocity,1);
  engine_speed_variation(m3->ctrl_velocity,1);
  engine_speed_variation(m4->ctrl_velocity,1);
  
  
  while(engine_slow_ok != 1)                                                                                        // tant que tout les moteurs ne sont pas ralenti et les stores ne sont pas proche des capteurs
  {
    interval = millis() - previousTime;
    Serial.print("ATTENTE POUR LA DECELERATION INTERVAL: ");
    Serial.println(interval);
    
    if(interval >= m1->travel_time -time_already_done && check_interval_m1 == 0)                                          // attention speedup peu etre modifier donc il dois aussi etre modifier dans l'intervalle 
     {
       Serial.print("deceleration moteur 1"); 
       engine_speed_variation(m1->ctrl_velocity,0);
       check_interval_m1 = 1;
      
     }
     else if(interval >= (m2->travel_time - time_already_done) + time_in_one_loop && check_interval_m2 == 0)
     {
        Serial.print("deceleration moteur 2");
        engine_speed_variation(m2->ctrl_velocity,0);
        check_interval_m2 = 1;
     }
     else if(interval >= (m3->travel_time - time_already_done) + (time_in_one_loop*2) && check_interval_m3 == 0)
     {
        Serial.print("deceleration moteur 3");
        engine_speed_variation(m3->ctrl_velocity,0);
        check_interval_m3 = 1;
     }
     else if(interval >= (m4->travel_time - time_already_done) + (time_in_one_loop*3) && check_interval_m4 == 0)
     {
        Serial.print("deceleration moteur 4");
        engine_speed_variation(m4->ctrl_velocity,0);
        check_interval_m4 = 1;
     }
     else if(check_interval_m1, check_interval_m2, check_interval_m3, check_interval_m4)
     {
        Serial.print("TOUT LES MOTEURS SONT RALENTIE");
        engine_slow_ok = 1;
     }
  
     
  }
        
}
