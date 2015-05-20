#define AS 3
#define AD 5
#define DS 9
#define DD 6

#define vel 5

#include <Servo.h>

int message;
int altezza;
int pt_attuale;

Servo as, ad, ds, dd;

void setup() {
  Serial.begin(9600);
  as.attach(AS);
  ad.attach(AD);
  ds.attach(DS);
  dd.attach(DD);
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
  as.write(potenza);
  ad.write(potenza);
  ds.write(potenza);
  dd.write(potenza);
}


void avanti(){
  ds.write(potenza + vel);
  dd.write(potenza + vel);
  delay(500);
  vola(pt_attuale);
}

void indietro(){
  as.write(potenza + vel);
  ad.write(potenza + vel);
  delay(500);  
  vola(pt_attuale);
}

void sinistra(){
  ad.write(potenza + vel);
  dd.write(potenza + vel);
  delay(500);
  vola(pt_attuale);
}

void destra(){
  as.write(potenza);
  ds.write(potenza);
  delay(500);
  vola(pt_attuale);
}
