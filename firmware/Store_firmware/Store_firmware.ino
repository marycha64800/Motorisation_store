
/*
 * 
 * 
 * 
 *                          FICHIER PRINCIPAL 
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
// ------------------------- INCLUDE ET DEFINE --------------------------------------------------



#include"store_firmware.h"



 //------------------------------ VARIABLE GLOBALE -----------------------------------------------

DHT dht(PIN_SENSOR_TEMP_HUM,DHTTYPE);
IRrecv Recv_IR(PIN_REMOTE_RCV);
int nbrsRotation = 0;
double speed_wind = 0;
unsigned long previous_millis_anm = 0;
unsigned long previous_millis_cmd = millis();
decode_results sendMess;


 /*
 *                                    *************** DEMARAGE EXECUTION *****************
 * 
 */

 
void setup() 
{
//------- MOTEUR 1 PIN -------
  pinMode(PIN_ENABLE_M1, OUTPUT);
  pinMode(MOVE_ENGINE_OPEN_M1, OUTPUT);
  pinMode(MOVE_ENGINE_CLOSE_M1, OUTPUT);
  pinMode(PIN_SENSOR_M1_EXT,OUTPUT);
  pinMode(PIN_SENSOR_M1_INT,OUTPUT);
  digitalWrite(PIN_SENSOR_M1_EXT,HIGH);
  digitalWrite(PIN_SENSOR_M1_INT,HIGH);
  
  //------- MOTEUR 2 PIN -------
  pinMode(PIN_ENABLE_M2, OUTPUT);
  pinMode(MOVE_ENGINE_OPEN_M2, OUTPUT);
  pinMode(MOVE_ENGINE_CLOSE_M2, OUTPUT);
  pinMode(PIN_SENSOR_M2_EXT,OUTPUT);
  pinMode(PIN_SENSOR_M2_INT,OUTPUT);
  digitalWrite(PIN_SENSOR_M2_EXT,HIGH);
  digitalWrite(PIN_SENSOR_M2_INT,HIGH);
  
  //------- MOTEUR 3 PIN -------
  pinMode(PIN_ENABLE_M3, OUTPUT);
  pinMode(MOVE_ENGINE_OPEN_M3, OUTPUT);
  pinMode(MOVE_ENGINE_CLOSE_M3, OUTPUT);
  pinMode(PIN_SENSOR_M3_EXT,OUTPUT);
  pinMode(PIN_SENSOR_M3_INT,OUTPUT);
  digitalWrite(PIN_SENSOR_M3_EXT,HIGH);
  digitalWrite(PIN_SENSOR_M3_INT,HIGH);
  
  //------- MOTEUR 4 PIN -------
  pinMode(PIN_ENABLE_M4, OUTPUT);
  pinMode(MOVE_ENGINE_OPEN_M4, OUTPUT);
  pinMode(MOVE_ENGINE_CLOSE_M4, OUTPUT);
  pinMode(PIN_SENSOR_M4_EXT,OUTPUT);
  pinMode(PIN_SENSOR_M4_INT,OUTPUT);
  digitalWrite(PIN_SENSOR_M4_EXT,HIGH);
  digitalWrite(PIN_SENSOR_M4_INT,HIGH);

  //--------CAPTEUR LUMNOSITÉ-----------

  pinMode(PIN_SENSOR_EAST, INPUT);
  pinMode(PIN_SENSOR_MID, INPUT);
  pinMode(PIN_SENSOR_WEST, INPUT);

  // ------------TELECOMANDE -------------
  
  Recv_IR.enableIRIn();

  Serial.begin(9600);
  delay(3000);

  attachInterrupt(digitalPinToInterrupt(PIN_ANEMO),event,FALLING);
}

void loop() 
{
  
 start_awning();

}


//------------------------------ Edition des Fonctions -------------------------------------------------------------


void event()
{
  event_sensor_wind(&nbrsRotation);
}






void start_awning()
{
  
  // Creation des variables
  Engine Engine_1 = {PIN_ENABLE_M1, MOVE_ENGINE_OPEN_M1, MOVE_ENGINE_CLOSE_M1, PIN_SENSOR_M1_EXT, PIN_SENSOR_M1_INT, MOVE_TIME_M1};
  Engine Engine_2 = {PIN_ENABLE_M2, MOVE_ENGINE_OPEN_M2, MOVE_ENGINE_CLOSE_M2, PIN_SENSOR_M2_EXT, PIN_SENSOR_M2_INT, MOVE_TIME_M2};
  Engine Engine_3 = {PIN_ENABLE_M3, MOVE_ENGINE_OPEN_M3, MOVE_ENGINE_CLOSE_M3, PIN_SENSOR_M3_EXT, PIN_SENSOR_M3_INT, MOVE_TIME_M3};
  Engine Engine_4 = {PIN_ENABLE_M4, MOVE_ENGINE_OPEN_M4, MOVE_ENGINE_CLOSE_M4, PIN_SENSOR_M4_EXT, PIN_SENSOR_M4_INT, MOVE_TIME_M4};

  

  int sun_is = where_s_sun(PIN_SENSOR_EAST, PIN_SENSOR_MID, PIN_SENSOR_WEST);
  int dry_and_hot = weather(dht.readTemperature(), dht.readHumidity());
  int command;
  
  int wind = ctrl_wind(&speed_wind, &nbrsRotation, &previous_millis_anm);
  
  


  // Demarrages des fonctions 

  if(Recv_IR.decode(&sendMess))
   {
      command = analys_order_select(sendMess.value);
      Serial.println(command);
      delay(200);
      Recv_IR.resume();
       
    }
   else
   {
      if (automatic_command(&previous_millis_cmd, &wind, &sun_is, &dry_and_hot))
      {
        command = FORWARD;
      }
      else
      {
        command = BACKWARD;
      }
   }
  
  switch(command)
  
  {
    
    case FORWARD:
      digitalWrite(Engine_1.dir_forward,HIGH);
      digitalWrite(Engine_2.dir_forward,HIGH);
      digitalWrite(Engine_3.dir_forward,HIGH);
      digitalWrite(Engine_4.dir_forward,HIGH);
      
      engine_move(&Engine_1,&Engine_2,&Engine_3,&Engine_4);
      engine_stop(&Engine_1.sensor_forward, &Engine_1.ctrl_velocity,&Engine_2.sensor_forward,&Engine_2.ctrl_velocity,&Engine_3.sensor_forward, 
      &Engine_3.ctrl_velocity,&Engine_4.sensor_forward, &Engine_4.ctrl_velocity);
      
      
      digitalWrite(Engine_1.dir_forward,LOW);
      digitalWrite(Engine_2.dir_forward,LOW);
      digitalWrite(Engine_3.dir_forward,LOW);
      digitalWrite(Engine_4.dir_forward,LOW);
      break;
      
    case BACKWARD:
      digitalWrite(Engine_1.dir_backward,HIGH);
      digitalWrite(Engine_2.dir_backward,HIGH);
      digitalWrite(Engine_3.dir_backward,HIGH);
      digitalWrite(Engine_4.dir_backward,HIGH);
      
      engine_move(&Engine_1,&Engine_2,&Engine_3,&Engine_4);
      engine_stop(&Engine_1.sensor_backward, &Engine_1.ctrl_velocity,&Engine_2.sensor_backward,&Engine_2.ctrl_velocity,&Engine_3.sensor_backward, 
      &Engine_3.ctrl_velocity,&Engine_4.sensor_backward, &Engine_4.ctrl_velocity);
     
      
      digitalWrite(Engine_1.dir_backward,LOW);
      digitalWrite(Engine_2.dir_backward,LOW);
      digitalWrite(Engine_3.dir_backward,LOW);
      digitalWrite(Engine_3.dir_backward,LOW);
      break;

    case ENG1:
      if(digitalRead(Engine_1.sensor_backward)!=0)
      {
        digitalWrite(Engine_1.dir_forward,HIGH);
        engine_move_solo(&Engine_1);
        digitalWrite(Engine_1.dir_forward,LOW);
      }
      else if(digitalRead(Engine_1.sensor_forward)!=0)
      {
        digitalWrite(Engine_1.dir_backward,HIGH);
        engine_move_solo(&Engine_1);
        digitalWrite(Engine_1.dir_backward,LOW);
      }
      break;
      
    case ENG2:
      if(digitalRead(Engine_2.sensor_backward)!=0)
      {
        digitalWrite(Engine_2.dir_forward,HIGH);
        engine_move_solo(&Engine_2);
        digitalWrite(Engine_2.dir_forward,LOW);
      }
      else if(digitalRead(Engine_2.sensor_forward)!=0)
      {
        digitalWrite(Engine_2.dir_backward,HIGH);
        engine_move_solo(&Engine_2);
        digitalWrite(Engine_2.dir_backward,LOW);
      }
      break;
      
    case ENG3:
      if(digitalRead(Engine_3.sensor_backward)!=0)
      {
        digitalWrite(Engine_3.dir_forward,HIGH);
        engine_move_solo(&Engine_3);
        digitalWrite(Engine_3.dir_forward,LOW);
      }
      else if(digitalRead(Engine_3.sensor_forward)!=0)
      {
        digitalWrite(Engine_3.dir_backward,HIGH);
        engine_move_solo(&Engine_3);
        digitalWrite(Engine_3.dir_backward,LOW);
      }
      break;
      
    case ENG4:
      if(digitalRead(Engine_4.sensor_backward)!=0)
      {
        digitalWrite(Engine_4.dir_forward,HIGH);
        engine_move_solo(&Engine_4);
        digitalWrite(Engine_4.dir_forward,LOW);
      }
      else if(digitalRead(Engine_4.sensor_forward)!=0)
      {
        digitalWrite(Engine_4.dir_backward,HIGH);
        engine_move_solo(&Engine_4);
        digitalWrite(Engine_4.dir_backward,LOW);
      }
      break;
  }
  
}

  




