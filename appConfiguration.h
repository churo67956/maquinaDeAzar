//Autor : Erik Churo y Edison Aushay
//FICHERO DE CONFIGURACION
#ifndef _APP_CONFIG_
#define _APP_CONFIG_
//estructura de datos que representa una pista
struct APP_TRACK{
  unsigned char PR2;//periodo
  unsigned char CCPRL;//ancho de pulso
};
//estructura de datos que aglutina los diferentes estados de las tareas
enum APP_STATE{//estados
  APP_STATE_INIT = 0,//estado de inicio
  APP_STATE_WAIT_UNTIL_PLAY_END = 1,//la partida finaliza si la ultima nota ha dejado de sonar 
  APP_STATE_END = 2,//estado final
  APP_STATE_REFRESH = 3,//estado de refresco
  APP_STATE_HIGH = 4,//estado no pulsador
  APP_STATE_DEBOUNCE = 5,//estado de espera, elimina rebotes
  APP_STATE_LOW = 6,//estado pulsador
  APP_STATE_ANIMATION = 7,//estado de animacion ( sonido , parpadeo) 
  APP_STATE_DISABLE = 8,//estado desactivado
};

//fichero de configuracion de la aplicacion
struct APP_CONFIGURATION{
  unsigned char PORTA_CODE[3];//codigos puertoA
  unsigned char PORTD_CODE[8];//codigos puerto D 
  struct APP_TRACK SOUND_TRACK[10];//pista inicio de partida  
  struct APP_TRACK SI[1];//nota SI
  struct APP_TRACK LA[1];//nota LA
  struct APP_TRACK SOL[1];//nota SOL
  struct APP_TRACK SCALE_NOTES_ASC[7];//escala de notas ascendente
  struct APP_TRACK SCALE_NOTES_DESC[7];//escala de notas descendente
  unsigned char _5_MS_;//espera de 5 ms
  unsigned char _20_MS_;//espera de 50 ms
  unsigned char _50_MS_;//espera de 50 ms
  unsigned char _500_MS_;//espera de 500ms
  unsigned char _125_MS_;//espera de 250ms
  unsigned char _250_MS_;//espera de 250ms
  unsigned char _1_SEG_;//espera de 1seg
  unsigned char _TMR0_;//TMR0
  unsigned char _10_;//10
  unsigned char _8_;//8
  unsigned char _1_;//1
  enum APP_STATE STATE;//estados
};
//instancia con la configuracion de la aplicacion
struct APP_CONFIGURATION appConfig;
//funcion de inicializacion
void APP_CONFIGURATION_Initialize();
#endif 
