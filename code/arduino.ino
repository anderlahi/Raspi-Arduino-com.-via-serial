int led = 13;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.read()>0){
    if(Serial.read() == 'H'){
       digitalWrite(led, HIGH);
    }
  
    else if(Serial.read() == 'L'){
      digitalWrite(led, LOW);
    }
  }
}
