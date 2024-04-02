#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Queue {
    Node *head;
    Node *tail;
};

void CreateQueue(Queue &q) {
    q.head = NULL;
    q.tail = NULL;
}

Node* CreateNode(int init) {
    Node *node = new Node;
    node -> data = init;
    node -> next = NULL;
    return node;
}

void DestroyQueue(Queue &q) {
    Node *node = q.head;
    while (q.head != NULL) {
        q.head = node -> next;
        delete node;
        node = q.head;
    }
    q.tail = NULL;
}

int IsEmpty(Queue q) {
    if (q.head == NULL)
        return 1;
    return 0;
}

void EnQueue(Queue &q, Node *node) {
    if (IsEmpty(q)) {
        q.head = node;
        q.tail = node;
    }
    else {
        q.tail -> next = node;
        q.tail = node;
    }
}

int DeQueue(Queue &q) {
    if (IsEmpty(q))
        return 0;
    Node *node = q.head;
    int data = node -> data;
    q.head = node -> next;
    delete node;
    if ( q.head == NULL )
        q.tail = NULL;
    return data;
}

int Front(Queue q) {
    if (IsEmpty(q))
        return 0;
    return q.head->data;
}

void PrintQueue(Queue q) {
    Node *node = q.head;
    while (node != NULL) {
        cout << node->data << ' ';
        node = node->next;
    }
}

int main() {
    Queue queue;
    CreateQueue(queue);

    Node *node;
    for (int i = 0; i < 10; i++) {
        node = CreateNode(i + 1);
        EnQueue(queue, node);
    }

    PrintQueue(queue); // 1 2 3 4 5 6 7 8 9 10
    cout << endl;

    cout << DeQueue(queue) << endl; // 1
    PrintQueue(queue); // 2 3 4 5 6 7 8 9 10
    cout << endl;

    cout << Front(queue) << endl; // 2
    PrintQueue(queue); // 2 3 4 5 6 7 8 9 10

    return 0;
}