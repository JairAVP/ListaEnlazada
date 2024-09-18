#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
struct Node {
    int data;
    struct Node* next;
};

// insertar un nuevo nodo en orden ascendente
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Si la lista está vacía o el nuevo nodo debe ir al principio
    if (*head == NULL || data < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// encontrar elemento
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// borrar un elemento
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, * prev = NULL;

    // Si el nodo a borrar es el primer nodo
    if (temp != NULL && temp->data == key) {
        *head = temp->next; 
        free(temp);
        return;
    }

    // Buscar el nodo que contiene el valor a borrar
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Si no se encontró el nodo
    if (temp == NULL) {
        printf("El elemento %d no está en la lista.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Función para imprimir la lista
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 21);
    insert(&head, 2);
    insert(&head, 12);
    insert(&head, 7);

    printf("Lista ordenada: ");
    printList(head);

    // Buscar elemento
    int key = 10;
    struct Node* foundNode = search(head, key);
    if (foundNode != NULL) {
        printf("El elemento %d fue encontrado.\n", key);
    }
    else {
        printf("El elemento %d no fue encontrado.\n", key);
    }

    // Borrar elemento
    key = 2;
    deleteNode(&head, key);
    printf("Lista despues de borrar '%d': ", key);
    printList(head);

    return 0;
}