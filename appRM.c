#include "appRM.h"

//funcion de inicializacion del modelo
void APP_RM_Initialize(){
  appRM.timerCount = 0;//contador de 1seg
  appRM.updateTimerCount = 0;//contador de 50ms
  appRM.pointer = 0;//apuntador de display 
  appRM.state = APP_RM_STATE_DISABLE;//estado de inicio
}

//funcion de actualizacion del valor de los displays
void APP_RM_Update(char pointer){
  if (appModel.digit[pointer].value == 7){
    appModel.digit[pointer].value = 0;
  }
  else{
    appModel.digit[pointer].value = appModel.digit[pointer].value + 1;
  }
}
//funcion transicion al estado de parada
void APP_RM_STOP(){
  appRM.state = APP_RM_STATE_STOP;
}
//funcion que determina el tipo de premio una vez finalizada la partida
void APP_RM_AwardedSeq(){
  if((appModel.digit[0].value == appModel.digit[1].value)
     && (appModel.digit[1].value == appModel.digit[2].value)){
    appRM.prize = 3;//Los 3 números son iguales
  }
  else if ((appModel.digit[0].value == appModel.digit[1].value)
	   || (appModel.digit[1].value == appModel.digit[2].value)){
    appRM.prize = 2;//Hay 2 números iguales en posiciones consecutivas
  }
  else if (appModel.digit[0].value == appModel.digit[2].value){
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
  numero = (TMR0 >> 1) & 0x07;
  return numero;
}
//maquina de estados
void APP_RM_Task(){
  switch (appRM.state){
  case APP_RM_STATE_INIT://estado de inicio
    //APP_SOUND_Play(SOUND_TRACK,500,NULL);//sonido de inicio
    APP_SOUND_SetTrack(SOUND_TRACK,500);//sonido de inicio
    appSound.state = APP_SOUND_INIT;//estado de inicio
    appsS2.state = APP_S2_STATE_DISABLE;//desabilitamos el boton
    appModel.digit[0].value = APP_RM_Random();//generamos el primer numero aleatorio
    appModel.digit[1].value = (appModel.digit[0].value == 7) ? 0 : appModel.digit[0].value + 1;//generamos el segundo numero aleatorio
    appModel.digit[2].value = (appModel.digit[0].value == 0 ? 7) : appModel.digit[0].value - 1;//generamos el tercer numero aleatorio
    appRM.state = APP_RM_STATE_WAIT;//estado de espera
    break;
  case APP_RM_STATE_WAIT:
    //mas prioritario el estado de FIX_DISPLAY que el estado UPDATE
    if (appRM.timerCount >= 200){//fijar el display
      appRM.timerCount = 0;//reiniciamos el contador
      appRM.state = APP_RM_STATE_FIX_DISPLAY;//estado fijar el display
    }
    else if(appRM.updateTimerCount >= 10){//actualizar los digitos
      appRM.updateTimerCount = 0;//reiniciamos el contador
      appRM.state = APP_RM_STATE_UPDATE;//estado de actualizacion
    }
    break;
  case APP_RM_STATE_UPDATE://solo actualizar los digitos que no estan fijos
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
    appRM.state = APP_RM_STATE_WAIT;//estado de espera
    break;
  case APP_RM_STATE_FIX_DISPLAY:
    if (appRM.pointer == 2){//ya no existen mas displays que fijar
      //APP_SOUND_Play(SI,250,APP_RM_STOP);//sonar SI con callback 
      APP_SOUND_SetTrack(SI,_250_MS_);
      appRM.state = APP_RM_STATE_WAIT_UNTIL_PLAY_END;//aun no hemos finalizado la partida acaba al finar de sonar la nota
    }
    else{
      if (appRM.pointer == 0){//acabamos de parar la primera cifra sonar SOL
	//APP_SOUND_Play(SOL,250,NULL);//sonar SOL c
	APP_SOUND_SetTrack(SI,_250_MS_);
      }
      else if (appRM.pointer == 1){//acabamos de parar la segunda cifra sonar LA
	//APP_SOUND_Play(LA,250,NULL);//sonar LA
	APP_SOUND_SetTrack(LA,_250_MS_);
      }
      appRM.pointer = appRM.pointer + 1;//actualizamos el apuntador
      appRM.state = APP_RM_STATE_WAIT;//estado de espera
    }
    appSound.state = APP_SOUND_INIT;//estado de inicio
    break;
  case APP_RM_STATE_WAIT_UNTIL_PLAY_END://solo pasamos al estado final si el sonido ha finalizado
    if (appSound.state == APP_SOUND_STATE_STOP){//sonido finalizado
      appRM.state = APP_RM_STATE_END;//final de partida
      appSound.state = APP_RM_STATE_DISABLE;//estado inactivo
    }
    break;
  case APP_RM_STATE_END://partida finalizada
    APP_RM_AwardedSeq();//determinamos si la partida tiene premio
    if (appRM.prize == 0){//la combinacion no tiene premio
      appS2.state = APP_S2_STATE_INIT;//activar el pulsador
    }
    else{//la combinacion tiene premio
      appBlink.state = APP_BLINK_STATE_INIT;//efectos de parpadeo
      appOrchestrate.state = APP_ORCHESTRATE_STATE_INIT;//efectos sonoros 
    }
  default://APP_RM_STATE_DISABLE
    break;
  }
}
