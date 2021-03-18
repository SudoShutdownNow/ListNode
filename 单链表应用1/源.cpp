#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;
#define ERROR -1
#define OK 1

struct ListNode {
	int appearance;//number of appearance
	char word[15];//word
	bool isEmpty;
	ListNode* next;
	ListNode() :appearance(-1), next(NULL), isEmpty(true) {};//���캯������ֵ��ʼ��Ϊ-1����һ���ڵ�ΪNULL
};

ListNode* getNode(ListNode* p,char* myword)//����ĳ����λ�ã�������һ��ָ��
{
	for (ListNode* q = p; q!= NULL; q = q->next)//ѭ������
	{
		if (strcmp(myword, q->word) == 0)
		{
			return q;
		}
	}
	return NULL;
}

int addWord(ListNode*& p, char* myword)//��ӵ���
{
	ListNode* q = getNode(p, myword);
	if (q != NULL)//������������Ѿ�����
	{
		q->appearance += 1;//�Ǿ͸����ִ���+1
	}
	else//����������ﲻ����
	{
		q = p;
		if (q->isEmpty == true)//��������ǿյ�
		{
			strcpy(q->word, myword);
			q->appearance = 1;
			q->isEmpty = false;
			return OK;
		}

		if (strcmp(myword, q->word) == 0)//�����жϵ�һ�����Է�����ֻ��һ��Ԫ�أ������ѭ����������
		{
			q->appearance++;
			return OK;
		}

		if (p->next == NULL)//���ֻ��һ��Ԫ�صĻ�
		{
			ListNode* Nnode = new ListNode;
			strcpy(Nnode->word, myword);
			Nnode->isEmpty = false;
			Nnode->appearance = 1;

			Nnode->next = NULL;
			q->next = Nnode;
			return OK;
		}


		if (strcmp(myword, q->word) < 0)//����ȵ�һ��С����Ҫ׷������ǰ��
		{
			ListNode* Nnode = new ListNode;
			strcpy(Nnode->word, myword);
			Nnode->isEmpty = false;
			Nnode->appearance = 1;

			Nnode->next = q;
			p = Nnode;
			return OK;
		}

		for (q = p; q->next != NULL; q = q->next)
		{

			//if (strcmp(myword, q->next->word) < 0)
			if (strcmp( q->next->word, myword) > 0)//��ѭ������һ�������ֵ�˳��ȵ�ǰ���ʴ�ʱ
			{
				ListNode* Nnode = new ListNode;
				strcpy(Nnode->word, myword);
				Nnode->isEmpty = false;
				Nnode->appearance = 1;

				Nnode->next = q->next;
				q->next = Nnode;
				return OK;
			}
		}
		//�����ͷ�˶�û�ҵ��ֵ�˳��ȵ�ǰ���ʴ�ģ��Ǿ�������ĩβ���ϵ�ǰ�ĵ���
		if (q->next != NULL)
		{
			q = q->next;
		}
		ListNode* Nnode = new ListNode;
		strcpy(Nnode->word, myword);
		Nnode->isEmpty = false;
		Nnode->appearance = 1;

		Nnode->next = NULL;
		q->next = Nnode;
	}
}

int explore(ListNode* p)//�������нڵ�
{
	for (ListNode* q = p; q != NULL; q = q->next)
	{
		cout << q->word << ": " << q->appearance << endl;
	}
	return OK;
}

int delWord(ListNode*& p, char* myword)//���ݵ���ɾ���ڵ�
{
	ListNode* q = p;
	if (strcmp(myword, q->word) == 0)//���Ŀ�굥���ڵ�һλ������
	{
		p = q->next;
		delete(q);
		return OK;
	}
	for ( q = p; q->next != NULL; q = q->next)
	{
		if (strcmp(myword, q->next->word) == 0)
		{
			ListNode* i = q->next;
			q->next = q->next->next;
			delete(i);
			return OK;
		}
	}
	return ERROR;
}

ListNode* findMost(ListNode* p)//�ҵ���ǰ���ִ������ĵ��ʲ��������ڽڵ�ָ��
{
	ListNode* res = NULL;
	int now = 0;
	for (ListNode* q = p; q != NULL; q = q->next)
	{
		if (q->appearance > now)
		{
			now = q->appearance;
			res = q;
		}
	}
	return res;
}

int main()
{
	ListNode* mynode = new ListNode;
	char word[15];

	cin >> word;//��������һ������

	while (cin >> word)
	{
		if (strcmp(word, "`") == 0)
		{
			break;
		}
		addWord(mynode, word);
	}

	//explore(mynode);

	ListNode* biggest;//���ڴ洢���ִ������Ľڵ�ָ��
	for (int i = 1; i <= 3; i++)
	{
		biggest = findMost(mynode);

		if (*biggest->word >= 'A'&& *biggest->word <='Z')//�����д�д��ĸ������
		{
			i--;
			delWord(mynode, biggest->word);
			continue;
		}

		cout << biggest->word << " " << biggest->appearance << " ";
		delWord(mynode,biggest->word);

		//cout << endl;
		//explore(mynode);
	}

}