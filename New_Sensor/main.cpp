#include <iostream>
#include <stdlib.h>
#include "New_Sensor.h"
using namespace std;

// module test

#include <time.h>

void delay(int delay)
{
	int now=time(NULL);
	int later=now+delay;
	while(now<=later)now=time(NULL);
}

//string Vir_Data()
//{
//	uint8_t i;
//	string str = "";
//	for(i=0; i<28; i++)
//	{
//		string tmp = "";
//		tmp += to_string(rand()%100);
//		tmp += ".";
//		tmp += to_string(rand()%100);
//		str += tmp;
//		if(i!=27)
//			str += ",";
//	}
//	return str;
//	/*
//		Example data:
//			41.67,34.0,69.24,78.58,62.64,5.45,81.27,61.91,95.42,27.36,91.4,2.53,92.82,21.16,
//			18.95,47.26,71.38,69.12,67.99,35.94,3.11,22.33,73.64,41.11,53.68,47.44,62.57,37.59
//	*/
//}

int main()
{
	new_sensor.Info();
	char a[]="";
	while(1)
	{
		Vir_Data(a);
		new_sensor.Get_DataFrame(a);
		new_sensor.Info();
		float euler_x, euler_y, euler_z;
		new_sensor.Get_Euler(euler_x, euler_y, euler_z);
		cout<<"Get euler: "<<euler_x<<" "<<euler_y<<" "<<euler_z<<endl<<endl;
		delay(1);
	}	
}

