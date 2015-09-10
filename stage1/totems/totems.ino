#include <Servo.h>

/*

Automatizacion - totems
Created by Cindy Canul Canul & Cristian Kumul Uc
E-mail: cindycanul92@gmail.com, cristiankumul@gmail.com
*/

/* MATERIALES
4 ARDUINO UNO
24 SENSORES HALL
3 CIRCUITO MOSFET
3 SERVOS
9 LEDS
1 LASER
*/

/*  CABLES


#CABLES | #HILOS | 
  24        3      para sensores hall
  3         3      para circuito mosfet
  1         3      para el laser
  9         2      para los leds

  
*Corriente y tierra del arduino dependende de como lo vayan ustedes a conectar 
*El servo motor necesita cables para una fuente de poder
  
*/
// Variables, el numero descrito es el PIN a utilizar en la placa arduino.
// El numero no necesariamente tiene que ser el que esta descrito aqui, puede ser diferente.




int totemPartOne = 2; // Parte uno del totem
int totemPartTwo = 3; // parte dos
int totemPartThree = 4; // parte tres

// Estas son por seguridad, en caso de que las primeras partes no funcionen

int totemPart1 = 5; // respaldo de parte uno del totem
int totemPart2  = 6; // respaldo parte dos
int totemPart3 = 7;  // respaldo parte tres

// validacion del juego
int correct = 13;  // Cuando las tres partes del totem estan correctas
int incorrect = 8; // el juego es incorrecto


int servo = 11;

// ENVIAR
const int arduinoUnoCorrecto = 9;

// RECIBIR
const int enviarArduinoCuatroCorrecto = 10;


int recibirEnviarArduinoCuatroUnoCorrecto; 

/*
// para servomotror
Servo servo; // se crea un objeto servo
int posicion = 0; // posicion del servo
//int servoActivo = 9;
*/
//variables para guardar
int temp = 0;
int temp1 = 0;
int temp2 = 0;
int temp3 = 0;
int temp4 = 0;
int temp5 = 0;
int temp6 = 0;


// INPUTS AND OUTPUTS, entradas y salidas
// para declarar la entra o salida del PIN
void setup() {
  // entradas
 
  
  pinMode(totemPartOne, INPUT); 
  pinMode(totemPartTwo, INPUT); 
  pinMode(totemPartThree, INPUT); 
  
  pinMode(totemPart1, INPUT); 
  pinMode(totemPart2, INPUT); 
 
 
  
 
  // salidas
  pinMode(correct, OUTPUT);  
  pinMode(incorrect, OUTPUT); 
 
  //pinMode(servoActivo, OUTPUT);     
  
  
  // ENVIAR RECIBIR
  pinMode(enviarArduinoCuatroCorrecto, INPUT); 
  pinMode(arduinoUnoCorrecto, OUTPUT); 
  
  // servomotor
  //servo.attach(11); // seleccionamos el PIN a usar.
  pinMode(servo,OUTPUT);
  
  Serial.begin(9600); 
}

 
void loop() {
  

  temp1 = digitalRead(totemPartOne);           temp4 = digitalRead(totemPart1);  
  temp2 = digitalRead(totemPartTwo);           temp5 = digitalRead(totemPart2);  
  temp3 = digitalRead(totemPartThree);         temp6 = digitalRead(totemPart3);  
 
 
  if( (comparePairs(totemPartOne,totemPart1)) )
  //&& (comparePairs(totemPartTwo,totemPart2)) && (comparePairs(totemPartThree,totemPart3)))
  {
  digitalWrite(correct, HIGH);
  digitalWrite(incorrect, LOW);
  digitalWrite(arduinoUnoCorrecto,HIGH);
  digitalWrite(servo,LOW);
  recibirEnviarArduinoCuatroUnoCorrecto = digitalRead(enviarArduinoCuatroCorrecto);
  if (recibirEnviarArduinoCuatroUnoCorrecto == HIGH){
     //temp = correct;
     digitalWrite(servo,HIGH);
     
     //temp = true;
  }
  else if (recibirEnviarArduinoCuatroUnoCorrecto == LOW){
      
     //temp = correct;
     //temp = false;
      digitalWrite(servo,LOW);
  }
  
  //temp = correct;
  //temp = true;
  
  }
  else{
  digitalWrite(correct, LOW);
  digitalWrite(incorrect, HIGH);
  digitalWrite(arduinoUnoCorrecto,LOW);
  digitalWrite(servo,LOW);
  //temp = correct;
  //temp = false;
 
  
  
  }
  //Serial.println(comparePairs(ValTotem,OtherValTotem));
  
 /* 
  // activacion del servo
    if(temp == HIGH)
  {
    //digitalWrite(servoActivo,HIGH);
    //posicion = 150;            // Establecemos el valor de la posicion a 150º  
    //posicion = map(posicion, 0, 1023, 0, 179);     // Establecemos la relacion entre los grados de giro y el PWM  
    servo.write(90);                  // Escribimos la posicion con el mapa de valores al servo  
    delay(150);                           // Y le damos un tiempo para que sea capaz de moverse   

  }else if(temp == LOW){
   //digitalWrite(servoActivo,LOW);
   servo.write(0);
  
  }
  
  */
  
 }  //loop
 
 
 // THIS FUNCTION IS FOR HALL SENSOR
  bool getHallValue(int x){
    if (digitalRead(x)) return true;
    else return false;
  }
  
  bool comparePairs(int x, int y)
  {
    if(getHallValue(x) == true || getHallValue(y) == true ) 
    return true;
    else 
    return false;
  }
  
 


