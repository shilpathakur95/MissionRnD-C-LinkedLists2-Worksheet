/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
void find(struct node *head);
struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head==NULL)
	return NULL;
	struct node *temp2 = head;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	find(head);
	head = temp2;
	return head;
}
void find(struct node *head)
{
	struct node *temp = head;
	struct node *prev = NULL;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	if (prev != NULL)
	{
		temp->next = prev;
		prev->next = NULL;
		find(head);
	}
	else
		temp->next = prev;
}