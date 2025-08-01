#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * next;
} node_one;


void add_value(node_one ** head, int val){
    node_one * new_node;
    new_node = (node_one *)malloc(sizeof(node_one));

    new_node->val = val;
    new_node->next = *head;

    *head = new_node;

}

void print_list(node_one * head){
    node_one * current = head;

    while(current != NULL){
        printf("%d->", current->val);
    
    current = current->next;
    }
    printf("NULL\n");

}

void pop(node_one ** head){

    int first_val = -1;

    node_one * node1 = NULL;

    if(*head == NULL){
        return -1;
    }

    node1 = (*head)->next;

    first_val = (*head)->val;

    free(*head);

    *head = node1;

    return first_val;

}

int main(){

    node_one * head = NULL;

    add_value(&head, 2);

    add_value(&head, 4);

    add_value(&head, 1);

    print_list(head);




    return 0;
}