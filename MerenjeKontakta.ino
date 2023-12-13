/* Arduino kod koji omogućava merenje kontakta prsta sa senzorom dodira.
Pin SIG je povezan na analogni ulaz A0 */

unsigned long startTime = 0;
unsigned long elapsedTime;

void setup(){
  Serial.begin(9600);
}

void loop(){
  float senzor = analogRead(A0) * (5.0 / 1024.0);
  //Serial.println(senzor); // po zelji prikazati izlaz iz senzora
  if ((senzor > 4.0) && (startTime == unsigned(0))) {
    startTime = millis();
  }
  if ((senzor > 4.0) && (startTime > unsigned(0))) {
    elapsedTime = millis() - startTime;
  }
  if ((senzor < 1.0) && (startTime > unsigned(0))) {
    Serial.println(elapsedTime);
    startTime = unsigned(0);
  }
}
