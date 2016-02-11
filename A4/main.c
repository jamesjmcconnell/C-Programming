#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.c"

int main(){
	DblList* dlist;
	dlist = (DblList *) malloc(sizeof(DblList));
	dlist->head = (NodeType *) malloc(sizeof(NodeType*));
	dlist->tail = (NodeType *) malloc(sizeof(NodeType*));
	dl_init(dlist);

	int x = 0;//just made a random variable to have an infinite while loop
	while (x == 0){
		int y;//this represents the user choice, used effectively like a switch case

		printf("888       888        888                                      \n");
		printf("888   o   888        888                                      \n");
		printf("888  d8b  888        888                                      \n");
		printf("888 d888b 888 .d88b. 888 .d8888b .d88b. 88888b.d88b.  .d88b.  \n");
		printf("888d88888b888d8P  Y8b888d88P    d88  88b888  888  88bd8P  Y8b \n");
		printf("88888P Y8888888888888888888     888  888888  888  88888888888 \n");
		printf("8888P   Y8888Y8b.    888Y88b    Y88..88P888  888  888Y8b.     \n");
		printf("888P     Y888  Y8888 888  Y8888P  Y88P  888  888  888  Y8888  \n");
		printf("\n");
		printf("1. Add a movie\n");
		printf("2. Remove a movie\n");
		printf("3. Print movies\n");
		printf("4. Exit the program\n");
		scanf("%d", &y);
		/************************************************************************
		*GOES INTO ADD MENU
		************************************************************************/
		while(y == 1){//WHILE ADDING
			Movie* movie = (Movie *) malloc(sizeof(Movie));
			movie->year = 0;
			int g;
			int yy;
			char *title;
			
			printf("Enter title to add\n");
			scanf("%15s", title); //15s so i dont get a buffer overflow
			strcpy(movie->title, title);

			printf("Choose a genre\n");
			printf("1. COMEDY\n");
			printf("2. DRAMA\n");
			printf("3. THRILLER\n");
			printf("4. ACTION\n");
			scanf("%d", &g);

			if (g == 1){movie->genre = COMEDY;}
				else if (g == 2){movie->genre = DRAMA;}
				else if (g == 3){movie->genre = THRILLER;}
				else if (g == 4){movie->genre = ACTION;}
				else{
					printf("Invalid choice\n");
					free(movie);
					continue;
				}
			dl_add(dlist, movie);
			printf("Enter 0 to add more or 1 to get out\n");
			scanf("%d", &yy);
			if(yy == 1){
				y = 0;
			}

		}
		/************************************************************************
		*GOES INTO DELETE MENU
		************************************************************************/
		while(y == 2){//WHILE DELETING
			int yy;
			char title[16];
			Movie* movie = (Movie *) malloc(sizeof(Movie));

			printf("Enter title to remove\n");
			scanf("%15s", &title); 
			strcpy(movie->title, title);

			dl_del(dlist, movie);
			free(movie);

			printf("Enter 0 to remove more or 1 to get out\n");
			scanf("%d", &yy);
			if(yy == 1){
				y = 0;
			}
		}
		/************************************************************************
		*GOES INTO PRINT MENU
		************************************************************************/
		while(y == 3){//WHILE PRINTING
			int yy;
			int g;

			printf("1. Print Forward\n");
			printf("2. Print backward\n");
			printf("3. Print by genre\n");
			printf("4. EXIT\n");
			scanf("%d", &yy);

			if( yy == 1){dl_printFwd(dlist);

			}else if (yy == 2){dl_printBack(dlist);

			}else if (yy == 3){
				printf("Please choose a GENRE to print\n");
				printf("1. COMEDY\n");
				printf("2. DRAMA\n");
				printf("3. THRILLER\n");
				printf("4. ACTION\n");
				scanf("%d", &g);
				if (g == 1){dl_printByGenre(dlist, COMEDY);}
				else if (g == 2){dl_printByGenre(dlist, DRAMA);}
				else if (g == 3){dl_printByGenre(dlist, THRILLER);}
				else if (g == 4){dl_printByGenre(dlist, ACTION);}
				else{printf("Incorrect choice");}

			}else{
				y = 0;
				printf("Exiting...");
			}
		}
		while(y == 4){//USER SELECTED EXIT
			dl_cleanup(dlist);
			printf("Goodbye! \n");
			x = 1; //exit the outermost while loop thereby returning and exiting the main
			break;

		}

	}
	return 0;
}