/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head==NULL)
	return -1;
	struct node *front = head, *back = head;
	struct node *temp = NULL;
	int flag, count = 0;
	float med;
	while (front)
	{
		if (front->next == NULL)
		{
			flag = 1;
			break;
		}
		else if (front->next->next == NULL)
		{
			flag = 0;
			break;
		}
		else
		{
			front = front->next->next;
			count++;
		}
	}
	while (count)
	{
		back = back->next;
		count--;
	}
	if (flag == 1)
	{
		return back->num;
	}
	else if (flag == 0)
	{
		temp = back;
		back = back->next;
		med = (temp->num + back->num) / 2;
		return med;
	}
}
