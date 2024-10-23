#include<stdio.h>
#define SIZE 5

void insert(int *front, int *rear, int q[], int e){
    if(*rear==SIZE-1){
        printf("Overflow");
    }
    else{
        q[++(*rear)]=e;
    }
}

int del(int *front, int *rear, int q[]){
    if(*front>*rear){
        printf("Underflow");
        return -1;
    }
    else{
        return ((q[(*front)++]));
    }
}

void display(int *front, int *rear, int q[]){
    if(*rear == -1){
        printf("Empty");
    }
    else{
        printf("Items: ");
        for(int i = *front; i<=*rear; i++){
            printf("%d ",q[i]);
        }
    }
}

void main(){
    int q[SIZE];
    int front = 0;
    int rear = -1;

    int ch;
    int e;

    while(1){
        printf("\nMenu:\n1.Insert\n2.Delete\n3.Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
               printf("Enter the element: ");
               scanf("%d",&e);
               insert(&front,&rear,q,e);
               break;
            case 2:
                if(del(&front,&rear,q)==-1)
                {

                }
                else
                printf("%d is deleted.\n",del(&front,&rear,q));
                break;
            case 3:
                display(&front, &rear, q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
                break;
        }
    }

}
