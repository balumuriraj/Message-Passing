/* thread.h
 * Contains helper function related to thread handling
 */
#include<stdlib.h>
#include"queue.h"
#define STACK_SIZE 8192

/* Head pointer to global queue element */
TCB_t *RunQ=NULL;

/* run(): To swap context of main thread with that at the queue head */
void run()
{
	ucontext_t parent;
	getcontext(&parent);
	swapcontext(&parent, &(RunQ->context)); 
}

/* start_thread(): Initialize queue with the function thread */
void start_thread(void (*function)(void))
{
	TCB_t *tcb_ptr;
	void *stack;
	stack = (int *)malloc(sizeof(char)*STACK_SIZE);
	tcb_ptr=(TCB_t *)malloc(sizeof(TCB_t));
	init_TCB(tcb_ptr, function, stack, STACK_SIZE);
	RunQ=(TCB_t*)add_q(RunQ,tcb_ptr);
}

/* yield(): Swap contexts of current thread with previous one in CPU */
void yield()
{
	RunQ=rotate_q(RunQ);
	swapcontext(&(RunQ->previous->context),&(RunQ->context));
}
