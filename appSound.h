#ifndef APP_SOUND
#def APP_SOUND
enum APP_SOUND_STATE{//estados
  APP_SOUND_STATE_INIT = 1,//estado de inicio
  APP_SOUND_STATE_PLAY = 2,//estado sonando
  APP_SOUND_STATE_STOP = 3,//estado fin sonido
  APP_SOUND_STATE_DISABLE = 4//estado desactivado
};

struct APP_SOUND_MODEL{
  unsigned char timerCount;//contador de 20ms
  unsigned char duration;//duracion de la pista
  unsigned char *track;//cadena de notas
  unsigned char length;//longitud de la cadena de notas
  unsigned char pointer;//posicion actual dentro de la cadena de notas
  enum APP_SOUND_STATE state; //estados
};

//void (*APP_SOUND_Callback)();

//modelo de datos (acceso global)
struct APP_SOUND_MODEL appSound;

//fija la pista
void APP_SOUND_SetTrack(unsigned char *track,unsigned char duration/*,void (*callback)()*/);

//funcion de inicializacion del modelo
void APP_SOUND_Initialize();

//máquina de estados
void APP_SOUND_Task();
#endif
