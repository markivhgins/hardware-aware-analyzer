#include <stdlib.h>
#include <stdio.h>

#include "../include/algorithms.h"

typedef struct Node{
    int value;
    struct Node* next;
}Node;

void run_linkedlist(int size){
    Node *head=NULL;
    Node *current=NULL;

    for(int i=0; i<size; i++){
        Node *new_node=(Node*)malloc(sizeof(Node));


        if(new_node==NULL){
        Node *temp=head;
        while(temp!=NULL){
            Node *next = temp->next;
            free(temp);
            temp=next;
        }
        return;
    }

    new_node->value=i;
    new_node->next=NULL;

    if(head==NULL){
        head = new_node;
        current = new_node;
    } else{
        current->next = new_node;
        current = new_node;
    }
}

    long long sum = 0;
    Node *temp = head;

    while(temp != NULL){
        sum+=temp->value;
        temp=temp->next;
    }

    volatile long long dummy = sum;
    (void) dummy;

    temp=head;
    while(temp!=NULL){
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
}