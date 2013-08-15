/*E11 binary tree to doublelink*/
#include <iostream>
#include <stack>
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
	if(root == NULL)
		return false;
	BSTNode* temp;
	stack<BSTNode*> nstack;
	nstack.push(root);
	while(1)
	{
		if(nstack.empty() == true)
			break;
		temp = nstack.top();
		nstack.pop();


		BSTNode* temp2 = temp->m_pLeft;
		temp->m_pLeft = temp->m_pRight;
		temp->m_pRight = temp2;			

		if(temp->m_pLeft)
			nstack.push(temp->m_pLeft);
		if(temp->m_pRight)
			nstack.push(temp->m_pRight);
		
	}
	return true;
}
void PrintBST(BSTNode* Root)
{
	if(Root == NULL)
		return;
	cout<<Root->m_nValue<<" ";
	PrintBST(Root->m_pLeft);
	PrintBST(Root->m_pRight);
	
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
	cout<<"Before Mirror:" <<endl;
	PrintBST(&Root);
	cout<<endl;
	cout<<"After Mirror:" <<endl;
	if(Mirror_Iter(&Root))
	{
		PrintBST(&Root);
	}
	return 0;
}
