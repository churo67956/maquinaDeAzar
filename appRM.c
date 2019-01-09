#include "appRM.h"
//funcion de inicializacion del modelo
void APP_RM_Initialize(){
  appRM.timerCount = 0;//contador de 1seg
  appRM.updateTimerCount = 0;//contador de 50ms
  appRM.pointer = 0;//apuntador de display 
  appRM.state = APP_STATE_DISABLE;//estado de inicio
}
//funcion de actualizacion del valor de los displays
void APP_RM_Update(char pointer){
  if (appModel.digit[pointer].value == 7){//si el valor es 7
    appModel.digit[pointer].value = 0;//el valor siguiente debe ser cero
  }
  else{//si el valor no es 7
    appModel.digit[pointer].value = appModel.digit[pointer].value + 1;//agregar 1 al valor actual
  }
}
//funcion que determina el tipo de premio una vez finalizada la partida
void APP_RM_AwardedSeq(){
  if((appModel.digit[0].value == appModel.digit[1].value)
     && (appModel.digit[1].value == appModel.digit[2].value)){//son todos los digitos iguales
    appRM.prize = 3;//Los 3 números son iguales
  }
  else if ((appModel.digit[0].value == appModel.digit[1].value)
	   || (appModel.digit[1].value == appModel.digit[2].value)){//números iguales en posiciones consecutivas
    appRM.prize = 2;//Hay 2 números iguales en posiciones consecutivas
  }
  else if (appModel.digit[0].value == appModel.digit[2].value){// números iguales en posiciones no consecutivas
    appRM.prize = 1;//Hay 2 números iguales en posiciones no consecutivas
  }
  else{
    appRM.prize = 0;//No hay números iguales
  }
}
//funcion que simula aleatoriedad en la generacion de numeros
unsigned char APP_RM_Random(){
  //Esta función devuelve un número aleatorio entre 0 y 7
  //Para ello toma la lectura del TMR0, la divide entre 2 y se le aplica una máscara para que quede un número entre 0 y 8
  unsigned char numero = 0;
  numero = (APP_PIC_TIMER0Value() >> 1) & 0x07;
  return numero;
}

//maquina de estados
void APP_RM_Task(){
  switch (appRM.state){
  case APP_STATE_INIT://estado de inicio
	APP_SOUND_SetTrack(&appConfig.SOUND_TRACK[0],appConfig._10_,appConfig._500_MS_,appConfig._50_MS_);//sonido de inicio
    appSound.state = APP_STATE_INIT;//estado de inicio
    appS2.state = APP_STATE_DISABLE;//desabilitamos el boton
    appModel.digit[0].value = APP_RM_Random();//generamos el primer numero aleatorio
    appModel.digit[1].value = APP_RM_Random();//(appModel.digit[0].value == 7) ? 0 : appModel.digit[0].value + 1;//generamos el segundo numero aleatorio
    appModel.digit[2].value = APP_RM_Random();(appModel.digit[0].value == 0) ? 7 : appModel.digit[0].value - 1;//generamos el tercer numero aleatorio
    appRM.state =  APP_STATE_ANIMATION;//estado de animacion
    appRM.updateTimerCount = appConfig._50_MS_;//la animacion debe de empezar YA, por motivos de la programacion estado ANIMATION
    appRM.pointer = 0;//apuntados al primer digito
    break;
  case  APP_STATE_ANIMATION:
      //mas prioritario el estado de FIX_DISPLAY que el estado UPDATE
      if (appRM.timerCount >= appConfig._1_SEG_){//fijar el display
        appRM.timerCount = 0;//reiniciamos el contador
	    if (appRM.pointer == 0){//acabamos de parar la primera cifra sonar SOL
	      APP_SOUND_SetTrack(&appConfig.SOL[0],appConfig._1_,appConfig._250_MS_,appConfig._250_MS_);
        }
        else if (appRM.pointer == 1){//acabamos de parar la segunda cifra sonar LA
	      APP_SOUND_SetTrack(&appConfig.LA[0],appConfig._1_,appConfig._250_MS_,appConfig._250_MS_);
        }
        else {
	      APP_SOUND_SetTrack(&appConfig.SI[0],appConfig._1_,appConfig._250_MS_,appConfig._250_MS_);//sonar SI
	      appRM.state = APP_STATE_WAIT_UNTIL_PLAY_END;
        }
	    appSound.state =  APP_STATE_INIT;//estado de inicio de la tarea SOUND    
        appRM.pointer = appRM.pointer + 1;//actualizamos el apuntador 
      }
      else if(appRM.updateTimerCount >= appConfig._50_MS_){//actualizar los digitos
        appRM.updateTimerCount = 0;//reiniciamos el contador
        if (appRM.pointer == 0){//actualizar todos los digitos
          APP_RM_Update(0);//actualizamos el primer digito
          APP_RM_Update(1);//actualizamos el segundo digito
          APP_RM_Update(2);//actualizamos el tercer digito
        }
        else if (appRM.pointer == 1){//actualizar 2 digitos
          APP_RM_Update(1);//actualizamos el segundo digito
          APP_RM_Update(2);//actualizamos el tercer digito
        }
        else if (appRM.pointer == 2){//actualizar 1 digito
          APP_RM_Update(2);//actualizamos el tercer digito
        }
      }
    break;
  case  APP_STATE_WAIT_UNTIL_PLAY_END://solo pasamos al estado final si el sonido ha finalizado
    if (appSound.state == APP_STATE_END
	|| appSound.state == APP_STATE_DISABLE){//sonido finalizado
      appRM.state = APP_STATE_END;//final de partida
		//appModel.digit[0].value = 3;
		//appModel.digit[1].value = 3;
		//appModel.digit[2].value = 3;
    }
    break;
  case  APP_STATE_END://partida finalizada
    APP_RM_AwardedSeq();//determinamos si la partida tiene premio  
    if (appRM.prize == 0){//la combinacion no tiene premio
      appS2.state =  APP_STATE_INIT;//activar el pulsador
    }
    else{//la combinacion tiene premio
      appBlink.state = APP_STATE_INIT;//efectos de parpadeo
	  appOrchestrate.state = APP_STATE_INIT;//efectos sonoros 
    }
    appRM.state = APP_STATE_DISABLE;//tarea desactivada
	break;
  default://APP_RM_STATE_DISABLE
    //NO HACER NADA
    break;
  }
}
