#ifndef _LIST_H
#define _LIST_H //define _LIST_H if its not defined.

typedef struct node node;



struct node
{
        int data;
        node * next;
};



int list_push( int, node **); //Compulsory!

void list_pop(node **); //Compulsory!
void list_delete(node **); //Compulsory! This will delete the list. Be careful while freeing the memory.
int list_length(node **); //Compulsory! Returns the length of the list.
void list_add(node **, node **);
void list_to_array(node **, int);
void list_remove(node **, int);
int search(node **, int);

#endif

