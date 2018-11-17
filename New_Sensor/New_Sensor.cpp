#include "New_Sensor.h"

New_Sensor new_sensor;

// Constructor New_Sensor
New_Sensor::New_Sensor()
{
	uint8_t i;
	for(i=0; i<28; i++)
		this->sensor[i] = 0;
}

// New_Sensor::Info
// View all sensor value
void New_Sensor::Info()
{
	uint8_t i;
	cout<<"New_Sensor Info"<<endl;
	for(i=0; i<28; i++)
	{
		cout<<"sensor["<<int(i)<<"]: "<<this->sensor[i]<<"  ";
		if((i+1)%5==0)
			cout<<endl;
	}
	cout<<endl<<"-----------------"<<endl<<endl;
}

// New_Sensor::Get_DataFrame
// Split and handling data from string dataFrame
void New_Sensor::Get_DataFrame(char *str)
{
	int16_t i = 0;
	uint16_t start = 0;
	uint16_t len = strlen(str);
	int8_t j = 0;
	
	char tmp_str[10];
	float tmp_sensor[28];
	
	for(i=0; i<len; i++)
	{
		if(str[i]==',')
		{
			String_nCopy(str, tmp_str, start, i-1);
			tmp_sensor[j++] = atof(tmp_str);
			start = i+1;
		}
	}
	if(start<len-1)
	{
		String_nCopy(str, tmp_str, start, len);
		tmp_sensor[j++] = atof(tmp_str);	
	}
	if(j<28)
		return;
	else
	{
		while(j>=0)
		{
			j--;
			this->sensor[j] = tmp_sensor[j];
		}
	}	
}

/*
	Get Data
*/

// Get_AccelNED
void New_Sensor::Get_AccelNED(float &accelNED_x, float &accelNED_y, float &accelNED_z)
{
	accelNED_x = this->sensor[0];
	accelNED_y = this->sensor[1];
	accelNED_z = this->sensor[2];
}

// Get_Euler
void New_Sensor::Get_Euler(float &euler_x, float &euler_y, float &euler_z)
{
	euler_x = this->sensor[3];
	euler_y = this->sensor[4];
	euler_z = this->sensor[5];
}

// Get_GyroBias
void New_Sensor::Get_GyroBias(float &gyroBias_x, float &gyroBias_y, float &gyroBias_z)
{
	gyroBias_x = this->sensor[6];
	gyroBias_y = this->sensor[7];
	gyroBias_z = this->sensor[8];
}

// Get_MagNED
void New_Sensor::Get_MagNED(float &magNED_x, float &magNED_y, float &magNED_z)
{
	magNED_x = this->sensor[9];
	magNED_y = this->sensor[10];
	magNED_z = this->sensor[11];
}

// Get_MagXYZ
void New_Sensor::Get_MagXYZ(float &magXYZ_x, float &magXYZ_y, float &magXYZ_z)
{
	magXYZ_x = this->sensor[12];
	magXYZ_x = this->sensor[13];
	magXYZ_x = this->sensor[14];
}

// Get_PosNE
void New_Sensor::Get_PosNE(float &posNE_x, float &posNE_y)
{
	posNE_x = this->sensor[15];
	posNE_y = this->sensor[16];
}

// Get_PosD
void New_Sensor::Get_PosD(float &posD)
{
	posD = this->sensor[17];	
}

// Get_Ret
void New_Sensor::Get_Ret(float &ret_q1, float &ret_q2, float &ret_q3, float &ret_q4)
{
	ret_q1 = this->sensor[18];
	ret_q2 = this->sensor[19];
	ret_q3 = this->sensor[20];
	ret_q4 = this->sensor[21];
}

// Get_Vel
void New_Sensor::Get_Vel(float &vel_x, float &vel_y, float &vel_z)
{
	vel_x = this->sensor[22];
	vel_y = this->sensor[23];
	vel_z = this->sensor[24];
}

// Get_Win
void New_Sensor::Get_Win(float &win_x, float &win_y)
{
	win_x = this->sensor[25];
	win_y = this->sensor[26];
}

// Get_Zbias
void New_Sensor::Get_Zbias(float &zbias)
{
	zbias = this->sensor[27];
}


void String_nCopy(char *src, char *dest, uint16_t start, uint16_t end)
{
	uint16_t i, j;
	dest[0] = '\0';
	j = 0;
	for(i=start; i<=end; i++)
	{
		dest[j++] = src[i];
	}
	dest[j] = '\0';
}

void Vir_Data(char *str)
{
	uint8_t i = 0;
	uint8_t j = 0;
	uint8_t sign = 0;
	str[0] = '\0';
	for(j=0; j<28; j++)
	{
		sign = rand()%2;
		if(sign==1)
		{
			str[i++] ='-';
		}
		str[i++] = '0';
		str[i++] = '.';
		str[i++] = rand()%10 + 48;
		if(j<27)
			str[i++] = ',';
	}
	str[i] = '\0';
}
