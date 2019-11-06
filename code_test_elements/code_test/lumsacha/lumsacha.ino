









void setup() 
{
 pinMode(8,OUTPUT);
 pinMode(A10,INPUT);
 Serial.begin(9600);
 delay(50);

}

void loop() 
{
  Serial.println(analogRead(A10));
  delay(1000);

}
