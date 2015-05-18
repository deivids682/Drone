#define AS 3
#define AD 5
#define DS 9
#define DD 6

int message;
int altezza;
int pt_attuale;

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
        avanti();
        break;
      case 2:
        indietro();
        break;
      case 3:
        sinistra();
        break;
      case 4:
        destra();
        break;
    }
    
  } else {
    pt_attuale = message - 100;
    vola(pt_attuale);
  }  
  
}

void vola(int potenza){
  altezza = potenza;
  analogWrite(AS, potenza);
  analogWrite(AD, potenza);
  analogWrite(DS, potenza);
  analogWrite(DD, potenza);
}

void avanti(){
  analogWrite(DS, pt_attuale + 50);
  analogWrite(DD, pt_attuale + 50);
  vola(pt_attuale);
}

void indietro(){
  analogWrite(AS, pt_attuale + 50);
  analogWrite(AD, pt_attuale + 50);
  vola(pt_attuale);
}

void sinistra(){
  analogWrite(AD, pt_attuale + 50);
  analogWrite(DD, pt_attuale + 50);
  vola(pt_attuale);
}

void destra(){
  analogWrite(AS, pt_attuale + 50);
  analogWrite(DS, pt_attuale + 50);
  vola(pt_attuale);
}
