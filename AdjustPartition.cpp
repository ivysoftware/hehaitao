/*奇数放于偶数前，负数放于非负数前*/
#include <iostream>
using namespace std;
bool isOdd(int value)
{
	return (value & 1) == 1 ? true : false ; 
} 
bool isNegative(int value)
{
	return value < 0 ? true : false;
}
void Adjust(int* array, unsigned int n, bool (*isBefore)(int))
{
	if (array==NULL || n == 0)
		return;
	int* pBegin = array;
	int* pEnd = array + n - 1;
	while(pEnd > pBegin)
	{
		if (isBefore(*pBegin)) pBegin++;
		else if(!isBefore(*pEnd)) pEnd--;
		else{
			/*
			*pBegin = *pBegin | *pEnd;
			*pEnd = *pBegin & (~*pEnd) ;
			*pBegin = *pBegin & (~*pEnd);
			*/
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}
int main()
{
	int array[]={3,8,6,5,2,1};
	Adjust(array, 6, isOdd);
	for(int i = 0; i < 6; i++ )
	{
		cout<<array[i]<<endl;
	}
} 
