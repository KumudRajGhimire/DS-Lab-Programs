#include<stdio.h>
#include<stdlib.h>
//#include<alloc.h>

struct Node{
int data;
struct Node* next;
};

typedef struct Node* NODE;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
};

void insertFirst(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    if(*head==NULL){
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newNode;
}

void display(struct Node* head){
    struct Node* current = head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("NULL");
}

void sort(NODE first){
    int x;
    NODE temp1, temp2;
    //temp1=first;
    //temp2=temp1->next;

    for (temp1 = first; temp1 != NULL && temp1->next != NULL; temp1 = temp1->next){
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next){
            if((temp1->data)>(temp2->data)){
                x=temp1->data;
                temp1->data=temp2->data;
                temp2->data=x;
            }
            //temp2=temp2->next;
        }
        //temp1=temp1->next;
    }
}




NODE Reverse(NODE first){
    NODE current,temp;
    current = NULL;

    while(first!=NULL){
        temp=first;
        first=first->next;
        temp->next=current;
        current=temp;
    }
    return current;
}

NODE Concatenate(NODE first1, NODE first2){
    NODE last1;

    if(first1==NULL && first2==NULL){
        return NULL;
    }
    if(first1==NULL){
        return first2;
    }
    if(first2==NULL){
        return first1;
    }

    last1=first1;
    while(last1->next!=NULL){
        last1=last1->next;
    }

    last1->next=first2;

    return first1;
}



void main(){
    NODE head = NULL;
    NODE newhead = NULL;
    int ch;
    insertEnd(&head,10);
    insertEnd(&head,9);
    insertEnd(&head,100);
    insertEnd(&head,25);
    insertEnd(&head,13);
    insertEnd(&newhead,133);
    insertEnd(&newhead,134);
    insertEnd(&newhead,135);

    while(1){
        printf("\nEnter your choice: \n1.original\n2.sort\n3.reverse\n4.concatenate\n5.exit\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Original:\n");
                display(head);
                break;
            case 2:
                printf("\nSorted:\n");
                sort(head);
                display(head);
                break;
            case 3:
                printf("\nReverse:\n");
                display(Reverse(head));
                break;
            case 4:
                printf("\nConcatenated:\n");
                display(Concatenate(head,newhead));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}
