#ifndef APP_CONFIG
#define APP_CONFIG

//fichero de configuracion de la aplicacion
struct APP_CONFIGURATION{
  unsigned char SI[1];//nota SI
  unsigned char LA[1];//nota LA
  unsigned char SOL[1];//nota SOL
  unsigned char SOUND_TRACK[100];//pista inicio de partida
  unsigned char _500_MS;//espera de 500ms
  unsigned char _250_MS;//espera de 250ms
  unsigned char _1_SEG;//espera de 1seg
};

//instancia con la configuracion de la aplicacion
struct APP_CONFIGURATION appConfig;

//funcion de inicializacion
void APP_CONG_Initialize();

#endif 
