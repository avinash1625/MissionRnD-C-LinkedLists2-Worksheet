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
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1==NULL&&head2==NULL)
		return NULL;
	struct node* head3 = NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	if (head1->num <= head2->num){

		head3 = head1;

		head3->next = merge2LinkedLists(head2, head1->next);
	}
	else{

		head3 = head2;

		head3->next = merge2LinkedLists(head1, head2->next);
	}
	return head3;
}

