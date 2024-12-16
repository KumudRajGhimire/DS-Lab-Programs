#include <stdio.h>
#include <stdlib.h>

int *ht;   
int n, m;  
int count = 0;  

void insert(int key) {
    int index = key % m;  
    while (ht[index] != -1) {  
        index = (index + 1) % m;
    }
    ht[index] = key; 
    count++;
}

void display() {
    int i;
    if (count == 0) {
        printf("\nHash Table is empty\n");
        return;
    }
    printf("\nHash Table contents are:\n");
    for (i = 0; i < m; i++) {
        printf("T[%d] --> %d\n", i, ht[i]);
    }
}

int main() {
    int i, key;

    
    printf("Enter the number of employee records (N): ");
    scanf("%d", &n);

    
    printf("Enter the size of the hash table (m): ");
    scanf("%d", &m);

    
    ht = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        ht[i] = -1;  
    }

    
    printf("Enter the key values (4-digit integers) for %d employee records:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);

        
        if (count == m) {
            printf("Hash table is full. Cannot insert key %d\n", key);
            break;
        }
        insert(key);  
    }

    
    display();

    
    free(ht);
    return 0;
}
