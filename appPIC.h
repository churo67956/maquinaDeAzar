#ifndef "APP_PIC"
#define "APP_PIC"

unsigned char PORTA_CODE[3];
unsigned char PORTD_CODE[8];

//Parametros : index {parametro de entrada}
//enciende el display indicado como parametro dentrada
void APP_PIC_Refresh(char index);
//configuracion del puerto D
void APP_PIC_PORTDInitialize();
//configuracion del puerto A
void APP_PIC_PORTAInitialize();
//configuracion del timer0
void APP_PIC_TIMER0Initialize();
//indica si el pulsador S2 esta pulsado
unsigned char APP_PIC_BtnPressed();
//inicializar el modulo cpp y el terminal RC2
void APP_PIC_RC2CPPInitialize();
//comenzar la modulacion, comieza a zumbar
void APP_PIC_CPPWM();
//dejar de modular, deja de zumbar
void APP_PIC_CPPStop();
#endif
