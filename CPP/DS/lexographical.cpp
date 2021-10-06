#include<iostream>
#include<string.h>
#define ASCII_SIZE 256
using namespace std;

char func(char str[])
{ int count[ASCII_SIZE]={0};

int max=0;
char result;
	for(int  i =0;str[i];i++)
	{
	  ++count[str[i]];//count[str[i]] count of str[i] wwhich is count of s a m p l e	
    
	 if(max<count[str[i]])
     {
     max= count[str[i]];;
     result=str[i];
	 }
    
	}
	cout<<"count \t "<<max;
	return result;
	
}
int main()
{
	char str[]="sattte s";
	cout<<"max \t"<<func(str);
}
