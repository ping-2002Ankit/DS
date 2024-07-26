#include <stdio.h>
#define MAX 10

// Structure to represent a node in the list
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Function prototypes
Node* createList();
void insertAtBeginning(Node** head, int data);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, int data);
void displayList(Node* head);

int main() {
  int ch, data, pos;
  Node* head = NULL;  // Initialize an empty list

  do {
    printf("\n Main Menu");
    printf("\n 1.Create List \n 2.Insert at Beginning \n 3.Insert at End \n");
    printf("\n 4.Delete \n 5.Display\n 6.Exit \n");
    printf("\n Enter your Choice: ");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        head = createList();
        break;
      case 2:
        printf("\n Enter element to insert: ");
        scanf("%d", &data);
        insertAtBeginning(&head, data);
        break;
      case 3:
        printf("\n Enter element to insert: ");
        scanf("%d", &data);
        insertAtEnd(&head, data);
        break;
      case 4:
        printf("\n Enter element to delete: ");
        scanf("%d", &data);
        deleteNode(&head, data);
        break;
      case 5:
        displayList(head);
        break;
      case 6:
        exit(0);
      default:
        printf("\n Enter the correct choice:");
    }
    printf("\n Do you want to continue (y/n)? ");
    scanf(" %c", &ch); // Read the character with a space to avoid issues with newline
  } while (ch == 'y' || ch == 'Y');

  return 0;
}

// Function to create an empty list
Node* createList() {
  return NULL; // An empty list has head pointing to NULL
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
    return;
  }

  // Traverse to the last node
  Node* temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Function to delete a node with a given value
void deleteNode(Node** head, int data) {
  if (*head == NULL) {
    printf("\n List is empty!");
    return;
  }

  Node* temp = *head, *prev;

  // Special case: Delete the head node
  if (temp->data == data) {
    *head = temp->next;
    free(temp);
    return;
  }

  // Traverse the list to find the node to delete
  while (temp != NULL && temp->data != data) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("\n Element not found!");
    return;
  }

  // Delete the node
  prev->next = temp->next;
  free(temp);
}

// Function to display the list contents
void displayList(Node* head) {
  if (head == NULL) {
    printf("\n List is empty!");
    return;
  }

  printf("\n List elements: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}
