/*FindMin*/ 
#include <iostream>
using namespace std;
int FindMin(int* array, unsigned int n)
{
	if(array == NULL || n== 0)
		return -1;
	int* start = array;
	int* end = array+n-1;
	while(*start > *end) // ²»ÄÜÓÃstart<end!!!! 
	{
		if(end - start == 1){
			return *start<*end?*start:*end;
		}
		int* middle = start + (end-start)/2;
		if(*middle - *start >= 0)
			start = middle;
		else
			end = middle;
	}
	return *start;
}

int main()
{
	int  arr[] ={12,14,0,1,2,3};
	cout<<FindMin(arr, 5)<<endl;
}
