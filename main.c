//Autores : Erik Churo, Eddyson Aushay
//TRABAJO FINAL
//DESCRIPCIÓN : SE DEBE PROGRAMAR UN JUEGO DE AZAR BASADO EN COMBINACIONES ALEATORIAS DE TRES NÚMEROS ENTRE
//              0 Y 7 QUE SE MOSTRARÁN EN LA PLACA CON LOS DISPLAYS DE 7 SEGMENTOS: EN FUNCIÓN DE LOS NÚMEROS
//              REPETIDOS SE IDENTIFICARÁN COMBINACIONES PREMIADAS. LA JUGADA COMPLETA IRÁ ACOMPAÑADA CON
//              EFECTOS DE SONIDO Y PARPADEOS EN LAS CIFRAS IGUALES.

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

//Funciones para el correcto funcionamiento del programa principal
#include "appConfiguration.h"
#include "appPIC.h"
#include "appModel.h"
#include "appRefresh.h"
#include "appS2.h"
#include "appRM.h"
#include "appBLINK.h"
#include "appSOUND.h"
#include "appOrchestrate.h"

//atencion de la interrupciones
static void interrupt isr(void);
//funcion de inicializacion
void Initialize();

//
//FUNCION PRINCIPAL DEL PROGRAMA
//

void main(){

  Initialize();  //funcion de inicializacion de parametros para el correcto funcionamiento del programa
  while(1){//HILO PRINCIPAL, TAREAS QUE DEBE ATENDER EL MICRO
    APP_REFRESH_Task();//maquina de estados de refresco
    APP_S2_Task();//maquina de estados pulsadar boton
    APP_RM_Task();//maquina de estados maquina de azar
    APP_BLINK_Task();//maquina de estados parpadeo
    APP_SOUND_Task();//maquina de estados de sonidos
    APP_ORCHESTRATE_Task();//maquina de estados animacion de sonidos
  }
}
void Initialize(){
  APP_PIC_Initialize();//inicializamos el puerto D
  APP_CONFIGURATION_Initialize();//inicializamos las variables de configuracion
  APP_MODEL_Initialize();//inicialimos el modelo de datos principal
  APP_REFRESH_Initialize();//funcion de inicializacion de la tarea REFRESH
  APP_S2_Initialize();//funcion de inicializacion de la tarea S2
  APP_RM_Initialize();//configuracion de la maquina de azar
  APP_BLINK_Initialize();//configuracion del efecto de parpadeo
  APP_SOUND_Initialize();//configuracion del efecto de parpadeo
  APP_ORCHESTRATE_Initialize();//configuracion del efecto sonidos
  appRefresh.state = APP_STATE_INIT;//pasamos al estado de inicio
  appS2.state = APP_STATE_INIT;//pasamos al estado de inicio
  APP_PIC_TIMER0Set(appConfig._TMR0_);//comenzamos a contar
}

//funcion de atencion a la interrupciones
static void interrupt isr(){
  if (T0IF){
    T0IF = 0;//bajamos el flag
    APP_PIC_TIMER0Set(appConfig._TMR0_);//comenzamos a contar
    appRefresh.timerCount = appRefresh.timerCount + 1;//incrementados contador de 5ms		
    if (appS2.state == APP_STATE_DEBOUNCE){//estado de bloque 
      appS2.timerCount = appS2.timerCount + 1; //incrementados contador de 20ms
    }
    if (appRM.state == APP_STATE_ANIMATION){//incremetamos los contadores de RM mientras la partida no termine
      appRM.timerCount = appRM.timerCount + 1;//contador de 1sg
      appRM.updateTimerCount = appRM.updateTimerCount + 1;//aumentamos contador de 50ms
    }
    if (appBlink.state == APP_STATE_ANIMATION){//si estamos bloqueados 
      appBlink.timerCount = appBlink.timerCount + 1;//aumentamos contador de 500ms
    }
    if (appSound.state == APP_STATE_ANIMATION){//si estamos sonando
      appSound.timerCount = appSound.timerCount + 1; //aumentar contador
      appSound.nextTimerCount = appSound.nextTimerCount + 1;//contador de la duracion de cada nota 
    }
  }
}

