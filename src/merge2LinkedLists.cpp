/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL&&head2 == NULL)
		return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node *current = head1;
	struct node *head = NULL;
	struct node *prev = NULL;
	struct node *current2 = head2;
	struct node *prev2 = head2;
	while (current != NULL&&current2 != NULL)
	{
		if (current->num >= current2->num)
		{
			if (prev == NULL)
			{
				head1 = current2;
			}
			else
			{
				prev->next = current2;
			}
			prev2 = current2->next;
			current2->next = current;
			prev = current;
			current = head1;
			current2 = prev2;
		}
		else if (current->num < current2->num)
		{
			prev = current;
			current = current->next;
		}
		//display(head1);
	}
	if (current2 != NULL)
	{
		prev->next = current2;
	}
	return head1;
}
