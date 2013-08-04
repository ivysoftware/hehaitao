/*Rebuild binary Tree by preorder and midorder*/ 
#include <iostream>
#include <stdexcept>
using namespace std;
struct BinaryTreeNode;
typedef BinaryTreeNode BTN;
struct BinaryTreeNode
{	
	int value;
	BTN* left;
	BTN* right;
}; 
void postorder_output(BTN* root)
{
	if(root == NULL)
		return;
	postorder_output(root->left);
	postorder_output(root->right);
	cout<<root->value<<" ";
}
BTN* RebuildRecursive(int* preorder, int* preorderend, 
					  int* midorder, int* midorderend)
{
	if(preorder == NULL || preorderend == NULL || preorder == NULL || preorderend == NULL )
		throw  runtime_error("Original Invalid input");
	BTN* root = new BTN();
	root->value = *preorder;
	//1. ֻ��һ���ڵ� 
	if(preorder == preorderend)
	{
		//cout<<root->value<<endl; 
		return root;
	} 
	//2. ����һ���ڵ� 
	int* rootpos = midorder;
	for(;rootpos < midorderend && *rootpos!=root->value; rootpos++) 
		;
	if(rootpos == midorderend && *rootpos != root->value)
		throw runtime_error("Invalid input");
	int length = rootpos - midorder; //ָ��֮��ľ���ֱ��������� 
	//cout<<root->value<<" "<<length<<endl;
	if(rootpos > midorder)
	{
		root->left = RebuildRecursive(preorder+1, preorder+length, midorder, midorder+length-1);
		//cout<<root->value<<"\tleft is "<< root->left->value <<endl;
	}
	if(rootpos < midorderend)
	{
		root->right = RebuildRecursive(preorder+length+1, preorderend, midorder+length+1, midorderend);
		//cout<<root->value << "\tright is "<<root->right->value<<endl;
	}
	return root;
}
//���ʵ�����β�������ͬ����Ҫ��&��ʾ���� �������� 
//Ҫ�ı�һ��ָ��ָ�����ݵ�ֵ����Ҫ��&���ţ������� 
bool Rebuild(int* preorder, int* midorder, unsigned int length, BTN*& root)
{
	if(preorder == NULL || midorder==NULL || length == 0)
		return false;
	root = RebuildRecursive(preorder, preorder+length-1, midorder, midorder+length-1);
	//postorder_output(root);
	return true;
	
}

int main()
{
	int preorder[]={1,2,4,7,3,5,6,8};
	int midorder[] = {4,7,2,1,5,3,8,6};
	BTN* treeroot;
	if (Rebuild(preorder, midorder, 8, treeroot))
	{
		cout<<"the postorder is "<<endl;
		postorder_output(treeroot);
		cout<<endl;
	}
}
