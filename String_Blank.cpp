/*2013.7.12*/
#include <iostream>
#include <cstring>
using namespace std;

bool ReplaceBlank (char* src)
{
	if(src == NULL)
		return false;
	
	int len=0;
	for(;src[len]!='\0'; len++)
		; 
	if(len == 1)
		return false;
		
	int blankNum = 0;
	for(int i=0;i<len; i++)
	{
		if(src[i] == ' ')
			blankNum ++;
	}	
	int j = len + 2*blankNum - 1;
	for(int i=len-1; i >=0; i--)
	{
		if( j == i )
		{
			break;
		}
		if(src[i] == ' ')
		{
			src[j--] = '0';
			src[j--] = '2';
			src[j--] = '%';
		}
		else
			src[j--] = src[i];
	}
}
int main()
{
	char src[5] ;//���Ҫ���ַ����Ƚϴ󣬷Ų�����ô�죿 
	gets(src); // ��ʹ����ܳ���srcҲ����ȷ��������ַ� 
	ReplaceBlank(src);
	cout<<src<<endl;
	
}
