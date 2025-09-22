#include <stdio.h>
#include <stdlib.h>
#define MAX 3  

int queue[MAX];
int front = -1, rear = -1;


void enqueue(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == (rear + 1) % MAX)) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) { 
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = item;
    printf("%d inserted\n", item);
}


void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    int item = queue[front];
    if (front == rear) { 
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("%d deleted\n", item);
}

// Display elements of Circular Queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, item;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
