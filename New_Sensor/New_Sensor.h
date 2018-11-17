#ifndef _NEW_SENSOR_H_
#define _NEW_SENSOR_H_

#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
using namespace std;

class New_Sensor{
	public:
		New_Sensor();
		
		void Info();
		
		void Get_DataFrame(char *str);
		/* 
			Example frame 
				{data1,data2,data3,data4,.....,data28}		
		*/
		
		void Get_AccelNED(float &accelNED_x, float &accelNED_y, float &accelNED_z);
		void Get_Euler(float &euler_x, float &euler_y, float &euler_z);
		void Get_GyroBias(float &gyroBias_x, float &gyroBias_y, float &gyroBias_z);
		void Get_MagNED(float &magNED_x, float &magNED_y, float &magNED_z);
		void Get_MagXYZ(float &magXYZ_x, float &magXYZ_y, float &magXYZ_z);
		void Get_PosNE(float &posNE_x, float &posNE_y);
		void Get_PosD(float &posD);
		void Get_Ret(float &ret_q1, float &ret_q2, float &ret_q3, float &ret_q4); 
		void Get_Vel(float &vel_x, float &vel_y, float &vel_z);
		void Get_Win(float &win_x, float &win_y);
		void Get_Zbias(float &zbias);
		/*
			Example Get
				float euler_x, euler_y, euler_z;
				Get_Euler(euler_x, euler_y, euler_z);
		*/
		
	private:
		/*
		float accelNED_x, accelNED_y, accelNED_z; 	-> sensor[0:2]
		float euler_x, euler_y, euler_z;			-> sensor[3:5]
		float gyroBias_x, gyroBias_y, gyroBias_z;	-> sensor[6:8]
		float magNED_x, magNED_y, magNED_z;			-> sensor[9:11]
		float magXYZ_x, magXYZ_y, magXYZ_z;			-> sensor[12:14]
		float posNE_x, posNE_y, posD;				-> sensor[15:17]
		float ret_q1, ret_q2, ret_q3, ret_q4;		-> sensor[18:21]
		float vel_x, vel_y, vel_z;					-> sensor[22:24]
		float win_x, win_y;							-> sensor[25:26]
		float zbias;								-> sensor[27]
		*/
		float sensor[28];
	
};

void String_nCopy(char *src, char *dest, uint16_t start, uint16_t end);
void Vir_Data(char *str);

extern New_Sensor new_sensor;
#endif
