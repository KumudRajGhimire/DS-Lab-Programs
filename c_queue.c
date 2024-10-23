#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void insert(int *front, int *rear, int q[], int e) {

    if (*front == -1 && *rear == -1) {
        *front = *rear = 0;
        q[*rear] = e;
    }

    else if ((*rear + 1) % SIZE == *front) {
        printf("Overflow\n");
    }

    else {
        *rear = (*rear + 1) % SIZE;
        q[*rear] = e;
    }
}

void del(int *front, int *rear, int q[]) {

    if (*front == -1 && *rear == -1) {
        printf("Underflow\n");
    }

    else if (*front == *rear) {
        printf("%d is popped\n", q[*front]);
        *front = *rear = -1;
    }

    else {
        printf("%d is popped\n", q[*front]);
        *front = (*front + 1) % SIZE;
    }
}

void display(int *front, int *rear, int q[]) {

    if (*front == -1 && *rear == -1) {
        printf("Queue is empty\n");
    } else {
        int i = *front;
        printf("Items: ");
            while(i!= *rear){
                printf("%d ",q[i]);
                i = (i + 1) % SIZE;
            }
        }
        printf("%d\n",q[*rear]);
}

int main() {
    int front = -1, rear = -1;
    int q[SIZE];
    int ch;
    int e;

    while (1) {
        printf("Enter the choice:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &e);
                insert(&front, &rear, q, e);
                break;

            case 2:
                del(&front, &rear, q);
                break;

            case 3:
                display(&front, &rear, q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
