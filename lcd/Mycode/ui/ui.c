#include "ui.h"
#include "lcdc.h"
#include "main.h"


uint8_t UI_Flag=0;
ModeSelect_t Mode_Select=None_mode;
ParameterAdj_t ParameterAdj=P_None;
uint16_t Parameter1_Buffer[18];
uint8_t	P_Flag;


static void UI_Adj(void){

	switch(Mode_Select){
	
		case Parameter1:
			LCD_ShowString(40-10,0, "P1:", GREEN);
			LCD_ShowNum(60-10,0,Parameter1_Buffer[0],5,RED);
			
			LCD_ShowString(40-10,20, "P2:" , GREEN);
			LCD_ShowNum(60-10,20,Parameter1_Buffer[1],5,RED);
			
			LCD_ShowString(40-10,40, "P3:"  , GREEN);
			LCD_ShowNum(60-10,40,Parameter1_Buffer[2],5,RED);
			
			LCD_ShowString(40-10,60, "P4:"  , GREEN);
			LCD_ShowNum(60-10,60,Parameter1_Buffer[3],5,RED);

			LCD_ShowString(40-10,80, "P5:", GREEN);
			LCD_ShowNum(60-10,80,Parameter1_Buffer[4],5,RED);
			
			LCD_ShowString(40-10,100, "P6:" , GREEN);
			LCD_ShowNum(60-10,100,Parameter1_Buffer[5],5,RED);
			
			LCD_ShowString(40-10,120, "P7:"  , GREEN);
			LCD_ShowNum(60-10,120,Parameter1_Buffer[6],5,RED);
			
			LCD_ShowString(40-10,140, "P8:"  , GREEN);
			LCD_ShowNum(60-10,140,Parameter1_Buffer[7],5,RED);

			LCD_ShowString(40-10,160, "P9:", GREEN);
			LCD_ShowNum(60-10,160,Parameter1_Buffer[8],5,RED);
			
			LCD_ShowString(40-10,180, "Parameter_Save"  , MAGENTA);
			LCD_ShowString(40-10,200, "BACK"  , MAGENTA);
			
			LCD_ShowString(150-30,0, "P10:", GREEN);
			LCD_ShowNum(180-30,0,Parameter1_Buffer[9],5,RED);
			
			LCD_ShowString(150-30,20, "P11:" , GREEN);
			LCD_ShowNum(180-30,20,Parameter1_Buffer[10],5,RED);
			
			LCD_ShowString(150-30,40, "P12:"  , GREEN);
			LCD_ShowNum(180-30,40,Parameter1_Buffer[11],5,RED);
			
			LCD_ShowString(150-30,60, "P13:"  , GREEN);
			LCD_ShowNum(180-30,60,Parameter1_Buffer[12],5,RED);

			LCD_ShowString(150-30,80, "P14:", GREEN);
			LCD_ShowNum(180-30,80,Parameter1_Buffer[13],5,RED);
			
			LCD_ShowString(150-30,100, "P15:" , GREEN);
			LCD_ShowNum(180-30,100,Parameter1_Buffer[14],5,RED);
			
			LCD_ShowString(150-30,120, "P16:"  , GREEN);
			LCD_ShowNum(180-30,120,Parameter1_Buffer[15],5,RED);
			
			LCD_ShowString(150-30,140, "P17:"  , GREEN);
			LCD_ShowNum(180-30,140,Parameter1_Buffer[16],5,RED);
			
				
			LCD_ShowString(150-30,160, "P18:", GREEN);
			LCD_ShowNum(180-30,160,Parameter1_Buffer[17],5,RED);
			
			
			
			LCD_Fill(20-10,0,40-10,240 , BLACK);
			LCD_Fill(130-30,0,150-30,180 , BLACK);
			if(ParameterAdj==P_None){
				UIcount2<9?(LCD_ShowString(20-10,(UIcount2*20), ">"  , YELLOW))
									:(UIcount2>17?LCD_ShowString(20-10,(UIcount2*20)-180, ">"  , YELLOW)
									:LCD_ShowString(130-30,((UIcount2-9)*20), ">"  , YELLOW));
			}else{
				(ParameterAdj-1)<9?(LCD_ShowString(20-10,((ParameterAdj-1)*20), ">>"  , YELLOW))
									:((ParameterAdj-1)>17?LCD_ShowString(20-10,((ParameterAdj-1)*20)-180, ">>"  , YELLOW)
									:LCD_ShowString(130-30,(((ParameterAdj-1)-9)*20), ">>"  , YELLOW));
			}
			break;
		case Parameter2:
			
			break;
		case Parameter3:
			
			break;
		default:
			
			break;
	}
}




static void UI_Working(void){

	switch(Mode_Select){
		case Mode1:
//			LCD_ShowString(80 ,80-40 ,"Temp:",GREEN);
//			LCD_ShowNum1(140,80-40,temp,4,RED);
//			LCD_ShowString(80 ,120-40 ,"Threshold:",GREEN);
//			LCD_ShowNum1(160,120-40,tempThreshold,4,RED);
			break;
		case Mode2:
//			LCD_ShowString(80 ,80-40 ,"saveImgS:",GREEN);
//			LCD_ShowNum(160,80-40,saveImgS,2,RED);
//			LCD_ShowString(80 ,120-40 ,"saveImgNum:",GREEN);
//			LCD_ShowNum(160,120-40,saveImgNum,2,RED);
			break;
		case Mode3:
//			LCD_ShowString(80 ,80-40 ,"saveImgNum:",GREEN);
//			LCD_ShowNum(160,80-40,saveImgNum,2,RED);
//			if(descript<20){
//				if(descript==0){
//					LCD_ShowString(80 ,120-40 ,"finding",GREEN);
//				}else{
//					LCD_ShowString(80 ,120-40 ,"Descript:",GREEN);
//					LCD_ShowNum(160,120-40,descript,2,RED);
//				}
//			}else{
//				LCD_ShowString(80 ,120-40 ,"Descript:",GREEN);
//				LCD_ShowString(160 ,120-40 ,"NONE",GREEN);
//			}
			break;
		case Mode4:
//			if(mask==2){
//				LCD_ShowString(80 ,80-40 ,"Have mask",GREEN);
//			}else if(mask==1){
//				LCD_ShowString(80 ,80-40 ,"No mask",GREEN);
//			}else{
//				LCD_ShowString(80 ,80-40 ,"Finding",GREEN);
//			}
			break;
		case Mode5:
//			if(Test5_Flag==0){//////////////////////////////////////////////////////////////////////////////////////////////
//				LCD_ShowString(80 ,120-40 ,"searching face?",GREEN);
//			}else if(Test5_Flag==1){//////////////////////////////////////////////////////////////////////////////////////////////
//				LCD_ShowString(20 ,120-40 ,"Wait for searching face",GREEN);
//			}else if(Test5_Flag==2){//////////////////////////////////////////////////////////////////////////////////////////////
//		   	if(descript<20){
//					LCD_ShowString(80 ,80-40 ,"Descript:",GREEN);
//					LCD_ShowNum(160,80-40,descript,2,RED);
//				}else{
//					LCD_ShowString(80 ,120-40 ,"Descript:",GREEN);
//					LCD_ShowString(80 ,120-40 ,"NONE:",GREEN);
//				}
//				LCD_ShowString(80 ,120-40 ,"measureing temp?",GREEN);
//			}else if(Test5_Flag==3){//////////////////////////////////////////////////////////////////////////////////////////////
//				LCD_ShowString(20 ,120-40 ,"Wait for measureing temp",GREEN);
//			}else if(Test5_Flag==4){//////////////////////////////////////////////////////////////////////////////////////////////
//				if(descript<20){
//					LCD_ShowString(80 ,80-40 ,"Descript:",GREEN);
//					LCD_ShowNum(160,80-40,descript,2,RED);
//				}else{
//					LCD_ShowString(80 ,120-40 ,"Descript:",GREEN);
//					LCD_ShowString(80 ,120-40 ,"NONE:",GREEN);
//				}
//				LCD_ShowString(80 ,80-40-20 ,"Temp:",GREEN);
//				LCD_ShowNum(160,80-40-20,temp,2,RED);
//				LCD_ShowString(80 ,120-40 ,"searching mask?",GREEN);
//			}else if(Test5_Flag==5){//////////////////////////////////////////////////////////////////////////////////////////////
//				LCD_ShowString(20 ,120-40 ,"Wait for searching mask",GREEN);
//			}else if(Test5_Flag==6){//////////////////////////////////////////////////////////////////////////////////////////////
//				if(descript<20){
//					LCD_ShowString(80 ,120 ,"Descript:",GREEN);
//					LCD_ShowNum(160,120,descript,2,RED);
//				}else{
//					LCD_ShowString(80 ,120 ,"Descript:",GREEN);
//					LCD_ShowString(180 ,120 ,"NONE:",GREEN);
//				}
//				LCD_ShowString(80 ,80 ,"Temp:",GREEN);
//				LCD_ShowNum(160,80,temp,2,RED);
//				if(mask==2){
//					LCD_ShowString(80 ,40 ,"Have mask",GREEN);
//				}else if(mask==1){
//					LCD_ShowString(80 ,40 ,"No mask",GREEN);
//				}
//			}
			break;
		case Mode6:
//				LCD_ShowString(80 ,80-40 ,"Temp:",GREEN);
//				LCD_ShowNum1(140,80-40,temp+4,4,RED);
//				LCD_ShowString(80 ,120-40 ,"Threshold:",GREEN);
//				LCD_ShowNum1(160,120-40,tempThreshold,4,RED);
			break;
		
		default:
			
			break;
	}
}



static void UI_Mode(void){

	LCD_ShowString(60 , 0 ,"Mode_Select:",MAGENTA);
	LCD_ShowString(90 , 30 ,"Mode1",GREEN);
	LCD_ShowString(90 ,50 ,"Mode2",GREEN);
	LCD_ShowString(90 ,70 ,"Mode3",GREEN);
	LCD_ShowString(90 ,90 ,"Mode4",GREEN);
	LCD_ShowString(90 ,110 ,"Mode5",GREEN);
	LCD_ShowString(90 ,130 ,"Mode6",GREEN);
	LCD_ShowString(90 ,150 ,"Parameter1",GREEN);
	LCD_ShowString(90 ,170 ,"Parameter2",GREEN);
	LCD_ShowString(90 ,190 ,"Parameter3",GREEN);
	
	LCD_Fill(70,30,90,240 , BLACK);
	LCD_ShowString(70,(UIcount1*20)+30, ">"  , YELLOW);
}



static void UI_Running(void){
	
	if(UI_Flag==1){
		
		UI_Flag=0;
		LCD_Fill(0,0,240,240 , BLACK);
	}
	
	LCD_ShowNum(210,0,UIcount1,2,GRAY);
	LCD_ShowNum(210,20,UIcount2,2,GRAY);
	UIcount3==-10?LCD_ShowString(205,40," B ",GRAY):LCD_ShowNum2(200,40,UIcount3,2,GRAY);
	
	if(Mode_Select==None_mode){
		UI_Mode();
	}else if(Mode_Select>0&&Mode_Select<7){
		UI_Working();
	}else{
		UI_Adj();
	}
}



static void UI_Key(void){
	
	UI_Flag=1;
	switch(Mode_Select){
		
		case None_mode:
			Mode_Select=(ModeSelect_t)(UIcount1+1);
			break;
		
		case Parameter1:
			switch(ParameterAdj){
				case P_None:
					ParameterAdj=(ParameterAdj_t)(UIcount2+1);
					UI_Flag=0;
					break;
				case Parameter_Save:
					if(UIcount3==-10){
						ParameterAdj=P_None;
					}else{
						ParameterAdj=P_None;
						P_Flag=1;
					}
					break;
				case BACK:
					if(UIcount3==-10){
						ParameterAdj=P_None;
					}else{
						ParameterAdj=P_None;
						Mode_Select=None_mode;
					}
					break;
				default:
					UI_Flag=0;
					if(UIcount3==-10){
						ParameterAdj=P_None;
					}else{
						Parameter1_Buffer[ParameterAdj-1]+=UIcount3;
					}
					break;
			}
			break;
			
		case Parameter2:
			Mode_Select=None_mode;
			break;
		
		case Parameter3:
			Mode_Select=None_mode;
			break;
		
		default:
//			Test2_Flag=0;
//			Test3_Flag=0;
//			Test4_Flag=0;
//			Test5_Flag=0;
//			Beep_Flag=0;
//			mask=0;
//			descript=0;
//			MP3_0();
			Mode_Select=None_mode;
			break;
	}
}



UI_t UI = {
	
	UI_Mode,
	UI_Working,
	UI_Adj,
	UI_Running,
	UI_Key,
};




















