#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};
bool hasCycle(struct Node *head) {
    struct Node **visited = (struct Node **)calloc(100, sizeof(struct Node *));
    int size = 100;

    while (head != NULL) {
        int key = ((unsigned long)head) % size;

        if (visited[key] == head) {
            free(visited);
            return true;
        }

        visited[key] = head;
        head = head->next;
    }

    free(visited);
    return false;
}
int main() {
    // Creating linked list: 1 → 2 → 3 → 4 → 2 
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node *)malloc(sizeof(struct Node));
    n1->data = 1; n1->next = n2;
    n2->data = 2; n2->next = n3;
    n3->data = 3; n3->next = n4;
    n4->data = 4; n4->next = n2; // Loop back to node 2
    // Check loop
    if (hasCycle(n1))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}