#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Step1: declare node type
struct node{
        int input;
        //point to the next node of the sequence
        struct node *next;
};

//comparador para bubble sort
int ascending(int a, int b) {
        return a > b;
}

//double pointer porque vamos a cambiar el head original
struct node *bubble_sort(struct node **head, int (*compare)(int,int)){
        int swapped;
        struct node *prev;
        struct node *curr;
        struct node *next_node;    
        next_node = NULL;

        if (*head == NULL || (*head)->next == NULL)
                return *head;

        do {
                swapped = 0;
                curr = *head;
                prev = NULL;

                while (curr->next != next_node) {
                        struct node *next = curr->next;

                        if (compare(curr->input, next->input)) {
                                // swap
                                curr->next = next->next;
                                next->next = curr;

                                if (prev == NULL)
                                        *head = next;
                                else
                                        prev->next = next;

                                prev = next;
                                swapped = 1;
                        } else {
                                prev = curr;
                                curr = curr->next;
                        }
                }
                next_node = curr;
        } while (swapped);

        return *head;
}

int main(){
        //initialize data members
        struct node *head = NULL;
        struct node *tail = NULL;
        struct node *pnode; //temporal pointer-> como la mano que chooses a las manzanas

        //step2: Create nodes and initialize members
        int count = 1;
        while(1){
                printf("Input data for node %d: ", count);
                pnode = (struct node*)malloc(sizeof(struct node));
                if (scanf("%d", &(pnode->input)) == EOF) break; //el input son las manzanas, so pnode ahora apunta a las manzanas

                //Step 3: Ensure next pointer of the last node is null
                pnode->next = NULL;

                //step 4: Link nodes on the list
                if(head == NULL) head = pnode;
                //El siguiente nodo después de tail ahora será pnode
                if(tail != NULL) tail->next = pnode;
                tail = pnode;
                count++;
        }

        //traverse it 
        //START FROM HEAD POINTER
        head = bubble_sort(&head, ascending);
        printf("Sorted list:\n");
        pnode = head;
        while(pnode != NULL){
                printf("Data = %d\n", pnode->input);
                pnode = pnode->next;
        }

        return 0;
}

