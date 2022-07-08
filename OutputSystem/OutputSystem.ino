#include <SoftwareSerial.h>
#include "LedControlMS.h"         //MatrizLED
#include <binary.h>               //MatrizLED
#include <Servo.h>
///////////////////////////////////////////////// MATRIZ LED ///////////////////////////////////////////////////////////
#define NumMatrix 2 //Cuantas matrices vamos a usar
LedControl lc=LedControl(12,/*11*/8,/*10*/7, NumMatrix); //Creamos una instancia de LedControl para la matriz led

void setup() {
  Serial.begin(9600);
  for (int iml=0; iml< NumMatrix ; iml++){ //MatrizLED
    lc.shutdown(iml,false);    // Activar las matrices
    lc.setIntensity(iml,8);    // Poner el brillo a un valor intermedio 8 max 15
    lc.clearDisplay(iml);      // Y borrar todo
  }
}

String inputSignal = "";
String resetInputSignal = "x0000 z";
String primaryButtons = "0000";
int inputButtons = 0000;
char quickButtons = 'x';

void loop() {
  //Leyendo puerto serial con los datos desde Atmega328p-pu (y almacenándola en inputSignal):
  if(Serial.available()){
    inputSignal = Serial.readStringUntil('\n');
    delay(250);
    //Serial.println(inputSignal);
  }
  else{
    inputSignal = "x0000 z";
  }

  //Definimos inputButtons como el valor decimal del botón: Usar Serial.println(inputButtons); para ver resultado.
  primaryButtons[0] = inputSignal[1];
  primaryButtons[1] = inputSignal[2];
  primaryButtons[2] = inputSignal[3];
  primaryButtons[3] = inputSignal[4];
  inputButtons = primaryButtons.toInt();

  //Definimos quickButtons como tipo char, para poder ser usado por el switch: Usar Serial.println(quickButtons); para ver resultado.
  quickButtons = inputSignal[0];

  //Acciones por defecto:
  //ojos_normales();


  //Aquí comienza la programación de nuestros switch - cases:
  switch(quickButtons){
    case 'A':
      Serial.println(quickButtons);
      //codigo
      break;
    case 'B':
      Serial.println(quickButtons);
      //codigo
      break;
    case 'C':
      Serial.println(quickButtons);
      //codigo
      break;
    case 'D':
      Serial.println(quickButtons);
      //codigo
      break;
    case 'E':
      Serial.println(quickButtons);
      //codigo
      break;
    case 'F':
      Serial.println(quickButtons);
      //codigo
      break;
    case 'G':
      Serial.println(quickButtons);
      //codigo
      break;
    case 'H':
      Serial.println(quickButtons);
      //codigo
      break;
    case 'I':
      Serial.println(quickButtons);
      //codigo
      break;
    case 'j':
      Serial.println(quickButtons);
      //codigo
      break;
    default:
      //Serial.println(quickButtons);
      break;
  }

  switch(inputButtons){
    case 1:
      Serial.print(inputButtons);
      Serial.println(": Luces");
      //codigo
      break;
    case 2:
      Serial.print(inputButtons);
      Serial.println(":");
      //codigo
      break;
    case 3:
      Serial.print(inputButtons);
      Serial.println(":");
      //codigo
      break;
    case 4:
      Serial.print(inputButtons);
      Serial.println(": Left click mouse");
      //codigo
      break;
    case 5:
      Serial.print(inputButtons);
      Serial.println(":");
      //codigo
      break;
    case 6:
      Serial.print(inputButtons);
      Serial.println(":");
      //codigo
      break;
    case 7:
      Serial.print(inputButtons);
      Serial.println(":");
      //codigo
      break;
    case 8:
      Serial.print(inputButtons);
      Serial.println(": Right click mouse");
      //codigo
      break;
    case 9:
      Serial.print(inputButtons);
      Serial.println(": Laser");
      //codigo
      break;
    case 10:
      Serial.print(inputButtons);
      Serial.println(":");
      //codigo
      break;
    case 256:
      Serial.print(inputButtons);
      Serial.println(": Laser");
      //codigo
      break;
    case 515:
      Serial.print(inputButtons);
      Serial.println(": [ >.> ]");
      ojos_derecha(); delay(1000);
      //codigo
      break;
    case 654:
      Serial.print(inputButtons);
      Serial.println(": *Enojada*");
      //codigo
      break;
    case 12: //765
      Serial.print(inputButtons);
      Serial.println(": *Parpadeo*");
      accion_final_parpadeo();
      break;
    case 769:
      Serial.print(inputButtons);
      Serial.println(": [ <.< ]");
      ojos_izquierda(); delay(1000);
      ojos_normales();
      //codigo
      break;
    case 771:
      Serial.print(inputButtons);
      Serial.println(": *Triste/Asustada*");
      //codigo
      break;

    default:
      //Serial.println(inputButtons);
      break;
  }

}

void accion_final_parpadeo(){
  ojos_medio_cerrar(); delay(60);     
  ojos_cerrados(); delay(120);
  ojos_medio_cerrar(); delay(60);
  ojos_normales();
}

void ojos_normales(){ // |.|
  lc.setRow(0,0,B00000000); lc.setRow(1,0,B00000000);
  lc.setRow(0,1,B00011000); lc.setRow(1,1,B00011000);
  lc.setRow(0,2,B00011000); lc.setRow(1,2,B00011000);
  lc.setRow(0,3,B00011000); lc.setRow(1,3,B00011000);
  lc.setRow(0,4,B00011000); lc.setRow(1,4,B00011000);
  lc.setRow(0,5,B00011000); lc.setRow(1,5,B00011000);
  lc.setRow(0,6,B00011000); lc.setRow(1,6,B00011000);
  lc.setRow(0,7,B00000000); lc.setRow(1,7,B00000000);
}

void ojos_izquierda(){ //[ <.< ]
  lc.setRow(0,0,B00000000); lc.setRow(1,0,B00000000);
  lc.setRow(0,1,B00000000); lc.setRow(1,1,B00000000);
  lc.setRow(0,2,B11000000); lc.setRow(1,2,B00000011);
  lc.setRow(0,3,B11000000); lc.setRow(1,3,B00000011);
  lc.setRow(0,4,B11000000); lc.setRow(1,4,B00000011);
  lc.setRow(0,5,B11000000); lc.setRow(1,5,B00000011);
  lc.setRow(0,6,B00000000); lc.setRow(1,6,B00000000);
  lc.setRow(0,7,B00000000); lc.setRow(1,7,B00000000);
}

void ojos_derecha(){ //[ >.> ]
  lc.setRow(0,0,B00000000); lc.setRow(1,0,B00000000);
  lc.setRow(0,1,B00000000); lc.setRow(1,1,B00000000);
  lc.setRow(0,2,B00000011); lc.setRow(1,2,B11000000);
  lc.setRow(0,3,B00000011); lc.setRow(1,3,B11000000);
  lc.setRow(0,4,B00000011); lc.setRow(1,4,B11000000);
  lc.setRow(0,5,B00000011); lc.setRow(1,5,B11000000);
  lc.setRow(0,6,B00000000); lc.setRow(1,6,B00000000);
  lc.setRow(0,7,B00000000); lc.setRow(1,7,B00000000);           
}

void ojos_cerrados(){ //[ -.- ]
  lc.setRow(0,0,B00000000); lc.setRow(1,0,B00000000);
  lc.setRow(0,1,B00000000); lc.setRow(1,1,B00000000);
  lc.setRow(0,2,B00000000); lc.setRow(1,2,B00000000);
  lc.setRow(0,3,B11111111); lc.setRow(1,3,B00000000);
  lc.setRow(0,4,B00000000); lc.setRow(1,4,B11111111);
  lc.setRow(0,5,B00000000); lc.setRow(1,5,B00000000);
  lc.setRow(0,6,B00000000); lc.setRow(1,6,B00000000);
  lc.setRow(0,7,B00000000); lc.setRow(1,7,B00000000);
}

void ojos_medio_cerrar(){ //[ ¬ ¬ ]
  lc.setRow(0,0,B00000000); lc.setRow(1,0,B00000000);
  lc.setRow(0,1,B00000000); lc.setRow(1,1,B00000000);
  lc.setRow(0,2,B00011000); lc.setRow(1,2,B11111111);
  lc.setRow(0,3,B00011000); lc.setRow(1,3,B00011000);
  lc.setRow(0,4,B00011000); lc.setRow(1,4,B00011000);
  lc.setRow(0,5,B11111111); lc.setRow(1,5,B00011000);
  lc.setRow(0,6,B00000000); lc.setRow(1,6,B00000000);
  lc.setRow(0,7,B00000000); lc.setRow(1,7,B00000000);
}

void ojos_abiertos(){ //[ OwO ]
  lc.setRow(0,0,B01111110); lc.setRow(1,0,B01111110);
  lc.setRow(0,1,B10000001); lc.setRow(1,1,B10000001);
  lc.setRow(0,2,B10000001); lc.setRow(1,2,B10000001);
  lc.setRow(0,3,B10000001); lc.setRow(1,3,B10000001);
  lc.setRow(0,4,B10000001); lc.setRow(1,4,B10000001);
  lc.setRow(0,5,B10000001); lc.setRow(1,5,B10000001);
  lc.setRow(0,6,B10000001); lc.setRow(1,6,B10000001);
  lc.setRow(0,7,B01111110); lc.setRow(1,7,B01111110);
}

void ojos_felices(){ //[ ^.^ ]
  lc.setRow(0,0,B00000000); lc.setRow(1,0,B00000000);
  lc.setRow(0,1,B00000000); lc.setRow(1,1,B00000000);
  lc.setRow(0,2,B00000000); lc.setRow(1,2,B00011000);
  lc.setRow(0,3,B01000010); lc.setRow(1,3,B00100100);
  lc.setRow(0,4,B00100100); lc.setRow(1,4,B01000010);
  lc.setRow(0,5,B00011000); lc.setRow(1,5,B00000000);
  lc.setRow(0,6,B00000000); lc.setRow(1,6,B00000000);
  lc.setRow(0,7,B00000000); lc.setRow(1,7,B00000000);
}
