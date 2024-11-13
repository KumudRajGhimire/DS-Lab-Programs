#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* NODE;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List Empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* second_last = *head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void push(NODE* head, int e) {
    insertAtFirst(head, e);
}

void pop(NODE* head) {
    deleteFirst(head);
}

void enqueue(NODE* head, int e) {
    insertAtFirst(head, e);
}

void dequeue(NODE* head) {
    deleteLast(head);
}

void main() {
    NODE stack = NULL;
    NODE queue = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display Stack\n4. Enqueue\n5. Dequeue\n6. Display Queue\n7. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                printf("Stack: ");
                display(stack);
                break;
            case 4:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 5:
                dequeue(&queue);
                break;
            case 6:
                printf("Queue: ");
                display(queue);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
