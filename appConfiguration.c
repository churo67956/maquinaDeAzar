#include "appConfiguration.h"
//funcion de inicializacion
void APP_CONFIGURATION_Initialize(){
  appConfig.SI[0].PR2 = 126 ;//PR2 nota SI
  appConfig.SI[0].CCPRL = 63 ;//CCPRL nota SI  
  appConfig.LA[0].PR2 = 141; //PR2 nota LA
  appConfig.LA[0].CCPRL = 71; //CCPRL nota LA
  appConfig.SOL[0].PR2 = 158;//PR2 nota SOL
  appConfig.SOL[0].CCPRL = 80;//CCPRL nota SOL
  appConfig._1_SEG_ = 200;//espera de 1seg  
  appConfig._500_MS_ = 100;//espera de 500ms
  appConfig._250_MS_ = 50;//espera de 250ms
  appConfig._50_MS_= 10;//espera de 50 ms
  appConfig._20_MS_= 4;//espera de 20ms 
  appConfig._125_MS_ = 25;//espera de 125ms 
  appConfig._5_MS_=1;//espera de 5 ms 
  appConfig._TMR0_ = 217;//TMR0
  appConfig._10_ = 10;//10
  appConfig._8_ = 8;//8
  appConfig._1_ = 1;//1
 //valores permitidos para los displays
  appConfig.PORTD_CODE[0] = 0xC0;//codigo 7 segmentos valor 0
  appConfig.PORTD_CODE[1] = 0xF9;//codigo 7 segmentos valor 1
  appConfig.PORTD_CODE[2] = 0xA4;//codigo 7 segmentos valor 2
  appConfig.PORTD_CODE[3] = 0xB0;//codigo 7 segmentos valor 3
  appConfig.PORTD_CODE[4] = 0x99;//codigo 7 segmentos valor 4
  appConfig.PORTD_CODE[5] = 0x92;//codigo 7 segmentos valor 5
  appConfig.PORTD_CODE[6] = 0x82;//codigo 7 segmentos valor 6
  appConfig.PORTD_CODE[7] = 0xF8;//codigo 7 segmentos valor 7
  appConfig.PORTA_CODE[0] = 0x01;//encendido primer display
  appConfig.PORTA_CODE[1] = 0x02;//encendido segundo display 
  appConfig.PORTA_CODE[2] = 0x04;//encendido tercer display
//escala ascendente
  appConfig.SCALE_NOTES_ASC[0].PR2 = 238;//DO
  appConfig.SCALE_NOTES_ASC[1].PR2 = 212;//RE
  appConfig.SCALE_NOTES_ASC[2].PR2 = 189;//MI
  appConfig.SCALE_NOTES_ASC[3].PR2 = 178;//FA
  appConfig.SCALE_NOTES_ASC[4].PR2 = 158;//SOL
  appConfig.SCALE_NOTES_ASC[5].PR2 = 141;//LA
  appConfig.SCALE_NOTES_ASC[6].PR2 = 126;//SI
  appConfig.SCALE_NOTES_ASC[0].CCPRL = 119;//DO
  appConfig.SCALE_NOTES_ASC[1].CCPRL = 106;//RE
  appConfig.SCALE_NOTES_ASC[2].CCPRL = 95;//MI
  appConfig.SCALE_NOTES_ASC[3].CCPRL = 89;//FA
  appConfig.SCALE_NOTES_ASC[4].CCPRL = 80;//SOL
  appConfig.SCALE_NOTES_ASC[5].CCPRL = 71;//LA
  appConfig.SCALE_NOTES_ASC[6].CCPRL = 63;//SI
  //escala descendente
  appConfig.SCALE_NOTES_ASC[6].PR2 = 238;//DO
  appConfig.SCALE_NOTES_ASC[5].PR2 = 212;//RE
  appConfig.SCALE_NOTES_ASC[4].PR2 = 189;//MI
  appConfig.SCALE_NOTES_ASC[3].PR2 = 178;//FA
  appConfig.SCALE_NOTES_ASC[2].PR2 = 158;//SOL
  appConfig.SCALE_NOTES_ASC[1].PR2 = 141;//LA
  appConfig.SCALE_NOTES_ASC[0].PR2 = 126;//SI
  appConfig.SCALE_NOTES_ASC[6].CCPRL = 119;
  appConfig.SCALE_NOTES_ASC[5].CCPRL = 106;
  appConfig.SCALE_NOTES_ASC[4].CCPRL = 95;
  appConfig.SCALE_NOTES_ASC[3].CCPRL = 89;
  appConfig.SCALE_NOTES_ASC[2].CCPRL = 80;
  appConfig.SCALE_NOTES_ASC[1].CCPRL = 71;
  appConfig.SCALE_NOTES_ASC[0].CCPRL = 63;
  //pista
  appConfig.SOUND_TRACK[0].PR2 = 31;//nota 1
  appConfig.SOUND_TRACK[1].PR2 = 31;//nota 2
  appConfig.SOUND_TRACK[2].PR2 = 43;//nota 3
  appConfig.SOUND_TRACK[3].PR2 = 43;//nota 4
  appConfig.SOUND_TRACK[4].PR2 = 36;//nota 5
  appConfig.SOUND_TRACK[5].PR2 = 36;//nota 6
  appConfig.SOUND_TRACK[6].PR2 = 45;//nota 7
  appConfig.SOUND_TRACK[7].PR2 = 42;//nota 8
  appConfig.SOUND_TRACK[8].PR2 = 55;//nota 9
  appConfig.SOUND_TRACK[9].PR2 = 55;//nota 10
  appConfig.SOUND_TRACK[0].CCPRL = 16;
  appConfig.SOUND_TRACK[1].CCPRL = 16;
  appConfig.SOUND_TRACK[2].CCPRL = 22;
  appConfig.SOUND_TRACK[3].CCPRL = 22;
  appConfig.SOUND_TRACK[4].CCPRL = 19;
  appConfig.SOUND_TRACK[5].CCPRL = 19;
  appConfig.SOUND_TRACK[6].CCPRL = 23;
  appConfig.SOUND_TRACK[7].CCPRL = 23;
  appConfig.SOUND_TRACK[8].CCPRL = 28;
  appConfig.SOUND_TRACK[9].CCPRL = 28;

}
