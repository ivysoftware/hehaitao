/*E09*/ 
#include <iostream>
using namespace std;
struct ListNode 
{
	int m_nKey;
	ListNode* m_pNext;
};
//�����������Ǵ���ģ���Ϊ�޷��жϲ����Ƿ���Ч��
//c++���õĵ�ַ�Ƿ���Ч���жϷ��� �������ڣ���Ϊ�����Ǳ�����˵����ֵʱ���Ѿ��ж����ڴ� 
//ListNode& FindReverseIndex(ListNode& Head, int k) 
ListNode* FindReverseIndex(ListNode* Head, int k)
{
	if (Head == NULL)
		return 0;
	
	ListNode* p1=Head;
	ListNode* p2=Head;
	int passNum = 0;
	while(p1->m_pNext != 0)
	{
		if(passNum > k-1)
		{
			p2 ++;
		}
		p1 ++;
		passNum ++;
	}
	if(passNum < k)
		return 0;
	return p2;
	
}

int main()
{
	ListNode a[6];
	a[5].m_nKey = 5;
	for (int i=4; i >= 0; i--)
	{
		a[i].m_nKey = i;
		a[i].m_pNext = &a[i+1];
	}
	ListNode* result = FindReverseIndex(a, 0);
	cout<<"result "<<result->m_nKey<<endl;
	return 0;
}
