#include <stdio.h>
#define SIZE 5

void push(int arr[SIZE], int *top, int ele) {
    if (*top == SIZE - 1) {
        printf("Overflow\n");
    } else {
        (*top)++;
        arr[*top] = ele;
    }
}

int pop(int arr[SIZE], int *top) {
    if (*top == -1) {
        printf("Underflow\n");
        return 0;
    } else {
        int res = arr[*top];
        (*top)--;
        return res;
    }
}

void display(int arr[SIZE], int top) {
    if (top == -1) {
        printf("Empty stack\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int a[SIZE], ch, ele, top = -1, z = 1;

    while (z) {
        printf("Enter the choice:\n1. push\n2. pop\n3. display\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &ele);
                push(a, &top, ele);
                break;
            case 2:
                printf("Last item popped: %d\n", pop(a, &top));
                break;
            case 3:
                display(a, top);
                break;
            default:
                printf("Error occurred\n");
                break;
        }

        printf("Want to perform more operations? (1/0): ");
        scanf("%d", &z);
    }

    return 0;
}
