/* TCB.h
 *  Contains basic TCB strucuture and initialization routine
 */
#include<stdio.h>
#include<ucontext.h>
#include<string.h>

/* Strucutre for Thread Control Block */
typedef struct TCB
{
	struct TCB *next;
	struct  TCB *previous;
	ucontext_t context;
}TCB_t;

/* init_TCB(): Initialize the contents of TCB
 * tcb: Pointer to target tcb
 * associated_function: function pointer to the function being to be executed
 * stack_pointer: stack pointer for the function
 * stack_size: limit for the stack
 */
void init_TCB(TCB_t *tcb, void *(associated_function), void *stack_pointer, int stack_size)
{
	memset(tcb, '\0', sizeof(TCB_t));
	getcontext(&tcb->context);
	tcb->context.uc_stack.ss_sp=stack_pointer;
	tcb->context.uc_stack.ss_size=(size_t)stack_size;
	makecontext(&tcb->context, associated_function, 0);
}
