#include "appPIC.h"
void APP_PIC_Initialize(){
  //Habilitamos la interrupciones
  GIE = 1;//Interrupciones Globales Desactivadas
  PEIE = 1;//Interrupciones de los Periféricos Desactivadas 
  APP_PIC_PORTDInitialize();//inicializamos el puerto D
  APP_PIC_PORTAInitialize();//inicializamos el puerto A
  APP_PIC_TIMER0Initialize();//inicializamos el timer0
  APP_PIC_RC2CPPInitialize();//inicializamos el puerto C y el modulo CPP como PWM
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
  ADCON1 = 0x06;//Desactivamos PORTA como entrada analógica
  TRISA = 0xf8;//Puerto RA4 como entrada. RA0, RA1 y RA2  salidas
}

//configuracion del timer0
void APP_PIC_TIMER0Initialize(){
  //Configuracion timer0
  T0IF = 0;//Bajamos el flag de desbormadiento
  OPTION_REG = 0x06;//predivisor de 128
  T0IE = 1;//habilitar interrupciones del TMR0
}

//fijar el valor de TMR0 que vamos a temporizar
void APP_PIC_TIMER0Set(char _TMR0_){
  TMR0 = _TMR0_;
}

//devuelve el valor del TMR0
char APP_PIC_TIMER0Value(){
 return TMR0;
}

//refresco de los display 
//Parametro de entrada : display
void APP_PIC_Refresh(char display){
  PORTD = appConfig.PORTD_CODE[display];//enviamos el codigo por el puerto D
  PORTA = appConfig.PORTA_CODE[display];//enviamos el codigo por el puerto A
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
//parametros de entrada : _PRE2{periodo},_CCPR1L{ancho de pulso}
void APP_PIC_CPPWM(unsigned char _PR2,unsigned char _CCPR1L){
  PR2 = _PR2;//fijamos el periodo
  CCPR1L=_CCPR1L;// ancho de pulso
  TMR2ON = 1;//arranca el TMR2
}
//dejar de modular, deja de zumbar, ciclo de trabajo a cero
void APP_PIC_CPPStop(){
  TMR2ON = 0;
  CCP1CON = 0;//desactivamos el modulo CPP
  CCPR1L = 0;//desactivamos el modulo CPP
  TRISC = 0xFF;//Terminal RC2 como entrada 
}
