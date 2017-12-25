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
#include <math.h>
#include "InstrUtils.h"
#include "Utils.h"

int isPowerOf2(int val){
	while(val != 1){
		if(val % 2 != 0)
			return 0;
		val = val / 2;
	}
	return 1; 
}


int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	/* YOUR CODE GOES HERE */
	Instruction *current = head;
	
	while (current != NULL){
		switch (current->opcode){
			case MUL:{
				if (current->prev->opcode == LOADI){
					Instruction *x = current->prev;
					if (isPowerOf2(x->field1)){
						current->opcode = LSHIFTI;
						current->field2 = 2;

						x->prev->next = current;
						current->prev = x->prev;
					}
					free(x);
				}
			}
			case DIV:{
				if (current->prev->opcode == LOADI){
					Instruction *x = current->prev;
					if (isPowerOf2(x->field1)){
						current->opcode = RSHIFTI;
						current->field2 = 2;
						x->prev->next = current;
						current->prev = x->prev;
					}
					free(x);
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

