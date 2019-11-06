

#include <IRremote.h>


#include"remote_control.h"
IRrecv Recv_IR(PIN_REMOTE_RCV);

decode_results sendMess;


int command = 0;


void setup() 
{
  
  Recv_IR.enableIRIn();
  Serial.begin(9600);
  delay(1000);
}
  

void loop() 
{
  
  if(Recv_IR.decode(&sendMess))
   {
      command = analys_order_select(sendMess.value);
      Serial.println(command);
      delay(200);
      Recv_IR.resume();
       
    }
   
  
}
 




