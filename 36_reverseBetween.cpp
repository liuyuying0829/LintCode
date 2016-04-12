/*
36 ��ת���� II

��ת�����е�m���ڵ㵽��n���ڵ�Ĳ���

ע������
m��n����1 �� m �� n �� ������

����
��������1->2->3->4->5->null�� m = 2 ��n = 4������1->4->3->2->5->null

��ս
��ԭ��һ�η�ת���
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(NULL){}
};

class Solution {
public:
	/**
	* @param head: The head of linked list.
	* @param m: The start position need to reverse.
	* @param n: The end position need to reverse.
	* @return: The new head of partial reversed linked list.
	*/
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		// write your code here
		if (head == NULL || head->next == NULL)
		{
			return head;
		}//if

		int count = 1;
		ListNode *pre = NULL, *p = head;
		while (p && count < m)
		{
			pre = p;
			p = p->next;
			++count;
		}//while

		ListNode *minHead = p, *minEnd = minHead, *r = p->next;
		minHead->next = r;
		while (p && count <= n)
		{
			r = p->next;
			p->next = minHead;
			minHead = p;

			p = r;
			++count;
		}//while

		if (pre != NULL)
		{
			pre->next = minHead;
		}//if   
		else
		{
			head = minHead;
		}//else

		minEnd->next = r;
		return head;
	}
};

ListNode *insert(ListNode *head, int val)
{
	if (!head)
		head = new ListNode(val);
	else{
		ListNode *p = head;
		while (p->next)
			p = p->next;
		p->next = new ListNode(val);
	}//else
	return head;
}

void display(ListNode *head)
{
	if (!head)
		cout << endl;
	else{
		ListNode *p = head;
		while (p->next)
		{
			cout << p->val << "��>";
			p = p->next;
		}//while
		cout << p->val << endl;
	}//else
}


int main()
{
	ListNode *head = NULL;
	for (int i = 0; i < 10; ++i)
		head = insert(head, i);
	display(head);
	Solution s;
	head = s.reverseBetween(head,1,1);
	display(head);

	system("pause");
	return 0;
}