#include<stdio.h>

void dfs(int, int *, int *);
int n, i, j, a[10][10], vis[10];
int isConnected = 1, isCyclic = 0;

void main() {
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }
    for (i = 1; i <= n; i++) {
        if (vis[i] == 0)
            dfs(i, &isConnected, &isCyclic);
    }
    for (i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            isConnected = 0;
            break;
        }
    }
    if (isConnected)
        printf("\nThe graph is connected");
    else
        printf("\nThe graph is not connected");
    if (isCyclic)
        printf("\nThe graph is cyclic\n");
    else
        printf("\nThe graph is not cyclic\n");
}

void dfs(int v, int *isConnected, int *isCyclic) {
    vis[v] = 1;
    char s[10] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    printf("%c ", s[v]);
    for (j = 1; j <= n; j++) {
        if (a[v][j] == 1) {
            if (vis[j] == 0) {
                dfs(j, isConnected, isCyclic);
            } else if (vis[j] == 1) {
                *isCyclic = 1;
            }
        }
    }
    vis[v] = 2;
}
