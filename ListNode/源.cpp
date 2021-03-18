#include <iostream>
using namespace std;
#define ERROR -1
#define OK 1

//test git

struct ListNode {
	int val;
	bool isEmpty;
	ListNode* next;
	ListNode() :val(-1), next(NULL),isEmpty(true) {};//���캯������ֵ��ʼ��Ϊ-1����һ���ڵ�ΪNULL
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
	//oldnext��ԭ������һ���ڵ�,next������ oldnext2��û�б������Ľڵ�
	bool flag = false;//to labal the first one
	oldnext = p->next;//��һ���ڵ�
	oldnext2 = p->next->next;//û�б��������ģ���һ���ڵ㣬��֤������ǰ�ƽ�
	while (p->next != NULL)
	{
		
		oldnext->next = p;
		if (flag == false)//��һ���ڵ���Ҫ��ָ���next����ΪNULL
		{
			p->next = NULL;
			flag = true;
		}


		if (oldnext2->next != NULL)//���¸��ڵ㵽ͷ��
		{
			p = oldnext;//��ǰ�ƽ�
			oldnext = oldnext2;
			oldnext2 = oldnext2->next;
		}
		else
		{
			break;
		}

	}
	oldnext2->next = oldnext;
	p = oldnext2;//���һ���ڵ���ͷָ��
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

int selKing(int sum,int n)//����ѡ��������ʵ��
{
	ListNode* p = new ListNode;
	for (int i = 1; i <= sum; i++)//�����к���װ��������
	{
		append(p, i);
	}

	ListNode* q = p;//����һ�¿�ʼ�ĵ�ַ
	while (p->next != NULL)
	{

		p = p->next;


	}
	p->next = q;//����β��ͷ����
	p = p->next;//�ص���һ��

	while (1)
	{
		if (p->next == p)//����ֻʣ��һ���ˣ����˳�ѭ��
		{
			break;
		}
		else
		{
			for (int i = 1; i < n-1; i++)//ѭ��������n��ʱɾ����ǰ�ڵ�
			{
				p = p->next;
			}

			//��ǰ���һ���ڵ�ɾ��ȥ
			ListNode* pdel = p->next;
			p->next = p->next->next;
			delete(pdel);
			p = p->next;
		}
	}
	return p->val;

}

void main()
{
	int sum, n;
	cin >> sum >> n;
	cout << selKing(sum, n);
	/*cout<<selKing(17, 3);
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
	explore(mynode);*/
}