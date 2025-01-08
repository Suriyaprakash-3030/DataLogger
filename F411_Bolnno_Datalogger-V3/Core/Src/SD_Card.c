/*
 * SD_Card.c
 *
 *  Created on: Dec 4, 2024
 *      Author: suriya.prakash
 */
#include <main.h>
#include <fatfs.h>
#include <ff.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "UART.h"
#include "SD_Card.h"
#include "SDIO.h"
#include "HTML_Code.h"
#include "Data.h"




bool Log_File_Num = 0;
char Num_File_Data[10];   // To store File systen like germany or usa
const char File_Name[9] = {'D', 'A', 'T', 'A', 'L', 'O', 'G', '_','\0'};
uint8_t FileNo = 0;
uint8_t Log_system_Type = 0;  //Its help to store File type
uint8_t NumberSystem = 0;
uint8_t File_Number  = 0;
extern uint8_t Current_Log_File_No;

FILINFO fileInfo;
 FATFS fs;  // file system
 FIL fil; // File
 FILINFO fno;
 DIR dir;  //Dir
 FRESULT fresult;  // result
 UINT br, bw;  // File read/write count

uint8_t SD_Card_Test() {
	fresult = f_mount( & fs, "/", 1);
  if (fresult != FR_OK)
  {
    UART_Printf("xxxxxxxxxxCHECK SD CARD(SD card is must to store data)xxxxxxxxxx\n");
    return fresult;
  }
  HAL_Delay(50);
  UART_Printf("*************SD_CARD_WORKING_FINE*************\n");
  HAL_Delay(50);
  f_mount(NULL, "", 0);
  return fresult;
}



uint8_t File_Number_Create()
{

	fresult = f_mount( & fs, "/", 1);
	  if (fresult != FR_OK)
	  {
		f_closedir(&dir);
		f_mount(NULL, "", 0);
	    UART_Printf("SD CARD MOUNT ISSUE IN FILE_NUMBER_CREATE FUNCTION\n");
	    return fresult;
	  }
	  HAL_Delay(50);

	fresult = f_opendir(&dir, "/");
	if (fresult != FR_OK)
	 {
		UART_Printf("SD CARD DIR OPEN ISSUE IN FILE_NUMBER_CREATE FUNCTION\n");
		return fresult;
	 }
	fresult = f_stat("File_Number.txt", & fileInfo);
	if(fresult != FR_NO_FILE)
	{
		UART_Printf("File_Number.txt already present\n");
		f_closedir(&dir);
		fresult = f_mount(NULL, "", 0);
		return fresult;
	}
	else
	{
		fresult = f_open(&fil, "File_Number.txt", FA_WRITE | FA_READ | FA_CREATE_ALWAYS);
		if (fresult != FR_OK)
		{
			UART_Printf("Problem to create File_Number.txt\n");
		}
		else
		{
			UART_Printf("New File_Number.txt created\n");
			f_puts("1", &fil);
			f_close(&fil);
			f_closedir(&dir);
			fresult = f_mount(NULL, "", 0);
			return fresult;
		}
	}


	f_closedir(&dir);
	fresult = f_mount(NULL, "", 0);
	return fresult;
}





uint8_t Num_Sys_Create()
{
	fresult = f_mount( & fs, "/", 1);
		  if (fresult != FR_OK)
		  {
			f_closedir(&dir);
			f_mount(NULL, "", 0);
		    UART_Printf("SD CARD MOUNT ISSUE IN Num_Sys FUNCTION\n");
		    return fresult;
		  }
		  HAL_Delay(50);

		fresult = f_opendir(&dir, "/");
		if (fresult != FR_OK)
		 {
			UART_Printf("SD CARD DIR OPEN ISSUE IN FILE_NUMBER_CREATE FUNCTION\n");
			return fresult;
		 }
		fresult = f_stat("Num_Sys.txt", & fileInfo);
		if(fresult != FR_NO_FILE)
		{
			UART_Printf("Num_Sys.txt already present\n");
			f_closedir(&dir);
			fresult = f_mount(NULL, "", 0);
			return fresult;
		}
		else
		{
			fresult = f_open(&fil, "Num_Sys.txt", FA_WRITE | FA_READ | FA_CREATE_ALWAYS);
			if (fresult != FR_OK)
			{
				UART_Printf("Problem to create Num_Sys.txt\n");
			}
			else
			{
				UART_Printf("New Num_Sys.txt created\n");
				f_puts("GERMAN", &fil);
				fresult = f_close(&fil);
				f_closedir(&dir);
				f_mount(NULL, "", 0);
				return fresult;
			}
		}


		f_closedir(&dir);
		fresult = f_mount(NULL, "", 0);
		return fresult;

}
uint8_t HTML_File_Create()
{
	fresult = f_mount( & fs, "/", 1);
			  if (fresult != FR_OK)
			  {
				f_closedir(&dir);
				f_mount(NULL, "", 0);
			    UART_Printf("SD CARD MOUNT ISSUE IN HTML file FUNCTION\n");
			    return fresult;
			  }
			  HAL_Delay(50);

			fresult = f_opendir(&dir, "/");
			if (fresult != FR_OK)
			 {
				UART_Printf("SD CARD DIR OPEN ISSUE IN HTML file FUNCTION\n");
				return fresult;
			 }
			fresult = f_stat("index.html", & fileInfo);
			if(fresult != FR_NO_FILE)
			{
				UART_Printf("index.html already present\n");
				f_closedir(&dir);
				fresult = f_mount(NULL, "", 0);
				return fresult;
			}
			else
			{
				fresult = f_open(&fil, "index.html", FA_WRITE | FA_READ | FA_CREATE_ALWAYS);
				if (fresult != FR_OK)
				{
					UART_Printf("Problem to create index.html\n");
				}
				else
				{
					UART_Printf("New index.html created\n");
					f_close(&fil);

				}
			}

			fresult = f_open(&fil, "Num_Sys.txt", FA_READ | FA_WRITE);
			f_gets(Num_File_Data, sizeof(Num_File_Data), & fil);
			f_close(&fil);
			char sys1[] = {"GERMAN"};
			f_open(&fil, "index.html", FA_READ | FA_WRITE);
			UART_Printf("-----------------Pls wait File Loading--------------------- \n");
			(strcmp(Num_File_Data,sys1)==0)? f_puts(GERMAN, & fil) : f_puts(USA, & fil);
			HAL_Delay(10000);
//			  int File_Size = 0;
//			  fresult =  f_stat("index.html", &fileInfo);
//			  File_Size = fileInfo.fsize;
//
//			  if(File_Size <= 14000)
//			  {
//				  UART_Printf("Peoblem while data loading\n");
//				  fresult = f_truncate(&fil);
//				     if (fresult != FR_OK) {
//				         UART_Printf("Failed to truncate file. Error: %d\n", fresult);
//				     } else {
//				         UART_Printf("File emptied successfully.\n");
//				     }
//				 	f_close(&fil);
//				 	f_closedir(&dir);
//				 	f_mount(NULL, "", 0);
//				 	return 1;
//			  }
//			  else
//			  {
			f_close(&fil);
			f_closedir(&dir);
			fresult = f_mount(NULL, "", 0);
			return fresult;
//			  }



}

uint8_t Read_Log_Number(uint8_t FileNo)
{



	char File_No[10];
	f_mount(&fs, "", 1);
	f_opendir(&dir, "/");
	fresult = f_open(&fil, "File_Number.txt", FA_READ | FA_WRITE);
	f_gets(File_No, sizeof(File_No), &fil);
	f_close(&fil);
	f_closedir(&dir);
	f_mount(NULL, "", 0);
	FileNo = (uint8_t)(File_No[0] - '0');
	return FileNo;
}


uint8_t Read_Number_Sys(uint8_t sys_type)
{
	uint8_t system_type = 0;
	char File_No[9];
	f_mount(&fs, "", 1);
	f_opendir(&dir, "/");
	fresult = f_open(&fil, "Num_Sys.txt", FA_READ | FA_WRITE);
	f_gets(File_No, sizeof(File_No), &fil);
	f_close(&fil);
	f_closedir(&dir);
	f_mount(NULL, "", 0);
	char sys1[] = {"GERMAN"};
	system_type = (strcmp(File_No , sys1)==0) ? 1 : 2;
	return system_type;
}



void Create_DataLog_File()
{

    char File[20];
    NumberSystem = Read_Number_Sys(NumberSystem);
    sprintf(File, "%s%d.csv", File_Name, Current_Log_File_No);
    fresult = f_mount(&fs, "", 1);
    f_opendir(&dir, "/");
    fresult = f_open(&fil, File, FA_WRITE | FA_READ | FA_CREATE_ALWAYS);
    if (fresult == FR_OK)
    {

    	const char* header = (NumberSystem == 1)
    	    ? "Time; X-axis; Y-axis; Z-axis; On_brd_TEMP; TEMP1; TEMP2; TEMP3; 40khz;R_Water;Pressure; Sleep_cnt \n"
    	    : "Time, X-axis, Y-axis, Z-axis, On_brd_TEMP, TEMP1, TEMP2, TEMP3, 40khz,R_Water,Pressure, Sleep_cnt \n";

    	f_puts(header, &fil);
        f_close(&fil);
        UART_Printf("Data_log file created and attributes loaded\n");
    }
    else
    {
        UART_Printf("Issue while open Data_log file \n");
    }
    f_mount(NULL, "", 0);
}

//extern DataSet Store_Data();

void DATA_LOG()
{
	 char buffer[200];

	 DataSet data = Store_Data();

	  if(NumberSystem==2)//USA
	  {
		  sprintf(buffer, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f \n", data.Timer_Count, data.XAxis, data.YAxis, data.ZAxis,
					data.On_Board_Temp, data.EXT_Temp1, data.EXT_Temp2, data.EXT_Temp3,
					data.Amplitude, data.Water_Resistance, data.Pressure, data.Sleep_Count); // @suppress("Float formatting support")
	  }
	  else if(NumberSystem==1)//GERMAN
	  {
	  sprintf(buffer, "%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f;%f \n", data.Timer_Count, data.XAxis, data.YAxis, data.ZAxis,
				data.On_Board_Temp, data.EXT_Temp1, data.EXT_Temp2, data.EXT_Temp3,
				data.Amplitude, data.Water_Resistance, data.Pressure, data.Sleep_Count); // @suppress("Float formatting support")

	  for( int i=0;i<sizeof(buffer);i++)
	  {
		  switch (buffer[i])
		  {
		  case ',':
			  buffer[i]=';';
			  break;
		  case '.':
			  buffer[i] = ',';
			  break;
	  }
	  }
	  }

	  	  int File_Size = 0;
	  	  char temp[20];
	  	f_mount(&fs, "", 1);
	  	f_opendir(&dir, "/");
	  	sprintf(temp, "%s%d.csv", File_Name,Current_Log_File_No);
	  	f_open(&fil, temp, FA_READ | FA_WRITE);
	  	f_lseek(&fil, f_size(&fil));
	  	fresult = f_puts(buffer, &fil);
	  	f_stat(temp, &fileInfo);
	  	File_Size = fileInfo.fsize;
	  	f_close(&fil);
	  	f_closedir(&dir);
	  	f_mount(NULL, "", 0);
	  	if(Log_File_Num == 0)
	  	{
	  		Update_Log_Num();
	  		Log_File_Num = 1;
	    }
	  	UART_Printf("Data saved in log file = %s%d file size = %d Bytes   amp = %f\n",File_Name,Current_Log_File_No,File_Size,data.Amplitude);
}

void Update_Log_Num()
{
	uint8_t Log_Number = Current_Log_File_No+1;
	char Log[10];
	sprintf(Log,"%d",Log_Number);
	f_mount( & fs, "/", 1);
	f_opendir(&dir, "/");
	f_stat("File_Number.txt", & fileInfo);
	f_open(&fil, "File_Number.txt", FA_WRITE | FA_READ);
	f_puts(Log, &fil);
	f_close(&fil);
	f_closedir(&dir);
	f_mount(NULL, "", 0);
	UART_Printf("Log Number Updated %d \n",Log_Number);

}
