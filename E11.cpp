/*E11*/
#include <iostream>
using namespace std;
struct BSTNode
{
	int m_nValue;
	BSTNode* m_pLeft;
	BSTNode* m_pRight;
}; 
bool Mirror_Recur(BSTNode* root)
{
	if( root == NULL )
	{
		return false;
	}
	if(root->m_pLeft != NULL)
	{
		Mirror_Recur(root->m_pLeft);
	}
	if(root->m_pRight != NULL)
	{
		Mirror_Recur(root->m_pRight);
	}
	BSTNode* temp = root->m_pLeft;
	root->m_pLeft = root->m_pRight;
	root->m_pRight = temp;
	return true;
}
bool Mirror_Iter(BSTNode* root)
{
	while(1)
	{
		
	}
}
int main()
{
	BSTNode leaf1 = {5, 0, 0};
	BSTNode leaf2 = {7, 0, 0};
	BSTNode leaf3 = {9, 0, 0};
	BSTNode leaf4 = {11, 0, 0};
	
	BSTNode p_12 = {6, &leaf1, &leaf2};
	BSTNode p_34 = {10, &leaf3, &leaf4};
	BSTNode Root = {8, &p_12, &p_34};
	if(Mirror_Recur(&Root))
	{
		PrintBST(&Root);
	}
	return 0;
}
