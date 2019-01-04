//Autores : Erik Churo, Eddyson Aushay
//Trabajo Final
//Descripción : Se debe programar un juego de azar basado en combinaciones aleatorias de tres números entre
//              0 y 7 que se mostrarán en la placa con los displays de 7 segmentos: en función de los números
//              repetidos se identificarán combinaciones premiadas. La jugada completa irá acompañada con
//              efectos de sonido y parpadeos en las cifras iguales.
#include<htc.h> 			//Incluimos librería del micro a usar
__CONFIG(WRT_OFF & WDTE_OFF & PWRTE_OFF & FOSC_XT & LVP_OFF);
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//WRT_OFF = Codigo no Potegido
//WDTE_OFF = Watch Dog Timer Desactivado
//PWRTE_OFF = Power Activado
//FOSC_XT = Osiclador cristal
//LVP_OFF = Low Voltage Porgramming Desactivado
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 	
#define _XTAL_FREQ 4000000 				//Oscilador Interno de 4MHZ	

//Librerias
#include "appUtils.c"
#include "appModel.c"
#include "appDisplay.c"
#include "appS2.c"
#include "appBlink.c"

static void interrupt isr(void);

//funcion de inicializacion
void Initialize();

//
//FUNCION PRINCIPAL DEL PROGRAMA
//
void main(){
  Initialize();  //funcion de inicializacion de parametros para el correcto funcionamiento del programa
  WHILE(1){//HILO PRINCIPAL, TAREAS QUE DEBE ATENDER EL MICRO
    APP_REFRESH.TASK();//maquina de estados de refresco
    APP_S2_TASK();//maquina de estados pulsadar boton
    APP_RM_Task();//maquina de estados maquina de azar
    APP_BLINK_Task();//maquina de estados parpadeo
    APP_SOUND_Task();//maquina de estados de sonidos
    APP_ORCHESTRATE_Task();//maquina de estados animacion de sonidos
  }
}

void Initialize(){
 //Configuracion de la tarea REFRESH
  APP_REFRESH_Initialize();//funcion de inicializacion de la tarea REFRESH
  //Configuracion de la tarea S2(presionar el boton de inicio de partida)
  APP_S2_Initialize();//funcion de inicializacion de la tarea S2
  APP_RM_Initialize();//configuracion de la maquina de azar
  APP_BLINK_Initialize();//configuracion del efecto de parpadeo
  APP_SOUND_Initialize();//configuracion del efecto de parpadeo
  APP_ORCHESTRATE_Initialize();//configuracion del efecto sonidos
  appRefresh.state = APP_REFRESH_STATE_INIT;//pasamos al estado de inicio
  appS2.state = APP_S2_STATE_INIT;//pasamos al estado de inicio
}

static void interrupt isr(){
  if (T0IF){
    T0IF = 0;//bajamos el flag
    appRefresh.timerCounter = appRefresh.timerCounter + 1;//incrementados contador de 5ms		
    if (appS2Model.state == APP_S2_STATE_DEBOUNCE){//estado de bloque 
      appS2Model.timerCount += 1; //incrementados contador de 20ms
    }
    if (appRModel.state >= APP_RM_STATE_WAIT
	& appRModel.state < APP_RM_STATE_STOP){//incremetamos los contadores de RM mientras la partida no termine
      appRModel.timerCount +=1;//contador de 1sg
      appRModel.updateTimerCount +=1;//aumentamos contador de 50ms
    }
    if (appBlinkModel.state == APP_BLINK_STATE_WAIT){//si estamos bloqueados 
      appBlinkModel.timerCount +=1;//aumentamos contador de 500ms
    }
  }
}
