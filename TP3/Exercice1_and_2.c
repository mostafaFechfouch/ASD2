#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

void createList(struct Node** head, struct Node** tail, int n) {
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter the value of element %d: ", i+1);
        scanf("%d", &value);

        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->value = value;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
            *tail = newNode;
        } else {
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
}

void printList(struct Node* head){
    printf("The linked list is:\n");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int countElements(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int isListSorted(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->value > current->next->value) {
            return 0; // la liste n'est pas triée
        }
        current = current->next;
    }

    return 1; // la liste est triée
}

void sumAndInsert(struct Node* head) {
    struct Node* current = head;

    int sum = 0;
    while (current != NULL) {
        sum += current->value;
        current = current->next;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = sum;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

int minimal_value(struct Node* head){
    struct Node* current=head;
    int min=current->value;
    while(current!=NULL){
        if (current->value < min){
            min = current->value;
        }
        current= current->next;
    }
    return min;
}



int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    createList(&head, &tail, n);

    printList(head);

    printf("The number of elements of this list is: %d\n", countElements(head));

    if(isListSorted(head)){
        printf("The list is sorted in ascending order of the field value.\n");
    }else{
        printf("The list is not sorted\n");
    }

    sumAndInsert(head);

    printf("After summing \n");
    printList(head);

    int minimum;
    minimum= minimal_value(head);
    printf("The minimal value of list is %d ", minimum);


    return 0;
}
