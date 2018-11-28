#include <iostream>
using namespace std;
#include "DataFrame.h"
#include <string.h>

class DataExample{
	public: 
		char example_ack[50];
		
		DataExample()
		{
			uint8_t i = 0;
			for(i=0; i<50; i++)
				example_ack[i] = '\0';
			strcpy(example_ack, "\n\r74*C,A,1,042,,02.711532,NCA--$");
			//$--ACN,HHMMSS.SS,AAA,BBB,C,D,E*hh<CR><LF>
		}
		
		bool available()
		{	
			return strlen(example_ack)>0 ? 1 : 0; 	
		} 
		
		char read()
		{	
			char ch = example_ack[strlen(example_ack)-1];
			example_ack[strlen(example_ack)-1] = '\0';
			return ch;
		}
};



int main()
{
	DataExample example;	
	Frame frame;
	while(example.available())
	{
		char ch = example.read();
		frame.Catch(ch);	
	}
	
	frame.Info();	
	return 0;
}
