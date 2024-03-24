#include <iostream>
using namespace std;

struct SNode {
    int Info;
    SNode* next;
};

struct Stack {
    SNode* top;
};

// 1. Viết hàm khởi tạo 1 Node
SNode* KhoiTaoNode(int x) {
    SNode* newNode = new SNode;
    newNode -> Info = x;
    newNode -> next = NULL;
    return newNode;
}

// 2. Viết hàm khởi tạo stack
Stack* createStack() {
    Stack* newStack = new Stack;
    newStack -> top = NULL;
    return newStack;
}

// 3. Viết hàm khởi tạo stack rỗng
void initializeStack(Stack* stack) {
    stack -> top = NULL;
}

// 4. Viết hàm push 1 phần tử vào stack
void push(Stack* stack, int value) {
    SNode* newNode = KhoiTaoNode(value);
    newNode -> next = stack->top;
    stack -> top = newNode;
}

// 5. Viết hàm pop phần tử ra khỏi stack
int pop(Stack* stack) {
    if (stack -> top == NULL) {
        cout << "Stack is empty. Cannot pop an element." << endl;
        return INT_MIN; // Giá trị INT_MIN để thể hiện rằng stack rỗng
    }

    SNode* temp = stack->top;
    int poppedValue = temp->Info;
    stack -> top = stack->top->next;

    delete temp;
    return poppedValue;
}

int main() {
    // Sử dụng hàm khởi tạo và thao tác trên stack
    Stack* stack = createStack();
    push(stack, 5);
    push(stack, 10);
    push(stack, 15);

    cout << "Popped element: " << pop(stack) << endl;
    cout << "Popped element: " << pop(stack) << endl;
    cout << "Popped element: " << pop(stack) << endl;

    delete stack;

    return 0;
}