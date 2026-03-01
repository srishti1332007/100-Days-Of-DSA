#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || k == 0) return head;

    struct Node *temp = head;
    int n = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    k = k % n;   // Handle k > n
    if (k == 0) return head;

    // Make circular
    temp->next = head;

    int steps = n - k;
    struct Node* newTail = head;

    // Move to new tail
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Function to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, x, k;

    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* newNode = createNode(x);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}