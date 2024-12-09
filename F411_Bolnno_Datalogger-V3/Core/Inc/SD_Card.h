/*
 * SD_Card.h
 *
 *  Created on: Dec 4, 2024
 *      Author: suriya.prakash
 */

#ifndef INC_SD_CARD_H_
#define INC_SD_CARD_H_

#include <main.h>
#include "SDIO.h"
#include "Data.h"

//FATFS FatFs; //Fatfs handle
//FIL fil; //File handle
//FILINFO fileInfo;
//FRESULT fres; //Result after operations
//DIR dir;




uint8_t SD_Card_Test();
uint8_t File_Number_Create();
uint8_t Num_Sys_Create();
uint8_t HTML_File_Create();
uint8_t Read_Log_Number(uint8_t FileNo);
uint8_t Read_Number_Sys(uint8_t sys_type);
void Create_DataLog_File();
extern DataSet Store_Data();
void DATA_LOG();
void Update_Log_Num();




#endif /* INC_SD_CARD_H_ */
