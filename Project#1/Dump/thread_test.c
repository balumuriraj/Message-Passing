/* Distributed and Multiprocessor Operating System
 * Project1
 * Tema Members: Shardul Mangade, Moheet Bhute.
 */

#include"thread.h"

/*Infinite funtion for simulation */
void function1()
{
	int j=0;
	while(1)
	{
		j++;
		printf("%d ",j);
		if(j%7==0)
		{
			yield();
			printf("\n\nNow in %s\n", __func__);
		}
	}
}

/*Infinite funtion for simulation */
void function2()
{
	int i=0;
	while(1)
	{
		i++;
		printf("%d ",i);
		if(i%9==0)
		{
			yield();
			printf("\n\nNow in %s\n", __func__);
		}
	}
}

/*Infinite funtion for simulation */
void function3()
{
	int i=0;
	while(1)
	{
		i++;
		printf("%d ",i);
		if(i%5==0)
		{
			yield();
			printf("\n\nNow in %s\n", __func__);
		}
	}
}

void main()
{
	start_thread(function1);
	start_thread(function2);
	start_thread(function3);
	run();

}
