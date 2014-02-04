/*
        DESCRIPTION: Implementation of a Linked List with four basic fuctions: push, pop, delete, size.
        AUTHOR: Shabhri Naresh
        EMAIL: shabhri.naresh@gmail.com
        VERSION: 2.0
*/

#include "list.h"
#include <stdio.h>


int list_push(int num, node **start)
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
				temp = temp->next;			
			}

			temp->next = pNode; // inserting the node at end of List
			printf("Node inserted successfully with value %d\n", num);
				
		}
		return 0;
	}

}


void list_pop(node **start)
{
	node *temp, *t;	

		if(*start==NULL){
			printf("List is empty cannot pop...\n");
			}		
		

		else{
			temp = *start;
			//t = temp->next;
			//traversing through the list
			while(temp->next->next!=NULL){
				//t=t->next;
				temp = temp->next;			
			}

			t = temp->next;
			temp->next = NULL;
			printf("A node with value %d is deleted\n", t->data);	
			free(t); //deallocation the node
				
		}
	

}




void list_delete(node **start)
{

	int len = list_length(start);
	
	int i;

	for(i=1;i<len; i++){
		list_pop(start);
	}
	
	
	node *temp;
	temp = *start;
	printf("A node with value %d is deleted\n", temp->data);
	*start = NULL;

	free(temp);
	
	

}


int list_length(node **start)
{
	node *temp;
	int count = 0 ;	

		if(*start==NULL){
			printf("List is empty so length is %d\n", count);
			}		
		

		else{
			temp = *start;

			//traversing through the list
			while(temp!=NULL){
				printf("\n %d \n " , temp->data);
				count++; //taking out length of the list. 
				temp=temp->next;
							
			}
			printf("length is %d \n",count);	
			
				
		}
	
		return count;
}


void list_add(node **start1, node **start2)
{
	node *temp;
	temp  = *start1;

	while(temp->next!=NULL){
		temp = temp->next;
	}

	temp->next = *start2;
	printf("Lists concatenated successfully..");

}

void list_to_array(node **start, int len)
{
	node *temp;
	temp = *start;
	int a[len];
	int i=0;


	while(temp!=NULL){
		a[i++] = temp->data;
		temp = temp->next;
	}

	printf("Array elemets are: ");
	for ( i = 0; i < (len); ++i){
		printf("%d\n", a[i]);
	}
}

void list_remove(node ** start, int item)
{
	node *first, *second, *temp;
	first = *start;
	second = first->next;
	int flag  = 0;

	if(first->data == item){
		*start = first->next;
		temp = first;
		free(temp);
		printf("No deleted with value = %d\n", item);
		flag = 1;
	}

	else{

		while(second!=NULL){

			if(second->data == item && second->next!=NULL){

				first->next = second->next;

				//temp = first->next;  Was not working with dis it was doing the next ka data = 0. Dont know why???
				temp  =second;
				free(temp);
				printf("No deleted with value = %d\n", item);
				flag = 1;
				break;
			}

			else if(second->data == item && second->next == NULL){

				first->next = NULL;
				temp = second;
				free(temp);
				printf("No deleted with value = %d\n", item);
				flag = 1;
				break;
			}

			first = first->next;
			second = second->next;
		}
	}

	if(flag==0){
		printf("No does not exists..\n");
	}


}

int search(node ** start, int elem)
{
	node * temp=*start;
	int flag=0;
	while(temp!=NULL){
		if(temp->data==elem){
			flag=1;
			printf("successfull search, %d found\n", elem);
			return flag;
			//break;
		}
		temp = temp->next;

	}
	if(flag==0){
		printf("%d not found\n", elem);
		return flag;
	}

}


