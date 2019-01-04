#ifndef APP_RM
#define APP_RM
enum APP_RM_STATE{//estados
  APP_RM_STATE_INIT = 1,//estado de inicio
  APP_RM_STATE_WAIT = 2,//estado no pulsador
  APP_RM_STATE_UPDATE = 3,//estado de espera
  APP_RM_STATE_FIX_DISPLAY = 4,//estado
  APP_RM_STATE_WAIT_UNTIL_PLAY_END = 5,//la partida finaliza si la ultima nota ha dejado de sonar 
  APP_RM_STATE_END = 6,//estado fin partida
  APP_RM_STATE_DISABLE = 6//estado inactivo
};

struct APP_RM_MODEL{
  unsigned char timerCount;//contador de 50ms
  unsigned char updateTimerCount;//contador de 1seg
  unsigned char pointer;//siguiente digito a parar
  unsigned char prize;//premio
  enum APP_RM_STATE state; //estados
};

//modelo de datos (acceso global)
struct APP_RM_MODEL appRM;

//funcion de inicializacion del modelo
void APP_RM_Initialize();
//funcion de actualizacion de los digitos
void APP_RM_Update(char);
//funcion que determina el tipo de premio
void APP_RM_AwardedSeq();
//funcion que simula un generador de numeros aleatorios
unsigned char APP_RM_Random();
//máquina de estados
void APP_RM_Task();
#endif
