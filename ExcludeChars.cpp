/*Exclude char*/
#include <iostream>
using namespace std;
bool ExcludeChars(char* src, char* excludechars){
	if(src == NULL)
		return false;
	if(excludechars == NULL)
		return true;
	char* pre = src;
	char* post = src;
	char chars[256];
	for(int i=0; i < 256; i ++){
		chars[i] = 0;
	} 
	for(char* pexclude=excludechars; *pexclude!= '\0' ; pexclude ++ ){
		chars[*pexclude] = 1;
	}
	/*
	int srclength = 0;
	for(; src[srclength] != '\0' ; srclength++) ;
	for(int i = 0; i < srclength + 1; i++ ){
		if()
	} */ // 到这里才意识到有指针这些代码都不需要了
	for(; *pre != '\0'; pre++){
		if(chars[*pre] != 1){
			*post = *pre;
			post++;
		}
	}
	*post = '\0';
	return true; 
}
void swap(int** a, int** b){
	int** v = a;
	a= b;
	b= a;
}
int main()
{
	/*char* 指针指向字符串的常量存储区，可修改指针指向地址，但修改内容是没有意义的*/
	//char* original = "they are student";
	//char* excludechars = "aeiou";
	char original[] = "they are student";
	char excludechars[] = "aeiou";
	ExcludeChars(original, excludechars);
	cout<<original<<endl;
	/* 
	delete[] original;
	delete[] excludechars;
	*/
	int i=1;
	int j = 2;
	int* a=&i;
	int* b=&j;
	swap(a,b);
	cout<<*a<<*b<<endl;
}
