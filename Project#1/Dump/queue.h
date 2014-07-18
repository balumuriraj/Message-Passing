/* queue.h
 * Contains helper functions related to queue handling
 */
#include<stdio.h>
#include<string.h>
#include"TCB.h"

/* Initialize the queue */
void init_q(TCB_t *queue)
{
	queue->next=queue;
	queue->previous=queue;
}

/* Add elements to the end of the queue */
TCB_t* add_q(TCB_t *head, TCB_t *item)
{
	TCB_t *temp;
	if(head==NULL)
	{
		init_q(item);
		head=item;
		return head;
	}
	temp=head;
	while(temp->next!=head)
		temp=temp->next;
	temp->next=item;
	item->previous=temp;
	item->next=head;
	head->previous=item;
	return head;
}

/* Delete first element of the queue */
TCB_t * del_q(TCB_t **head)
{
	TCB_t *temp;
	temp=(*head)->previous;
	if(temp==*head)
	{
		*head=NULL;
		return temp;
	}
	temp->next=(*head)->next;
	(*head)->next->previous=temp;
	temp=(*head);
	(*head)=(*head)->next;
	return temp;
}

/* Rotate the queue */
TCB_t* rotate_q(TCB_t *head)
{
	if(head==NULL)
	{
		printf("List is empty");
		return head;
	}
	head=head->next;
	return head;
}
