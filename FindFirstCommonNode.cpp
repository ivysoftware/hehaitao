/*Find first common node*/
#include<iostream>
using namespace std;
struct LinkNode{
	int value;
	LinkNode* next;
};
LinkNode* FindFirstCommonNode(LinkNode* aHead, LinkNode* bHead){
	if(aHead == NULL || bHead == NULL){
		return NULL;
	}
	if(aHead == bHead)
		return aHead; //head common
	int aLen = 0;
	//for(; (aHead+aLen)!=NULL; aLen++)  ERROR!!!
	//for(LinkNode* p; p->next!=NULL; aLen++, p=p->next) ;  //p û�г�ʼ������ 
	for(LinkNode* p=aHead; p->next!=NULL; aLen++, p=p->next) ;
	aLen ++;
	
	int bLen = 0;
	for(LinkNode* p=bHead; p->next!=NULL; bLen++, p=p->next) ;
	bLen ++;
	
	LinkNode* commonNode = NULL;
	LinkNode* aStart = aHead;
	LinkNode* bStart = bHead;
	int distance = 0;
	//aStart += aLen - bLen  ERROR !!!!
	if(aLen > bLen){
		distance = aLen - bLen;
		for(int i = 0; i < distance; aStart = aStart->next, i++) ;
	}		
	else{
		distance = bLen - aLen;
		for(int i = 0; i < distance; bStart = bStart->next, i++) ;
	}
	/* �ð汾�ɼ� 
	//ԭ��һ�����ϵģ�����a=0 1 2; b= -2��-1,0,1,2	
	if(aStart == bStart)
		return aStart;
		
	for(; aStart->next != bStart->next; aStart=aStart->next, bStart=bStart->next) ; //����ֱ��һ����λ�𣿣��� 
	
	return aStart->next;
	*/
	for(; aStart!=NULL && bStart!= NULL && aStart!=bStart; aStart=aStart->next, bStart=bStart->next) ;
	
	return aStart;	
	
}
void printLink(LinkNode* Head){
	for(; Head->next!=NULL; Head=Head->next){
		cout<<Head->value<<" ";
	}
	cout<<endl;
}
int main(){
	//LinkNode* aHead;
	LinkNode aHead ;//= {0,0}; //Link������Ҫһ���Ѿ��г�ʼλ�õ�ͷָ�� 
	//aHead->value = 0; 
	LinkNode* pa = &aHead;
	for(int i = 0; i< 10; i++){
		pa->value = i;
		pa->next = new LinkNode(); //���������ã������� pa = new LinkNode(); ������ָ���ǶϿ��� 		
		pa = pa->next;
	}
//	cout<<"check link a";
//	cout<<aHead.value<<" " << aHead.next->value<<endl;
	
	cout<<"first array construst ok!"<<endl;
	LinkNode bHead ;//= {8, 0}; //Link������Ҫһ���Ѿ��г�ʼλ�õ�ͷָ�� 
	LinkNode* pb = &bHead;
	for(int i = 8; i < 10; i++){
		pb->value = i;
		pb->next = new LinkNode();
		pb = pb->next;
	}
	LinkNode* p = &aHead;	
	for( int i = 0; i < 0; p=p->next, i++ ) ; 
	pb->next = p; // ��Ҫ�ҹ��ĵط�һ��Ҫ��next 
	//pb = &aHead + 6;  // too young too simple
	cout<<"second array construst ok!"<<endl;
	printLink(&aHead);
	printLink(&bHead);
	cout<<FindFirstCommonNode(&aHead, &bHead)->value<<endl;	
}
