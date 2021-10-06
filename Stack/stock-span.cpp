#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

// change size of stack from here
// change this char to int if
// you want to create stack of
// int. rest all program will work fine
typedef int stackentry;

typedef struct stack {
	stackentry entry[SIZE];
	int top;
} STACK;

// stack is initialized by setting top pointer = -1.
void initialiseStack(STACK* s) { s->top = -1; }

// to check if stack is full.
int IsStackfull(STACK s)
{
	if (s.top == SIZE - 1) {
		return (1);
	}
	return (0);
}

// to check if stack is empty.
int IsStackempty(STACK s)
{
	if (s.top == -1) {
		return (1);
	}
	else {
		return (0);
	}
}

// to push elements into the stack.
void push(stackentry d, STACK* s)
{
	if (!IsStackfull(*s)) {

		s->entry[(s->top) + 1] = d;
		s->top = s->top + 1;
	}
}

// to pop element from stack.
stackentry pop(STACK* s)
{
	stackentry ans;
	if (!IsStackempty(*s)) {
		ans = s->entry[s->top];
		s->top = s->top - 1;
	}
	else {
	
		// '\0' will be returned if
		// stack is empty and of
		// char type.
		if (sizeof(stackentry) == 1)
			ans = '\0';
		else
			// INT_MIN will be returned
			// if stack is empty
			// and of int type.
			ans = INT_MIN;
	}
	return (ans);
}

// The code for implementing stock
// span problem is written
// here in main function.
int main()
{
	// Just to store prices on 7 adjacent days
	int price[7] = { 100, 80, 60, 70, 60, 75, 85 };

	// in span array , span of each day will be stored.
	int span[7] = { 0 };
	int i;

	// stack 's' will store stock values of each
	// day. stack 'temp' is temporary stack
	STACK s, temp;

	// setting top pointer to -1.
	initialiseStack(&s);
	initialiseStack(&temp);

	// count basically signifies span of
	// particular day.
	int count = 1;

	// since first day span is 1 only.
	span[0] = 1;
	push(price[0], &s);

	// calculate span of remaining days.
	for (i = 1; i < 7; i++) {
	
		// count will be span of that particular day.
		count = 1;
	
		// if current day stock is larger than previous day
		// span, then it will be popped out into temp stack.
		// popping will be carried out till span gets over
		// and count will be incremented .

		while (!IsStackempty(s)
			&& s.entry[s.top] <= price[i]) {
			push(pop(&s), &temp);
			count++;
		}
		
		// now, one by one all stocks from temp will be
		// poped and pushed back to s.
		while (!IsStackempty(temp)) {
			push(pop(&temp), &s);
		}
	
		// pushing current stock
		push(price[i], &s);
	
		// appending span of that particular
		// day into output array.
		span[i] = count;
	}

	// printing the output.
	for (i = 0; i < 7; i++)
		printf("%d ", span[i]);
}
