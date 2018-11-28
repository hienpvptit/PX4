#ifndef _DATA_FRAME_H_
#define _DATA_FRAME_H

#include <iostream>
using namespace std;

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define FR_HEADER_ACN "$--ACN"
#define FR_HEADER_ACK "$--ACK"
#define FR_HEADER_GGA "$--GGA"
#define FR_HEADER_GLL "$--GLL"
#define FR_HEADER_GST "$--GST"
#define FR_HEADER_RMC "$--RMC"
#define FR_HEADER_VHW "$--VHW"
#define FR_HEADER_VBW "$--VBW"
#define FR_HEADER_ZDA "$--ZDA"



class Frame{
	public:
		Frame();
		void Catch(char ch);
		void Info();
		
	private:
		char header[7];
		char content[100];
		char package[100];
		uint8_t checksum;
		uint8_t flag;
			// flag = 0 -> Disable
			// flag = 1 -> Enable to push data
			// flag = 2 -> Data split is ready
};

void String_nCopy(char *src, char *dest, uint16_t start, uint16_t end);

extern Frame frame;

#endif
