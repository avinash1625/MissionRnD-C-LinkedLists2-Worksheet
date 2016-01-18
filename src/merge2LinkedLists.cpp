/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};
struct node *insert(struct node *start, int data)
{
	struct node *p, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->num = data;
	if (start == NULL)
	{
		tmp->next = start;
		start = tmp;
		return start;
	}
	else  
	{
		p = start;
		while (p->next != NULL)
			p = p->next;
		tmp->next = p->next;
		p->next = tmp;
	}
	return start;
}

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1==NULL&&head2==NULL)
		return NULL;
	struct node *head3=NULL;
	while (head1!= NULL && head2!= NULL)
	{
		if (head1->num < head2->num)
		{
			head3 = insert(head3, head1->num);
			head1 = head1->next;
		}
		else if (head2->num< head1->num)
		{
			head3= insert(head3, head2->num);
			head2 = head2->next;
		}
		else if (head1->num == head2->num)
		{
			head3 = insert(head3, head1->num);
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	while (head1 != NULL)
	{
		head3 = insert(head3, head1->num);
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		head3 = insert(head3, head2->num);
		head2 = head2->next;
	}
	return head3;
}

