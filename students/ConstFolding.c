/*
 *********************************************
 *  314 Principles of Programming Languages  *
 *  Fall 2017                                *
 *  Author: Uli                              *
 *  Student Version                          *
 *********************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "InstrUtils.h"
#include "Utils.h"

int main()
{
	Instruction *head;
	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	/* YOUR CODE HERE */
	Instruction *current = head;
	while (current != NULL){
		switch (current->opcode){
			case ADD:{
				Instruction *x = current->prev->prev;
				Instruction *y = current->prev;
				if (x->opcode == LOADI && y->opcode == LOADI){
					//Fix current
					current-> opcode = LOADI;
					current->field1 = x->field1 + y->field1;
					current->field2 = current->field3;
					
					//fix links
					current->prev = x->prev;
					x->prev->next = current;

					free(x);
					free(y);
				}
			}	
			case SUB:{
				Instruction *x = current->prev->prev;
				Instruction *y = current->prev;
				if (x->opcode == LOADI && y->opcode == LOADI){
					//Fix current
					current-> opcode = LOADI;
					current->field1 = x->field1 - y->field1;
					current->field2 = current->field3;

					//fix links
					current->prev = x->prev;
					x->prev->next = current;

					free(x);
					free(y);
				}
			}
			case MUL:{
				Instruction *x = current->prev->prev;
				Instruction *y = current->prev;
				if (x->opcode == LOADI && y->opcode == LOADI){
					//Fix current
					current-> opcode = LOADI;
					current->field1 = x->field1 * y->field1;
					current->field2 = current->field3;

					//fix links
					current->prev = x->prev;
					x->prev->next = current;

					free(x);
					free(y);
				}
			}
		}
		current = current->next;
	}//end while
	

	if (head)
		PrintInstructionList(stdout, head);
	DestroyInstructionList(current);
	DestroyInstructionList(head);
	return EXIT_SUCCESS;
}

