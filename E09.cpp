/*E09*/ 
#include <iostream>
using namespace std;
struct ListNode 
{
	int m_nKey;
	ListNode* m_pNext;
};
//这里用引用是错误的，因为无法判断参数是否无效。
//c++引用的地址是否有效的判断方法 ：不存在，因为引用是别名，说明赋值时候已经有对象内存 
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
