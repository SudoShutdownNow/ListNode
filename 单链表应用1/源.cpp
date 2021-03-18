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
	ListNode() :appearance(-1), next(NULL), isEmpty(true) {};//构造函数，把值初始化为-1，下一个节点为NULL
};

ListNode* getNode(ListNode* p,char* myword)//查找某单词位置，并返回一个指针
{
	for (ListNode* q = p; q!= NULL; q = q->next)//循环查找
	{
		if (strcmp(myword, q->word) == 0)
		{
			return q;
		}
	}
	return NULL;
}

int addWord(ListNode*& p, char* myword)//添加单词
{
	ListNode* q = getNode(p, myword);
	if (q != NULL)//如果在链表里已经存在
	{
		q->appearance += 1;//那就给出现次数+1
	}
	else//如果在链表里不存在
	{
		q = p;
		if (q->isEmpty == true)//如果链表是空的
		{
			strcpy(q->word, myword);
			q->appearance = 1;
			q->isEmpty = false;
			return OK;
		}

		if (strcmp(myword, q->word) == 0)//单独判断第一个，以防链表只有一个元素，下面的循环不起作用
		{
			q->appearance++;
			return OK;
		}

		if (p->next == NULL)//如果只有一个元素的话
		{
			ListNode* Nnode = new ListNode;
			strcpy(Nnode->word, myword);
			Nnode->isEmpty = false;
			Nnode->appearance = 1;

			Nnode->next = NULL;
			q->next = Nnode;
			return OK;
		}


		if (strcmp(myword, q->word) < 0)//如果比第一个小，需要追加在最前面
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
			if (strcmp( q->next->word, myword) > 0)//当循环到下一个单词字典顺序比当前单词大时
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
		//如果到头了都没找到字典顺序比当前单词大的，那就在链表末尾加上当前的单词
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

int explore(ListNode* p)//回显所有节点
{
	for (ListNode* q = p; q != NULL; q = q->next)
	{
		cout << q->word << ": " << q->appearance << endl;
	}
	return OK;
}

int delWord(ListNode*& p, char* myword)//根据单词删除节点
{
	ListNode* q = p;
	if (strcmp(myword, q->word) == 0)//解决目标单词在第一位的问题
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

ListNode* findMost(ListNode* p)//找到当前出现次数最多的单词并返回所在节点指针
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

	cin >> word;//舍弃掉第一个输入

	while (cin >> word)
	{
		if (strcmp(word, "`") == 0)
		{
			break;
		}
		addWord(mynode, word);
	}

	//explore(mynode);

	ListNode* biggest;//用于存储出现次数最多的节点指针
	for (int i = 1; i <= 3; i++)
	{
		biggest = findMost(mynode);

		if (*biggest->word >= 'A'&& *biggest->word <='Z')//把所有大写字母都扔了
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