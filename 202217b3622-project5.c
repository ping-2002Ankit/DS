#include <stdio.h>

#define MAX_SIZE 5  // Define the maximum size of the queue

int queue[MAX_SIZE];
int front = -1, rear = -1;  // Initialize front and rear to -1 (empty queue)

// Function prototypes for better code organization
void Insertion(int data);
int Deletion();
void display();
int isFull();
int isEmpty();

int main() {
    int choice, data;

    printf("Queue Operations using Array\n");

    while (1) {
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to Insertion: ");
                scanf("%d", &data);
                if (isFull()) {
                    printf("Queue Overflow\n");
                } else {
                    Insertion(data);
                    printf("Data Insertiond successfully\n");
                }
                break;
            case 2:
                data = Deletion();
                if (isEmpty()) {
                    printf("Queue Underflow\n");
                } else {
                    printf("Deleted data: %d\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear; // Handle both cases for empty queue
}

// Function to add an element to the queue (Insertion)
void Insertion(int data) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = 0; // Initialize front if queue was empty
    }
    queue[++rear] = data;  // Increment rear after assignment to avoid overwrite
}

// Function to remove an element from the queue (Deletion)
int Deletion() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1; // Indicate error or a special value
    }

    int data = queue[front++];

    if (front > rear) { // Reset front and rear if queue becomes empty
        front = rear = -1;
    }

    return data;
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
