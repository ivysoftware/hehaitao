/*IsStraightFlush 是否为顺子*/
#include <iostream>
using namespace std;
bool IsStraightFlush(int* array, unsigned int n){
	if(array == NULL || n == 0)
		return false;
	int array_count[13];
	for(int i = 0; i < 13; i++){
		array_count[i] = 0;
	}
	
	for(int i = 0; i< n; i++){
		array_count[array[i]] ++;
	}
	int zero_num = array_count[0];  // 写完程序后，如果需要调试，先确定每个变量定义、初始化、赋值的正确 
	bool isStart = false;
	int StraightLength = 0;
	for(int i = 1; i < 13; i++){
		if(StraightLength == n)
			return true;
		if(array_count[i] > 0 && isStart == false){
			isStart = true;
			StraightLength ++;
			continue;
		} else if(isStart == true && array_count[i] == 0){
			if(zero_num>0){
				zero_num --;
				StraightLength ++;
			}else{
				return false;
			}
		}else if(isStart == true && array_count[i] > 0){
			StraightLength ++;
		}
		
	}
	if(StraightLength < n )
		return false;
	else return true;
	
}
int main(){
	int array[] = {5,2,4,0,0};
	bool status = IsStraightFlush(array, 5);
	if(status)
		cout<<"is straight flush" << endl;
	else
		cout<<"not straight flush" << endl;
}
