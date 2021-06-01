#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
};

struct node *insert_beginning(struct node *head, int item);

struct node *insert_end(struct node *head, int item);

int main() {

    // Head of the node Initialization.
    struct node *head = NULL;

    int k = 1;
    int resp;
    int element;

    printf("Linked list Menu!\n");
    while (k != 0) {
        printf("Option 0: Enter '0' to exit the menu and the app:\n");
        printf("Option 1: Enter '1' to insert a node at the beginning:\n");
        scanf("%d", &k);


        switch (k) {
            case 1:
                printf("Enter the value of the INFO:\n");
                scanf("%d", &element);
                insert_beginning(head, element);
                break;
            default:
                printf("Invalid entry: please enter a value from the menu list>\n");

        }
    }
    return 0;
}

// Pre-
// post
struct node *insert_beginning(struct node *head, int item) {
    struct node *n;
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->info = item;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else {
        temp->next = head;
        head = temp;
    }
    return head;

}

struct node *insert_end(struct node *head, int item) {
    struct node *n;
    struct node *temp;
    temp->info = item;
    temp->next = NULL;
    temp = (struct node *) malloc(sizeof(struct node));
    if (head == NULL)
        head = temp;
    else {
        n = head;
        while (n->next != NULL) {
            n=n->next;
        }
        n->next=temp;
    }
    return head;
}