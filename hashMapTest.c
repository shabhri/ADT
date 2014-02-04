/*
DESCRIPTION: Implementation of a Hash Map with some basic fuctions: insert, delete, display, search.
AUTHOR: Shabhri Naresh
EMAIL: shabhri.naresh@gmail.com
VERSION: 1.0
*/

#include <stdio.h>
#include "list.h"
#include "hashMap.h"


int main()
{
	int array[15]={12, 34, 25, 86, 14, 10, 7, 5, 13, 16, 16, 16, 16, 1, 77};

	init();
	int i;
	for(i=0; i<15; i++){
		insert(array[i]);
	}

	display();

	/*searchHashMap(34);
	searchHashMap(10);
	searchHashMap(99);*/

	hashMap_delete(100);
	hashMap_delete(12);
	hashMap_delete(0);
	hashMap_delete(86);
	hashMap_delete(16);
	hashMap_delete(100);
	

	display();

	return 0;
}
