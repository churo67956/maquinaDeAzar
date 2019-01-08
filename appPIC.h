//Autor : Erik Churo y Edison Aushay
//MIDDLEWARE QUE NOS PERMITE INTERRACTUAR CON EL PIC
//DE ESTA FORMA BASTA CON CAMBIAR ESTE FICHERO PARA 
//EMPLEAR CUALQUIER OTRO PIC ( MAYOR TRANSPARENCIA )
#ifndef _APP_PIC_
#define _APP_PIC_
#include <htc.h> 
#include "appConfiguration.h"
//funcion de inicializacion
void APP_PIC_Initialize();
//Parametros : index {parametro de entrada}
//enciende el display indicado como parametro dentrada
void APP_PIC_Refresh(unsigned char value,unsigned char index);
//configuracion del puerto D
void APP_PIC_PORTDInitialize();
//configuracion del puerto A
void APP_PIC_PORTAInitialize();
//configuracion del timer0
void APP_PIC_TIMER0Initialize();
//fijar el valor de TMR0 que vamos a temporizar
void APP_PIC_TIMER0Set(char);
//devuelve el valor TMR0
char APP_PIC_TIMER0Value();
//indica si el pulsador S2 esta pulsado
unsigned char APP_PIC_BtnPressed();
//inicializar el modulo cpp y el terminal RC2
void APP_PIC_RC2CPPInitialize();
//comenzar la modulacion, comieza a zumbar
void APP_PIC_CPPWM(unsigned char,unsigned char);
//dejar de modular, deja de zumbar
void APP_PIC_CPPStop();
//apagar un display
void APP_PIC_TurnOff(unsigned char);
#endif
