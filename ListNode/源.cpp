#include <iostream>
using namespace std;
#define ERROR -1
#define OK 1

//test git

struct ListNode {
	int val;
	bool isEmpty;
	ListNode* next;
	ListNode() :val(-1), next(NULL),isEmpty(true) {};//构造函数，把值初始化为-1，下一个节点为NULL
	ListNode(int myval) :val(myval), next(NULL),isEmpty(false) {};
	ListNode(int myval, ListNode* p) :val(myval), next(p),isEmpty(false) {};
};

int append(ListNode* p, int myval)//append to the end
{
	if (p->isEmpty == true)//judge weather listnode is empty
	{
		p->val = myval;
		p->isEmpty = false;
	}
	else 
	{
		while (p->next != NULL)//Move pointer to the end of ListNode
		{
			p = p->next;
		}
		ListNode* Nnode = new ListNode(myval);//create a new node with new val
		p->next = Nnode;//link new node to the old one
		return OK;
	}
	
}

int explore(ListNode* p)//show all
{
	if (p->isEmpty == true)
	{
		return OK;
	}
	else
	{
		while (p != NULL)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
		return OK;
	}
}

int insert(ListNode* p, int position, int myval)//insert after the no.position listnode
{
	for (int i = 1; i < position; i++)
	{
		if (p == NULL)//check if overflow
		{
			return ERROR;
		}
		else
		{
			p = p->next;
		}
	}
	ListNode* Nnode = new ListNode(myval, p->next);//create new one and the next is same with old one
	p->next = Nnode;//connect the new one with old one
}

int del(ListNode* p, int position)//delete node of no.position
{
	for (int i = 1; i < position - 1; i++)//move to the one before the target need to be deleted
	{
		if (p == NULL)//check if overflow
		{
			return ERROR;
		}
		else
		{
			p = p->next;
		}
	}

	if (p->next != NULL)
	{
		ListNode* target = p->next;
		p->next = p->next->next;
		delete(target);
	}
	return OK;




}

int reverse(ListNode*& p)
{
	if (p->isEmpty == true)
	{
		return ERROR;
	}
	ListNode* oldnext,* oldnext2;//to save the origin next pointer,and the next's next
	//oldnext是原本的下一个节点,next被动过 oldnext2是没有被动过的节点
	bool flag = false;//to labal the first one
	oldnext = p->next;//下一个节点
	oldnext2 = p->next->next;//没有被操作过的，下一个节点，保证持续向前推进
	while (p->next != NULL)
	{
		
		oldnext->next = p;
		if (flag == false)//第一个节点需要把指针的next设置为NULL
		{
			p->next = NULL;
			flag = true;
		}


		if (oldnext2->next != NULL)//下下个节点到头了
		{
			p = oldnext;//向前推进
			oldnext = oldnext2;
			oldnext2 = oldnext2->next;
		}
		else
		{
			break;
		}

	}
	oldnext2->next = oldnext;
	p = oldnext2;
	return OK;
}

int link(ListNode*& p1, ListNode* p2)
{
	ListNode* p = p1;
	while (p->next != NULL)
	{
		p = p -> next;
	}
	p->next = p2;
	return OK;
}




void main()
{
	ListNode* mynode = new ListNode;
	int temp;
	while (cin >> temp)
	{
		if (temp == -1)
		{
			break;
		}
		append(mynode, temp);
	}
	ListNode* mynode1 = new ListNode;
	while (cin >> temp)
	{
		if (temp == -1)
		{
			break;
		}
		append(mynode1, temp);
	}
	link(mynode, mynode1);
	explore(mynode);
	insert(mynode, 3, 20);
	explore(mynode);
	del(mynode, 4);
	explore(mynode);
	reverse(mynode);
	explore(mynode);
}