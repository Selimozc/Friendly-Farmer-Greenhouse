#define humiditySensor   A0 
#define LM35             A1 
#define LDR              A2
#define waterlevelSensor A3

int role=3;  
int limitValue=550;

int ldr_led=8;

int lm35_buzzer=2;
int reading_value=0;
float temperature_voltage=0;
float temperature=0;


int sensorvalue=0;
int green_led=11;
int yellow_led=10;
int red_led=9;
int buzzer=12;

void setup() {
pinMode(role,OUTPUT);
pinMode(humiditySensor,INPUT);
digitalWrite(role,LOW);
Serial.begin(9600);

pinMode(lm35_buzzer,OUTPUT);
Serial.begin(9600);

pinMode(ldr_led,OUTPUT);
Serial.begin(9600);

pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
Serial.begin(9600);
  
} 
void loop() {
  humiditySensor_Readings();
  LDR_Readings();
  LM35_Readings();
  Waterlevelsensor_Readings();
}
void humiditySensor_Readings(){
   int humidity=analogRead(humiditySensor);
  //Humidity sensor loop part
  Serial.println(humidity);
  Serial.print("Humidity=");
  Serial.print(!humidity);
  Serial.print("\n");
  if(limitValue>=humidity) //limitValue=550
  {
    digitalWrite(role,HIGH);
  }
  else
  {
    digitalWrite(role,LOW);
  }
}
void LDR_Readings(){
  int light=analogRead(LDR);
//LDR loop part
 
  Serial.println(light);
  Serial.print("Light=");
  Serial.print(!light);
  Serial.print("\n");
  if(light>=320){
    digitalWrite(ldr_led,LOW);
  }
  else{
    digitalWrite(ldr_led,HIGH);
  }
}
void LM35_Readings(){
 reading_value=analogRead(LM35); 
//LM35 loop part
  temperature_voltage=(5000.0/1023.0)*reading_value;
  temperature=temperature_voltage/10.0;
  Serial.println(temperature);
  Serial.print("Temperature=");
  Serial.print(!reading_value);
  Serial.print("\n");
  if(temperature>=15){
    digitalWrite(lm35_buzzer,LOW); 
  }
  else{
    digitalWrite(lm35_buzzer,HIGH);
  }
}
void Waterlevelsensor_Readings(){
  int sensorvalue=analogRead(waterlevelSensor);
//Water level sensor loop part
Serial.println(sensorvalue);
Serial.print("Water Level=");
Serial.print(!sensorvalue);
Serial.print("\n");
if(sensorvalue>=401){
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(12,LOW);
  delay(100);
}
else if((sensorvalue<=400) && (sensorvalue>=300)){
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
  delay(100);
}
else if(sensorvalue<=299){
  digitalWrite(9,HIGH);
  digitalWrite(12,HIGH);
   digitalWrite(10,LOW);
digitalWrite(11,LOW);
delay(2000);
}
else{
  digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
delay(100);
  
}
}




  
  
