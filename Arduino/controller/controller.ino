#define AS 3
#define AD 5
#define DS 9
#define DD 6

#define vel 5

#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial esp8266(12, 11);

int message;
int altezza = 0;
int pt_attuale;

Servo as, ad, ds, dd;

void setup() {
  Serial.begin(9600); //Comunicazione via usb
  Serial.println("Check del sistema. Attendere.");
  
  esp8266.begin(115200); //Comunicazione con il modulo Wi-Fi

  //Configurazione dei servo
  as.attach(AS);
  ad.attach(AD);
  ds.attach(DS);
  dd.attach(DD);

  esp8266.println("AT+RST");
  delay(1000);
  esp8266.println("AT+CWMODE=3");
  delay(1000);
  esp8266.println("AT+CIPMUX=0");
  delay(1000);
  esp8266.println("AT+CIPSERVER=1,8569");
  delay(1000);
  
  Serial.println("Pronto a ricevere un comando");
}

void loop() { 
  
  vola(altezza); //reset iniziale
  
  if (Serial.available()){
    message = Serial.parseInt(); //Leggi il messaggio dal seriale
    doActions();
  }
  
  if (esp8266.available()){
    if(esp8266.find("+IPD,")){
      delay(500);
      if (esp8266.find(":")){
        message = esp8266.parseInt(); //Leggi il messaggio dal seriale
        doActions();
      }
    }
  }
  
}

void doActions(){
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
    
    Serial.println(message);
    
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
  ds.write(pt_attuale + vel);
  dd.write(pt_attuale + vel);
  delay(500);
  vola(pt_attuale);
}

void indietro(){
  as.write(pt_attuale + vel);
  ad.write(pt_attuale + vel);
  delay(500); 
  vola(pt_attuale);
}

void sinistra(){
  ad.write(pt_attuale + vel);
  dd.write(pt_attuale + vel);
  delay(500);
  vola(pt_attuale);
}

void destra(){
  as.write(pt_attuale + vel);
  ds.write(pt_attuale + vel);
  delay(500);
  vola(pt_attuale);
}
