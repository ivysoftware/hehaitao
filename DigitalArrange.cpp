#include <iostream>
using namespace std;

void Print1ToMaxNDigitsRec(char* number,int length, int index, int* remains )
{
	if(index == length)
	{
		cout<<number<<endl;
		return;
	}
	for(int i=0; i<10; i++)
	{
		if (remains[i] == -1)
			continue;
		number[index] = remains[i]+'0';
		remains[i] = -1;
		Print1ToMaxNDigitsRec(number,length, index+1, remains);
		remains[i] = i; 
	} 
}
void Print1ToMaxNDigits(int n)
{
	if(n<=0)
		return;
	int charSequence[10];
	for(int i=0; i<10; i++)
	{
		charSequence[i] = i;
	}
	for(int i=0; i< 10; i++)
	{
		charSequence[i] = -1;
		char number[n];
		number[0] = i+'0';
		Print1ToMaxNDigitsRec(number,n, 1, charSequence);
		charSequence[i] = i; 
	}
}
void Print1ToMaxNDigitsRec(char* number,int length, int index, char* remains )
{
	if(index == length)
	{
		number[length]='\0';
		cout<<number<<endl;
		return;
	}
	for(int i=0; i<length; i++)
	{
		if (remains[i] == -1)
			continue;
		number[index] = remains[i];
		remains[i] = -1;
		Print1ToMaxNDigitsRec(number,length, index+1, remains);
		remains[i] = number[index]; 
	} 
}
void PrintArrange(char* src)
{
	if(src==0)
		return;
	int length = 0;
	char* p=src;
	while(*p != '\0')
	{
		p++;
		length++;		
	}
	cout<<length<<endl;
	for(int i=0; i<length; i++)
	{
		
		char pStr[length+1];
		pStr[0] = src[i];
		src[i] = -1;
		Print1ToMaxNDigitsRec(pStr,length, 1, src);
		src[i] = pStr[0]; 
	}
}
int main()
{
	/*
	int n;
	cin>>n;
	Print1ToMaxNDigits(n);
	*/

	char s[245];
	cin>>s;
	PrintArrange(s);	
}
