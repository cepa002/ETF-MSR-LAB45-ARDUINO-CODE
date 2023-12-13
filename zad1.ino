// C++ code
//

int pinLed = 9;
int pinBtn = 2;
bool diodeState = false;
bool state = false; // True - hladno, false - toplo

void setup()
{
  
  pinMode(pinLed, OUTPUT);
  pinMode(pinBtn, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0);

  float temp = 100*(float)sensorValue/1023;
    Serial.println(temp);
  if(temp <= 20){
    diodeState = true;
    digitalWrite(pinLed, diodeState);
    state = true;
  }
  else if(state == true){
    diodeState = false;
    digitalWrite(pinLed, diodeState);
    state = false;
  }
    
  int startTime = millis();
  while(digitalRead(pinBtn) == HIGH){}
  int endTime = millis();
  if((endTime-startTime) <= 1500 && (endTime-startTime) >= 50 && state == false){
    diodeState=!diodeState;
  	digitalWrite(pinLed, diodeState);

  }
  
}