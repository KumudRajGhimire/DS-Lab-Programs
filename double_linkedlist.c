#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node* NODE;

NODE getNode(int data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->value = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

NODE insert_left_value(NODE first, int item, int key) {
    NODE new = getNode(item), current = first;
    if (first == NULL) {
        return new;
    }
    while (current != NULL && current->value != key) {
        current = current->next;
    }
    if (current != NULL && current->value == key) {
        new->next = current;
        new->prev = current->prev;
        if (current->prev != NULL) {
            current->prev->next = new;
        } else {
            first = new;
        }
        current->prev = new;
    } else {
        printf("Can't find the value\n");
    }
    return first;
}

NODE delete_value(NODE first, int key) {
    NODE current = first;
    if (first == NULL) {
        printf("Can't delete from empty list\n");
        return NULL;
    }
    while (current != NULL && current->value != key) {
        current = current->next;
    }
    if (current != NULL && current->value == key) {
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            first = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
    } else {
        printf("Value not found\n");
    }
    return first;
}

void display(NODE first) {
    NODE current = first;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void main() {
    NODE head = NULL;
    int ch, val, key;

    while (1) {
        printf("Enter choice:\n1. Insert at left of value\n2. Delete value\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the item and key: ");
                scanf("%d%d", &val, &key);
                head = insert_left_value(head, val, key);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                head = delete_value(head, val);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
        }
    }
}
