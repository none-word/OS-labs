#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int value;
};

void print_list(struct node *head) {
    
    struct node *currentNode;
    currentNode = head -> next;
    
    while (currentNode != NULL) {
        
        printf ("%d ", currentNode -> value);
        currentNode = currentNode -> next;
        
    }
    printf ("\n");
    
}

void insert_node(struct node *head, struct node *newNode, struct node *previousNode) {
    
    struct node *currentNode;
    currentNode = head;
    
    while (currentNode != previousNode) {
        currentNode = currentNode -> next;
    }
    
    
    newNode -> next = currentNode -> next;
    currentNode -> next = newNode;
    
}

void delete_node(struct node *head, struct node *deleteNode) {
    
    struct node *currentNode;
    currentNode = head;
    
    while (currentNode -> next != deleteNode) {
        currentNode = currentNode -> next;
    }
    
    currentNode -> next = currentNode -> next -> next;
    
}

int main()
{
    
    struct node head;
    head.next = NULL;
    
    struct node node1;
    struct node node2;
    struct node node3;
    struct node node4;
    
    node1.value = 1;
    node2.value = 2;
    node3.value = 3;
    node4.value = 4;

    node1.next = NULL;
    node2.next = NULL;
    node3.next = NULL;
    node4.next = NULL;
    
    insert_node(&head, &node1, &head);
    insert_node(&head, &node2, &node1);
    insert_node(&head, &node3, &node2);
    insert_node(&head, &node4, &node3);

    print_list(&head);
    delete_node(&head, &node2);
    
    print_list(&head);
    delete_node(&head, &node1);
    
    print_list(&head);
    delete_node(&head, &node4);

    print_list(&head);

    return 0;
}
