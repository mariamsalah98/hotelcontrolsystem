#include "KPD.h"
u8 in_Pin[no_Of_Rows]={Pin0 , Pin1 ,Pin2 ,Pin3};
u8 out_Pin[no_Of_Coloumns]={Pin4 , Pin5 ,Pin6 };

void KPD_ScanKeys( u8 KPD_Array[no_Of_Coloumns][no_Of_Rows]){

	u8 coloumn , row , setter;
	
	for(coloumn=0 ; coloumn < no_Of_Coloumns ; coloumn++){	//deh btlf 3la el coloumns

			for(setter=0 ; setter < no_Of_Coloumns ; setter++){	//deh btst el coloumn el enta feh el o/p value = 0

				if(setter==coloumn)	GPIO_setPinValue(Port_KPD ,out_Pin[setter] ,LOW);
				else	GPIO_setPinValue(Port_KPD ,out_Pin[setter] ,HIGH);
			}
			
			for(row=0 ; row < no_Of_Rows ; row++){	//deh el btgib el values bta3t el pin and save it in array
				
				u8 level;
				GPIO_getPinValue(Port_KPD ,in_Pin[row],&level);
				KPD_Array[coloumn][row] = level;
			}
		}
}

/*

	KPD_ScanKeys(KPD_Array);
*/



void KPD_GetKeys( u8 KPD_Array[no_Of_Coloumns][no_Of_Rows] , u8 *key)
{
	
	if(KPD_Array[0][0]==0) *key= '1';
	

	if(KPD_Array[0][1]==0) *key =  '4';

	if(KPD_Array[0][2]==0) *key = '7';
		
	
	if(KPD_Array[0][3]==0) *key = '*';


	if(KPD_Array[1][0]==0) *key =  '2';

	if(KPD_Array[1][1]==0) *key = '5';

	if(KPD_Array[1][2]==0) *key = '8';

	if(KPD_Array[1][3]==0) *key = '0';

	if(KPD_Array[2][0]==0) *key = '3';
		
	
	if(KPD_Array[2][1]==0) *key = '6';
		
	if(KPD_Array[2][2]==0) *key = '9';

	if(KPD_Array[2][3]==0) *key = '#';

	/*if(KPD_Array[3][0]==0) *key = 'A';

	if(KPD_Array[3][1]==0) *key = 'B';

	if(KPD_Array[3][2]==0) *key = 'C';

	if(KPD_Array[3][3]==0) *key = 'D'; */

	
	
	
}
