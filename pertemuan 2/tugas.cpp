#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void insertFirst(int n) {

    node *newNode = new node;

    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(int n) {

    node *newNode = new node;

    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteFirst() {

    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    node *temp = head;

    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }

    delete temp;
}

void deleteLast() {

    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    node *p = head;

    while (p->next != tail) {
        p = p->next;
    }

    delete tail;

    tail = p;
    tail->next = NULL;
}

void display() {

    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    node *temp = head;

    cout << "Isi Linked List: ";

    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void enqueue(int n) {

    cout << "Enqueue: " << n << endl;

    insertLast(n);
}

void dequeue() {

    if (head == NULL) {
        cout << "Queue kosong!" << endl;
        return;
    }

    cout << "Dequeue: " << head->value << endl;

    deleteFirst();
}

void push(int n) {

    cout << "Push: " << n << endl;

    insertFirst(n);
}


void pop() {

    if (head == NULL) {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Pop: " << head->value << endl;

    deleteFirst();
}

int main() {

    system("cls");

    cout << "===== QUEUE =====" << endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    dequeue();
    display();

    head = NULL;
    tail = NULL;

    cout << endl;
    cout << "===== STACK =====" << endl;

    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    pop();
    display();

    return 0;
}