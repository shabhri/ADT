#include "list.h"
#include <stdio.h>


int main() //execution starts here
{
	int i ;
	//node start = (node *)malloc(sizeof(node));
	
	struct node *start =NULL;

	list_length(&start);
	//Inserting 5 nodes in Linked List at end
	for(i=1; i<=6; i++){

		int t = list_push(i, &start);
		if(t==0){
			printf("Node inserted successfully\n");	
			
		}
		else if(t==-1){
			printf("Unable to allocate memory to Node!!\n");
		}
	}
	
	int len = list_length(&start);
	list_pop(&start);
	list_pop(&start);
	//list_pop(&start);
	//len = list_length(&start);
	list_delete(&start);
	len = list_length(&start);
	
	return 0 ;
}

