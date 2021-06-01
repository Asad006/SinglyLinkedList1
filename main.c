#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
};

struct node *insert_beginning(struct node *head, int item);

struct node *insert_end(struct node *head, int item);

int numberOfListElements(struct node *head);

void displayElementsList(struct node *head);

int main() {

    // Head of the node Initialization.
    struct node *head = NULL;

    int k = 1;
    int element;

    printf("Linked list Menu!\n");
    while (k != 0) {
        printf("_____________________MENU_______________________");
        printf("\nOption 0: Enter '0' to exit the menu and the app.\n");
        printf("Option 1: Enter '1' to insert a node at the beginning.\n");
        printf("Option 2: Enter '2' to insert a node at the end.\n");
        printf("Option 3: Enter '3' to get the number of nodes in the list.\n");
        printf("Option 4: Enter '4' to print the elements of nodes in the list.\n");
        printf("________________________________________________\n");
        scanf("%d", &k);


        switch (k) {
            case 0:
                break;
            case 1:
                printf("Enter the value of the INFO:\n");
                scanf("%d", &element);
                head = insert_beginning(head, element);
                break;
            case 2:
                printf("Enter the value of the INFO:\n");
                scanf("%d", &element);
                head = insert_end(head, element);
                break;
            case 3:
                printf("The number of the elements in the list: %d\n", numberOfListElements(head));
                break;
            case 4:
                displayElementsList(head);
                break;
            default:
                printf("Invalid entry: please enter a value from the menu list.\n");

        }
    }
    return 0;
}

// Pre-
// post
struct node *insert_beginning(struct node *head, int item) {
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

    temp = (struct node *) malloc(sizeof(struct node));

    temp->info = item;
    temp->next = NULL;

    if (head == NULL)
        head = temp;
    else {
        n = head;
        while (n->next != NULL) {
            n = n->next;
        }
        n->next = temp;
    }
    return head;
}

int numberOfListElements(struct node *head) {
    int k = 0;
    struct node *temp;
    temp = head;
    if (temp == NULL) {
        return 0;
    } else {
        while (temp != NULL) {
            temp = temp->next;
            k++;
        }
        return k;
    }

}

void displayElementsList(struct node *head) {
    int k;

    struct node *temp;
    temp = head;

    if (temp == NULL) {
        printf("Empty list.\n");
    } else {
        while (temp != NULL) {
            printf("The element %d has a value of: %d\n", k, temp->info);

            temp = temp->next;
            k++;
        }
    }
}