#include "appPIC.h"
void APP_PIC_Initialize(){
  //valores permitidos para los displays
  PORTD_CODE[0] = 0xC0;//codigo 7 segmentos valor 0
  PORTD_CODE[1] = 0xF9;//codigo 7 segmentos valor 1
  PORTD_CODE[2] = 0xA4;//codigo 7 segmentos valor 2
  PORTD_CODE[3] = 0xB0;//codigo 7 segmentos valor 3
  PORTD_CODE[4] = 0x99;//codigo 7 segmentos valor 4
  PORTD_CODE[5] = 0x92;//codigo 7 segmentos valor 5
  PORTD_CODE[6] = 0x82;//codigo 7 segmentos valor 6
  PORTD_CODE[7] = 0xF8;//codigo 7 segmentos valor 7
  PORTA_CODE[0] = 0x01;//encendido primer display
  PORTA_CODE[1] = 0x02;//encendido segundo display 
  PORTA_CODE[2] = 0x04;//encendido tercer display
  //Habilitamos la interrupciones
  GIE = 1;//Interrupciones Globales Desactivadas
  PEIE = 1;//Interrupciones de los Periféricos Desactivadas
  


}

//configuracion del puerto D
void APP_PIC_PORTDInitialize(){
  //Configuracion display 7 segmentos
  TRISD = 0x00;//Todos los terminales del PuertoD como salida
  PORTD = 0xff;//Limpiamos los displays
}

//configuracion del puerto A
void APP_PIC_PORTAInitialize(){
  //Configuracion del puerto A como E/S digitales
  ADCON1 = 0b00000110;//Desactivamos PORTA como entrada analógica
  TRISA = 0x10;//Puerto RA4 como entrada. RA0, RA1 y RA2  salidas
}

//configuracion del timer0
void APP_PIC_TIMER0Initialize(){
  //Configuracion timer0
  T0IF = 0;//Bajamos el flag de desbormadiento
  OPTION_REG = 0x06;//predivisor de 128
  T0IE = 1;//habilitar interrupciones del TMR0

}

void APP_PIC_Refresh(char display){
  PORTD = PORTD_CODE[display];//enviamos el codigo por el puerto D
  PORTA = PORTA_CODE[display];//enviamos el codigo por el puerto A
}

//funcion que dice si el boton S2 esta pulsado
unsigned char APP_PIC_BtnPressed(){
  return !RA4;//boton pulsado o no
}

//funcion de inicializacion del RC2-CPP
void APP_PIC_RC2CPPInitialize(){
  //Configuracion del puerto C (buzzer piezo-eléctrico)
  TRISC = 0xFB;//Terminal RC2 como salida
  //Configuracion el timer2, exclusivo para el PWM
  T2CON = 0b00000011;//Pos=1(0000) y Pre=16(11) divisor
  //PWM
  CCP1CON = 0b00001100;//Configuracion modo PWM
}

//comenzar la modulacion, comieza a zumbar
void APP_PIC_CPPWM(){

}

//dejar de modular, deja de zumbar
void APP_PIC_CPPStop(){

}
