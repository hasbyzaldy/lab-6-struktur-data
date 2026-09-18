#include <iostream>
using namespace std;

//deklarasi struktur node

struct node {
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;


//dekklarasi fungsi insert di node pertama/paling depan
void insertFirst( int n ) {
    node *newNode = new node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}


//deklarasi fungsi insert di node terakhir/paling belakang
void insertLast ( int n ) {
    node *newNode = new node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}


//deklarasi fungsi insert setelah node yang ditentukan
void insertAfter ( int n, int check ) {
    if (head == NULL) {
        cout << "list kosong!" << endl;
        return;
    }

    node *newNode = new node;
    newNode->value = n;
    newNode->next = NULL;

    node *p = head;
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ditemukan." << endl;
        delete newNode;
    } else {
        newNode->next = p->next;
        p->next = newNode;
        if (p == tail) {
            tail = newNode;
        }
    }
}

// Hapus node pertama
void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    node *temp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    delete temp;
}

// Hapus node terakhir
void deleteLast() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
}

// Hapus node dengan nilai tertentu
void deleteMiddle(int value) {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    if (head->value == value) {
        deleteFirst();
        return;
    }

    node *p = head;
    while (p -> next != NULL && p->next->value != value) {
        p = p->next;
    }

    if (p->next == NULL) {
        cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
    } else {
        node *temp = p->next;
        p->next = temp->next;
        if (temp == tail) tail = p;
        delete temp;
    }
}

//cetak linked list
void display() {
    node *temp = head;
    cout << " Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main () {
    system("cls");
    insertFirst(10);
    display();
    insertLast(20);
    display();
    insertLast(30);
    display();
    insertAfter(25, 20);
    display();
    insertFirst(3);
    display();

    deleteFirst();
    display();
    deleteLast();
    display();
    deleteMiddle(25);
    display();
    return 0;
}