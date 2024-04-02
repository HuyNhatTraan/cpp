#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Stack {
    Node *head;
};

void CreateStack(Stack &s) {
    s.head = NULL;
}

Node *CreateNode(int init) {
    Node *node = new Node;
    node->data = init;
    node->next = NULL;
    return node;
}

int IsEmpty(Stack s) {
    if (s.head == NULL)
        return 1;
    return 0;
}

void Push(Stack &s, Node *node) {
    if (IsEmpty(s))
        s.head = node;
    else
    {
        node->next = s.head;
        s.head = node;
    }
}

int Pop(Stack &s) {
    if (IsEmpty(s))
        return 0;
    Node *node = s.head;
    int data = node->data;
    s.head = node->next;
    delete node;
    return data;
}
 
int Top(Stack s) {
    if (IsEmpty(s))
        return 0;
    return s.head->data;
}

void DestroyStack(Stack &s) {
    Node *node = s.head;
    while (s.head != NULL)
    {
        s.head = node->next;
        delete node;
        node = s.head;
    }
}

void PrintStack(Stack s) {
    Node *node = s.head;
    while (node != NULL)
    {
        cout << node->data << ' ';
        node = node->next;
    }
}

int main() {
    Stack stack;
    CreateStack(stack);

    Node *node;
    for (int i = 0; i < 10; i++)
    {
        node = CreateNode(i + 1);
        Push(stack, node);
    }
    PrintStack(stack); // 10 9 8 7 6 5 4 3 2 1
    cout << endl;

    cout << Pop(stack) << endl; // 10
    PrintStack(stack); // 9 8 7 6 5 4 3 2 1
    cout << endl;

    cout << Top(stack) << endl; // 9
    PrintStack(stack); // 9 8 7 6 5 4 3 2 1

    DestroyStack(stack);

    return 0;
}
