#include<Servo.h>

//#define motor1 13
#define motor2 5
#define motor3 2
//#define motor4 27
//#define motor5 26
//#define motor6 25

//Servo motor1s;
Servo motor2s;
Servo motor3s;
//Servo motor4s;
//Servo motor5s;
//Servo motor6s;

void setup() {
  Serial.begin(9600);
  
  //pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT); 
  pinMode(4, OUTPUT); //laranha escuro = 4 = D2
  pinMode(14, OUTPUT); //branco        = 5 = D5
  pinMode(16, OUTPUT); //laranja claro = 6 = D0
  pinMode(12, OUTPUT); // D6
  
  /*pinMode(motor4, OUTPUT);
  pinMode(motor5, OUTPUT);
  pinMode(motor6, OUTPUT);

  motor1s.attach(motor1);*/
  motor2s.attach(motor2);
  motor3s.attach(motor3);
  /*motor4s.attach(motor4);
  motor5s.attach(motor5);
  motor6s.attach(motor6);*/

}

int aa;
int i=0;
char str[30];
char *angulos[6];
int iangulos[6];
int j=0, aux;
int tempo=50;

void loop() {
  while(Serial.available() > 0)
  {
    aa = Serial.read();

    str[i] = (char)aa;

    if((str[i] == '\0' || str[i] == '\n' || str[i] == '\0') and i>1)
    {
      j = 0;
      angulos[j] = strtok(str, ";");
      while( angulos[j] != NULL ) {
        iangulos[j] = atoi(angulos[j]);
        j++;
        angulos[j] = strtok(NULL, ";");
      }

      /*motor1s.write(iangulos[0]);*/
      motor2s.write(iangulos[1]);
      motor3s.write(iangulos[2]);

      aux = iangulos[0]/0.7;
      
      while(aux>0){
        digitalWrite(12,LOW);
        digitalWrite(4,LOW);
        digitalWrite(14,LOW);
        digitalWrite(16,LOW);
        digitalWrite(4,HIGH);
        delay(tempo);
        
        aux--;
        if(aux==0)
          break;
        
        digitalWrite(4,LOW);
        digitalWrite(14,LOW);
        digitalWrite(16,LOW);
        digitalWrite(12,LOW);
        digitalWrite(16,HIGH);
        delay(tempo);

        aux--;
        if(aux==0)
          break;
        
        digitalWrite(16,LOW);
        digitalWrite(4,LOW);
        digitalWrite(14,LOW);
        digitalWrite(12,LOW);
        digitalWrite(14,HIGH);
        delay(tempo);

        aux--;
        if(aux==0)
          break;
      
        digitalWrite(14,LOW);
        digitalWrite(4,LOW);
        digitalWrite(16,LOW);
        digitalWrite(12,LOW);
        digitalWrite(12,HIGH);
        delay(tempo);

        aux--;
        if(aux==0)
          break;
      }
        digitalWrite(14,LOW);
        digitalWrite(4,LOW);
        digitalWrite(16,LOW);
        digitalWrite(12,LOW); 
        Serial.println("Passou motor");
      /*motor4s.write(iangulos[3]);
      motor5s.write(iangulos[4]);
      motor6s.write(iangulos[5]);*/
      
      i = -1;
      j = 0;
    }
    i++;
  }
}
