/*E3 Find number in matrix*/
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
/*一个糟糕的开始，会需要大量的时间绕弯弯，但弯弯也是能绕出来的*/
bool FindMatrix(int* m, int row, int col, int number)
{
	if(m == NULL)
		return false;
	if(row <= 0 || col <=0 )
		return false;
	int block[row*col];
	memset(block,0, row*col*sizeof(int));
	for(int i=0,j=0; i<row&&j<col;)
	{
		cout<<i<<" "<<j<<endl;
		int cur = m[i*col+j];
		if(cur == number)
			return true;
		else if(cur < number && j<col-1 && block[i*col+j+1] == 0 && m[i*col+j+1]<=number)
		{
			block[i*col+j]=1;			
			j++;
		}

		else if(cur < number && i<row-1 && block[i*col+j+col] == 0 && m[i*col+j+col]<=number)
		{
			
			block[i*col+j]=1;
			i++;
		}
		else if(cur < number && block[i*col+j+col] == 0 )
		{
			 block[i*col+j+col] = 1 ;
			 i++;
		}
		else if(cur > number && j > 0 && block[i*col+j-1] == 0 && m[i*col+j-1]<=number)
		{
			block[i*col+j-1]=1;
			j--;
		}
		else
		{
			return false;
		}
	}
	return false;
}
/*从左上角或右下角开始搜索，利用大小关系，删除完全小于或是完全大于的行和列，更体现这道题数字的特点*/ 
bool FindMatrix_del(int* m, int row, int col, int number)
{
	if(m == NULL)
		return false;
	if(row <= 0 || col <=0 )
		return false;
	for(int i=0,j=col-1;i<row,j>=0;)
	{
		int cur = m[i*col+j];
		if(cur == number)
		{
			return true;
		}
		else if(cur > number && j > 0 )
		{
			j--;
		}
		else if(cur < number && i < row-1)
		{
			i ++;
		}
		else
		{
			return false;
		}
	}
	return false;
}
int main()
{
	int m[16]={1,2,3,9,
	2,4,9,12,
	4,7,10,13,
	6,8,11,15};
	int aim = 0;
	while(1)
	{
			cin>>aim;
		if(FindMatrix_del(m,4,4,aim))
		//if(FindMatrix(m,4,4,aim))
			cout<<"Eurake, "<<aim<<" find!"<<endl;
		else
			cout<<"oh No, Not find "<<aim<<" !"<<endl;
	}

}
