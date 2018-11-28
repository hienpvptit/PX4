#include "DataFrame.h"

Frame frame;

// Frame Init
Frame::Frame()
{
	uint8_t i;
	for(i=0; i<7; i++)
		this->header[i] = '\0';
	for(i=0; i<100; i++)
	{
		this->package[i] = '\0';
		this->content[i] = '\0';
	}
	this->flag = 0;
	this->checksum = 0;
}

// Catch Frame
void Frame::Catch(char ch)
{
	if(ch=='$')
		this->flag = 1;		// Start catch package
		
	if(ch=='\n')
	{
		this->flag = 2;		// End catch package => Data split is ready
	}
	
	if(this->flag==1)		// Receive package
	{
		this->package[strlen(this->package)] = ch;
	}
	
	if(this->flag==2)		// Split data
	{	
		uint8_t i;
		uint8_t len = strlen(this->package);
		char tmp_str[10];
		uint8_t start = 0;
		
		// Get checksum;
		for(i=0; i<10; i++)
			tmp_str[i] = '\0';
		for(i=len-1; i>0; i--)
		{
			if(this->package[i]=='*')
			{
				this->package[i] = '\0';
				break;
			}
				
			if(this->package[i]=='\r') 
				continue; // pass
			
			tmp_str[strlen(tmp_str)] = this->package[i];
			this->package[i] = '\0';
		}
		strrev(tmp_str);
		this->checksum = atoi(tmp_str); 		// return checksum
		
		// Get Header and content
		len = strlen(this->package);
		for(i=0; i<len; i++)
		{
			if(this->package[i]==',')
			{
				String_nCopy(this->package, tmp_str, start, i-1);
				if(start==0)
				{
					strcpy(this->header, tmp_str);
					String_nCopy(this->package, this->content, i+1, len);
				}
				start = i+1;
				cout<<tmp_str<<endl;
			}
		}
		if(start<len-1)
		{
			String_nCopy(this->package, tmp_str, start, len);
			cout<<tmp_str<<endl;
		}
		this->flag = 0;
	}	
}


//
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


// 
void Frame::Info()
{
	cout<<endl<<endl<<"Frame Info:"<<endl;
	cout<<"flag: "<<(int)this->flag<<endl;
	cout<<"package: "<<this->package<<endl;	
	cout<<"header: "<<this->header<<endl;
	cout<<"content: "<<this->content<<endl;
}
