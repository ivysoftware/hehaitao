/*n length digital*/
#include <iostream>
using namespace std;

void printDigital(char* digital, unsigned int n){
	bool isStart = true;
	for(int i=0 ; i < n ; i ++){
		if(digital[i] != '0' ){
			isStart = false;
			cout << digital[i];
		}else if( ! isStart ){
			cout << digital[i];
		}		
	}
	cout<<endl;
} 
void outputDigitalRecur(unsigned int n , unsigned int index, char* digital){
	if(index == n){
		printDigital(digital, n);
		return;
	}
	for(int i = 0; i < 10; i++){
		digital[index] = '0' + i;
		outputDigitalRecur(n, index+1, digital);
	}
}
bool outputDigital(unsigned int n){
	if(n == 0){
		return false;
	}
	char* digital = new char[n];
	for(int i = 0; i < 10; i ++){
		digital[0] = '0' + i;
		outputDigitalRecur(n, 1, digital);
	}
	delete[] digital;
}
int main(){
	unsigned int n;
	cin>>n;
	outputDigital(n);
}
