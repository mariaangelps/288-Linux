#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Step1: declare node type
struct node{
        int input;
       //char name[20];
       //pount to the next node of the sequence
       	struct node *next;
	//struct node *reverse_head;
};

int main(){
//initialize data members
struct node *head =NULL;
struct node *tail=NULL;
struct node *pnode; //temporal pointer-> como la mano que chooses a las manzanas
struct node *rpnode;
struct node *next_node;
struct node *reverse_head=NULL;


//step2: Create nodes and initialize members
int count=1;
while(1){
		
	printf("Input data for node %d: ",count);
	pnode = (struct node*)malloc(sizeof(struct node));
	if (scanf("%d",&(pnode->input)) == EOF) break;//el input son las mnanzas, so pnode ahora apunta a las manzanas
	
	//pnode = (struct node*)malloc(sizeof(struct node));
	
	//Step 3: Ensure next pointer of the last node is null

	pnode->next=NULL;
	
	//step 4: Link nodes on the list
	if(head==NULL) head=pnode;
	//El siguiente nodo después de tail ahora será pnode
	if(tail!=NULL) tail->next=pnode;
	tail=pnode;
	count++;


}


//traverse it 
//START FROM HEAD POINTER
pnode =head;
 printf("\nData entered in the list are:\n");
while(pnode !=NULL){
        //printf("\nData entered in the list are:\n");
	printf("Data = %d \n",pnode->input);
        pnode=pnode->next;

}



//reverse 
//mientras no se llegue al final de la lista 
//head -> [5] -> [6] -> [7] -> NULL
//revrse ->  [7] -> [6] -> [5] -> NULL

rpnode=head;
while(rpnode != NULL){
	//el siguiente nodo despues del curent que estamos visitando va a ser el next
	next_node = rpnode->next;
	rpnode->next=reverse_head;
	reverse_head=rpnode;
	rpnode=next_node;
}

pnode = reverse_head;
 printf("\nThe list in reverse are: \n");
while(pnode !=NULL){
	printf("\n");
	//printf("\nThe list in reverse are: \n");
	printf("Data = %d",pnode->input);
	//rpnode->next = reverse_head;
	pnode =pnode->next;

printf("\n");
}

}
