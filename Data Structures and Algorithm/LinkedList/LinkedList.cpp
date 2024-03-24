#include <bits/stdc++.h>
 
typedef struct tagNode { // Tạo 1 Node để lưu thông tin
    int data; // Lưu thông tin dữ liệu
    tagNode* pNext; // tạo 1 con trỏ trỏ đến Node
} Node;

typedef struct tagList { // Tạo 1 danh sách liên kết
    Node* pHead; // Tạo 1 con trỏ trỏ đến đầu của list
    Node* pTail; // Tạo 1 con trỏ trỏ đến đuôi của list
} List;

void CreateList(List &l) { // Tạo 1 danh sách rỗng (NULL)
    l.pHead = NULL;
    l.pTail = NULL;
};

Node* CreateNode(int x) {
    Node *p;
    p = new Node; // Cấp phát vùng nhớ cho 1 Node
    if (p == NULL) exit(1);
    p -> data = x;
    p -> pNext = NULL;
    return p;
};

void AddHead(List &l, Node* p) {
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else {
        p -> pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail(List &l, Node* p) {
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pTail;
    }
    else {
        l.pTail -> pNext = p;
        l.pTail = p;
    }
    
}

int main(){
    std::cout << sizeof(Node) << std::endl; // In ra số Byte của Node này 
    std::cout << sizeof(List) << std::endl; // In ra số Byte của List này 
    return 0;
}
