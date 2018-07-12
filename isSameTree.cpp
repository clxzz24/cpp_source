#include <iostream>
using namespace std;

struct Tree
{
	int val;
	Tree* left;
	Tree* right;
};

Tree* createTree(int a[]);
Tree* createTreeNode(int val);
void connectTreeNode(Tree* pParent, Tree* pLeft, Tree* pRight);
bool isSameTree(Tree* pHead1, Tree* pHead2);
bool isSubTree(Tree *pHead1, Tree* pHead2);
bool isSubTreeCore(Tree* pHead1, Tree* pHead2);

Tree* createTree(int a[])
{

}

Tree* createTreeNode(int val)
{
	Tree* pNode = new Tree();
	pNode->val = val;
	pNode->left = nullptr;
	pNode->right = nullptr;
	return pNode;
}

void connectTreeNode(Tree* pParent, Tree* pLeft, Tree* pRight)
{
	if(pParent != nullptr)
	{
		pParent->left = pLeft;
		pParent->right = pRight;
	}
}

bool isSameTree(Tree* pHead1, Tree* pHead2)
{
	bool res;
	if(pHead1 == nullptr && pHead2 == nullptr)
		return true;
	if(pHead1 == nullptr)
		return false;
	if(pHead2 == nullptr)
		return false;
	if(pHead2->val != pHead1->val)
		return false;
	res = isSameTree(pHead1->left, pHead2->left) && isSameTree(pHead1->right, pHead2->right);
	return res;
}

bool isSubTree(Tree *pHead1, Tree* pHead2)
{
	bool res = false;
	if(pHead2 == nullptr)
		return true;
	if(pHead2 != nullptr && pHead1 == nullptr)
		return false;
	if(pHead1->val == pHead2->val)
	{
		res = isSubTreeCore(pHead1, pHead2);
	}
	if(!res)
		res = isSubTree(pHead1->left,pHead2);
	if(!res)
		res = isSubTree(pHead1->right,pHead2);
	return res;
}

bool isSubTreeCore(Tree* pHead1, Tree* pHead2)
{
	if(pHead1 == nullptr)
		return false;
	if(pHead2 == nullptr)
		return true;
	if(pHead1->val != pHead2->val)
		return false;
	return isSubTreeCore(pHead1->left, pHead2->left) && isSubTreeCore(pHead1->right, pHead2->right);
}

int main()
{

}