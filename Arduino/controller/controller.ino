#define AS 3
#define AD 5
#define DS 9
#define DD 6

int message;

void setup() {
  Serial.begin(9600);
  pinMode(AS, OUTPUT);
  pinMode(AD, OUTPUT);
  pinMode(DS, OUTPUT);
  pinMode(DD, OUTPUT);
}

void loop() {
  message = Serial.parseInt();

  if (message < 100){
  
    switch(message){
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
    }
    
  } else {
    vola(message-100);
  }  
  
}

void vola(int potenza){

  analogWrite(AS, potenza);
  analogWrite(AD, potenza);
  analogWrite(DS, potenza);
  analogWrite(DD, potenza);
}
