#ifndef KPD_H_
#define KPD_H_
#include "gpio.h"

#define u8 	unsigned char

#define no_Of_Rows 4


#define no_Of_Coloumns 3


#define Port_KPD Port_B

void KPD_GetKeys(u8 KPD_Array[no_Of_Coloumns][no_Of_Rows]  , u8 *key);
void KPD_ScanKeys(u8 KPD_Array[no_Of_Coloumns][no_Of_Rows]);

#endif
