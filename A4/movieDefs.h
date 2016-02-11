#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ARR_SIZE 32 
#define MAX_STR_SIZE 16 

enum MovieGenre {
	COMEDY,
	DRAMA,
	THRILLER,
	ACTION
};

typedef struct{
	char title[MAX_STR_SIZE];
	enum MovieGenre genre;
	int year;
	char cast[MAX_ARR_SIZE][MAX_ARR_SIZE];
}Movie;

typedef struct Node{
	Movie* data;
	struct Node* next;
	struct Node* prev;	
}NodeType;

typedef struct{
	NodeType* head;
	NodeType* tail;
}DblList;