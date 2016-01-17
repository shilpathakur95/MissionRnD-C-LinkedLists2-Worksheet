/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head==NULL||K<=0)
	return NULL;
	struct node *current = head;
	int r = 1;
	while (current != NULL)
	{
		if (r == K)
		{
			struct node *newnode;
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = K;
			newnode->next = current->next;
			current->next = newnode;
			current = newnode->next;
			r = 1;
		}
		else
		{
			current = current->next;
			r++;
		}
	}
	return head;
}
