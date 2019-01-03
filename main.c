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

void main(){
  //valores por defecto al encender la máquina
  appModel.digit[0].value = 0;
  appModel.digit[1].value = 0;
  appModel.digit[2].value = 0;
  
  APP_MODEL.Initialization();//inicialización de las 3 cifras a cero
  APP_DISPLAY.Initialization();//inicialización de la acción mostrar números en placa  
  while(1){//hilo principal, tareas que debe atender el micro
    APP_DISPLAY.Task();//mostrar los numeros en los display
    APP_S2.Task();//máquina de estados pulsador S2
    APP_RM.Task();//máquina de estados Maquina Aleatorio
  }
}

static void interrupt isr(){
  if (T0IF){
    T0IF = 0;//bajamos el flag
    appDisplayModel.timerCounter += 1;//incrementados contador de 5ms		
    if (appS2Model.state == APP_S2_STATE_DEBOUNCE){//estado de bloque 
      appS2Model.timerCount += 1; //incrementados contador de 20ms
    }
    if (appRModel.state >= APP_RM_STATE_WAIT
	& appRModel.state < APP_RM_STATE_STOP){//incremetamos los contadores de RM mientras la partida no termine
      appRModel.timerCount +=1;//contador de 1sg
      appRModel.setterTimerCount +=1;//aumentamos contador de 50ms
    }
    if (appBlinkModel.state == APP_BLINK_STATE_WAIT){//si estamos bloqueados 
      appBlinkModel.timerCount +=1;//aumentamos contador de 500ms
    }
  }
}
