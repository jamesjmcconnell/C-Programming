#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movieDefs.h"

/****************************************************
* List initializer function
****************************************************/
void dl_init(DblList* dlist){
	dlist->head = NULL;
	dlist->tail = NULL;
}

/****************************************************
* ADD NODE FUNCTION (Adds a movie into the list)
****************************************************/
void dl_add(DblList* dlist, Movie* newMovie){
	NodeType* newNode;
	NodeType* currNode;

	newNode = malloc(sizeof(NodeType));

	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = newMovie;

	currNode = dlist->head;

	//the above allocates memmory for a new node and sets all necessary variables to their
	//needed values in order for this function to work properly

	if(dlist->head == NULL){
		//empty case
		dlist->head = newNode;
		dlist->tail = newNode;
		printf("added first node in list\n");
	}else if(strcmp(dlist->head->data->title, newNode->data->title) > 0){
		//head case
		newNode->next = dlist->head;
		currNode->prev = newNode;
		dlist->head = newNode;
		printf("added to head\n");
	}else if(strcmp(dlist->tail->data->title, newNode->data->title) < 0){
		//tail case
		currNode = dlist->tail;
		newNode->prev = dlist->tail;
		currNode->next = newNode;
		newNode->next = NULL;
		dlist->tail = newNode;
		printf("added to tail\n");

	}else{
		// printf("hit else case\n");
		while(currNode != NULL){
			if(strcmp(currNode->data->title, newNode->data->title) > 0){
				// printf("breaking\n");
				break;
			}else{
				currNode = currNode->next;
				// printf("advancing node\n");
			}
		}
		//middle case
		currNode->prev->next = newNode;
		newNode->next = currNode;
		newNode->prev = currNode->prev;
		currNode->prev = newNode;
		printf("added to middle\n");		
	}

}

/****************************************************
* DEL NODE FUNCTION (removes a movie from the list)
****************************************************/
void dl_del(DblList* dlist, Movie* oldMovie){

	NodeType* currNode;
	currNode = NULL;

	if(dlist->head ==  NULL){
		//empty case
		printf("No movies in list!\n");
	}else if(dlist->head->next == NULL){
		//only case
		currNode = dlist->head; //have to assign currNode so next line doesnt seg fault
		free(currNode->data);
		free(currNode);
		dlist->head = NULL;
		dlist->tail = NULL;
		printf("the only node in the list has been deleted\n");
	}else if(strcmp(oldMovie->title, dlist->head->data->title) == 0){
		//head case
		currNode = dlist->head;
		currNode->next->prev = NULL;
		dlist->head = currNode->next;
		currNode->next = NULL;
		free(currNode->data);
		free(currNode);
		printf("deleted head\n");
	}else if(strcmp(oldMovie->title, dlist->tail->data->title) == 0){
		//tail case
		currNode = dlist->tail;
		currNode->prev->next = NULL;
		dlist->tail = currNode->prev;
		currNode->prev = NULL;
		free(currNode->data);
		free(currNode);
		printf("deleted tail\n");
	}else{
		// printf("hit else\n");
		currNode = dlist->head;
		while(currNode != NULL){
			// printf("hit while in delete\n");
			if(strcmp(currNode->data->title, oldMovie->title) == 0){
				//middle case
				currNode->next->prev = currNode->prev;
				currNode->prev->next = currNode->next;
				currNode->next = NULL;
				currNode->prev = NULL;
				free(currNode->data);
				free(currNode);
				printf("deleted middle node\n");
				return;
			}else{
				currNode = currNode->next;
			}
		}
	}
}
/****************************************************
* Print forward function
* Prints from head to the tail of the list
****************************************************/
void dl_printFwd(DblList* dlist){
	NodeType* currNode;
	if(dlist->head == NULL){
		printf("Nothing to print\n");
	}
	else{
		currNode = dlist->head;
		while(currNode != NULL){
			printf("%s\n", currNode->data->title);
			currNode = currNode->next;
		}
	}
}

/****************************************************
* Print backward function
* Prints from tail to the head of the list
****************************************************/
void dl_printBack(DblList* dlist){
	NodeType* currNode;
	if(dlist->head == NULL){
		printf("Nothing to print\n");
	}
	else{
		currNode = dlist->tail;
		while(currNode != NULL){
			printf("%s\n", currNode->data->title);
			currNode = currNode->prev;
		}
	}
}
/****************************************************
* Print by genre function
* Prints all movie in list by genre
****************************************************/

void dl_printByGenre(DblList *dlist, enum MovieGenre genre){
	NodeType* currNode;
	if (dlist->head == NULL){
		printf("Nothing to print");
	}
	else{
		currNode = dlist->tail;
		while(currNode != NULL){
			if(currNode->data->genre == genre){
				printf("%s\n", currNode->data->title);
				currNode = currNode->prev;
			}
			else{currNode = currNode->prev;}
		}
	}
}

/****************************************************
* CLEAN UP FUNCTION
* Cleans up all the memory in the program
****************************************************/

void dl_cleanup(DblList *dlist){
	NodeType* currNode;
	NodeType* temp;
	if (dlist->head == NULL){
		free(dlist);
		printf("EVERYTHING FREED\n");
	}
	else{
		currNode = dlist->head;
		while(currNode != NULL){
			temp = currNode;
			currNode = currNode->next;
			free(temp->data);
			free(temp);
		}
		free(dlist);
		printf("EVERYTHING FREED\n");
	}
}