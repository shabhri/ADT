/*
        DESCRIPTION: Implementation of a Hash Map with some basic fuctions: insert, delete, display, search.
        AUTHOR: Shabhri Naresh
        EMAIL: shabhri.naresh@gmail.com
        VERSION: 1.0
*/


#include <stdio.h>
#include "list.h"
#include "hashMap.h"
#include "list.c"

node * array[11];

void init()
{
	int i=0;
	while(i<11)
	{
		array[i++] = NULL;
	}
}
void insert(int elem)
{
	int j = elem%11;

	hashMap_push(elem, &array[j]);
}

void display()
{
	int i;

	for(i=0; i<=10; i++){

		printf("Displaying the map with index %d\n", i);
		list_length(&array[i]);
	}
}

int searchHashMap(int elem)
{
	int j = elem % 11;
	int i =search(&array[j], elem);
	return i;

}

int hashMap_push(int num, node **start)
{
	node *temp, *pNode;
	pNode = (node *)malloc(sizeof(node));
	
	if(pNode==NULL){
		return -1;	//memory allocation failure
	}
		else{
		pNode->data = num;
		pNode->next=NULL;

		if(*start==NULL){
			printf("List is empty now...bwdfh\n");
			*start = pNode;
			printf("first node  inserted successfully with value %d\n", pNode->data);			
		}

		else{
			temp = *start;
			
			//traversing through the list
			while(temp->next!=NULL){
				if(num==temp->next->data){
					printf("Cannot insert Duplicate...%d\n", num);
					return 1;
				}
				temp = temp->next;			
			}

			temp->next = pNode; // inserting the node at end of List
			printf("Node inserted successfully with value %d\n", num);
				
		}
		return 0;
	}

}

void hashMap_delete(int elem)
{
	int j;
	j=elem%11;
	list_remove(&array[j], elem);
}
