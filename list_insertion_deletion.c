#include<stdio.h>
#include<stdlib.h>
//#include<alloc.h>

struct Node{
int data;
struct Node* next;
};


struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
};

void insertAtFirst(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data){
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

void insertAtPosition(struct Node** head, int data, int position){
    if(position==0){
        insertAtFirst(head,data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;

    for(int i=0;i<position-1&&current!=NULL;i++){
        current=current->next;
    }

    if(current==NULL){
        printf("position exceeds length of list\n");
        free(newNode);
        return;
    }

    newNode->next = current -> next;
    current -> next = newNode;
}

void deleteFirst(struct Node** head){
    if(*head==NULL){
        printf("List empty\n");
        return;
    }
    struct Node* temp =*head;
    *head= (*head)->next;
    free(temp);
}

void deleteLast(struct Node** head){
    if(*head==NULL){
        printf("List Empty");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        return;
    }
    struct Node* second_last=*head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }
    free(second_last->next);
    second_last->next=NULL;
}

void deleteElement(struct Node** head, int key){
    struct Node* current = *head;
    struct Node* previous = NULL;
    if(current!=NULL && current->data==key){
        *head = current -> next;
        free(current);
        return;
    }

    while(current!=NULL && current->data!=key){
        previous = current;
        current = current -> next;
    }
    if(current==NULL){
        printf("Element not found");
        return;
    }
    previous->next = current ->next;
    free(current);
}


void display(struct Node* head){
    struct Node* current = head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("NULL");
}

void main(){
struct Node* head = NULL;
int ch,e,i;
    while(1){

            printf("\n\nMenu\n1.Insert at first\n2.Insert at end\n3.Insert at index\n4.Delete first\n5.Delete last\n6.Delete anywhere\n7.Display\n8.Exit\n");
            scanf("%d",&ch);


            switch(ch){
                case 1:
                    printf("Enter element to insert: ");
                    scanf("%d",&e);
                    insertAtFirst(&head,e);
                    break;
                case 2:
                    printf("Enter element to insert: ");
                    scanf("%d",&e);
                    insertAtEnd(&head,e);
                    break;
                case 3:
                    printf("Enter element to insert: ");
                    scanf("%d",&e);
                    printf("Enter index to insert at: ");
                    scanf("%d",&i);
                    insertAtPosition(&head,e,i);
                    break;
                case 4:
                    printf("Element at first deleted!\n");
                    deleteFirst(&head);
                    break;
                case 5:
                    printf("Element at last deleted!\n");
                    deleteLast(&head);
                    break;
                case 6:
                    printf("Enter element to delete: ");
                    scanf("%d",&e);
                    deleteElement(&head,e);
                    break;
                case 7:
                    display(head);
                    break;
                case 8:
                    exit(0);
                default:
                    printf("Invalid choice");

            }
    }
}
