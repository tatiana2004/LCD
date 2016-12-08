#include <LiquidCrystal.h>                             //libreria para  LCD



LiquidCrystal lcd (12,11,5,4,3,2);                   //activacion de pines para la LCD

String contrasena;                                   //variable contraseña
String msm1 = "CONTRASENA";                          // variable con el mensaje contraseña
String msm2 = "CORRECTA";                 // variable con el mensaje contraseña correcta
String msm3 = "INCORRECTA";               // variable con el mensaje contraseña incorrecta



void setup() {
   
    Serial.begin(9600);                              //cantidad de vaudios,numero de simbolos que se envian por minuto
    lcd.begin(16,2);                                 //asignacion de la LDC para 16 columnas y 2 filas
    Serial.println("INGRESE CONTRASENA");            //ingrese el usuario contraseña
}

void loop() 
  {
  
  if (Serial.available()>0)                         //lee el dato 
   { 
    contrasena=Serial.readString();                 //Lee el dato ingresado por teclado
    Serial.println(contrasena);                     //Imprime elmensaje
    lcd.clear();                                    //limpia la LCD
    
    if(contrasena=="12345")                         //Compara el texto ingresado con la contraseña que se genero
      {
      lcd.setCursor(0,0);                           //Ubica cursor lcd posicion 0,0
      lcd.print(msm1);                              //Imprime el mensaje contraseña correcta
      lcd.setCursor(0,1);                           // Ubica cursor lcd posicion 0,1
      lcd.print(msm2);                              //Imprime mensaje contraseña
    }
    else                                            //para la contraseña incorrecta envia lo siguiente
      {
      lcd.setCursor(0,0);                           //Ubica cursor lcd posicion 0,0
      lcd.print(msm1);                              //Imprime contraseña incorrecta
      lcd.setCursor(0,1);                           //Ubica cursor lcd posicion 0,1
      lcd.print(msm3);                              //Imprime contraseña
    }
  }  
 }

