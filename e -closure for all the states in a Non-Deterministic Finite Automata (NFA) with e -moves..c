#include <stdio.h>
#define MAX 10

int nfa[MAX][MAX], closure[MAX][MAX], visited[MAX], n;
int i,j;
void epsilon_closure(int state) {
    visited[state] = 1;
    closure[state][state] = 1;
    for ( i = 0; i < n; i++) {
        if (nfa[state][i] && !visited[i]) {
            epsilon_closure(i);
            for ( j = 0; j < n; j++)
			 closure[state][j] |= closure[i][j];
        }
    }
}

int main() {
    printf("Enter the number of states: ");
    scanf("%d", &n);
    printf("Enter the epsilon-move matrix:\n");
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            scanf("%d", &nfa[i][j]);
    for ( i = 0; i < n; i++) { 
        for ( j = 0; j < n; j++) visited[j] = 0;
        epsilon_closure(i);
    }
    printf("Epsilon-closures:\n");
    for ( i = 0; i < n; i++) {
        printf("State %d: ", i);
        for ( j = 0; j < n; j++) 
		if (closure[i][j]) 
		printf("%d ", j);
        printf("\n");
    }
    return 0;
}

