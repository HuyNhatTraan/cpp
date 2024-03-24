#include <bits/stdc++.h>
using namespace std;

// Khai báo 1 cấu trúc cho Node
struct Node {
    int data; 
    Node* pNext;
};
// Tạo Node
Node* getNode(int x) {
    Node* newNode = new Node;
    if (newNode == NULL) {
        cout << "Khong du bo nho!";
        return NULL;
    }
    newNode -> data;
    newNode -> pNext = NULL;
    return newNode;
}
// Tạo danh sách liên kết đơn
struct SinglyLinkedList {
    Node* pHead;
    Node* pTail;
};

void CreateList(SinglyLinkedList &l){
    l.pHead = NULL;
    l.pTail = NULL;
}
// 3.1 Thêm vào danh sách liên kết theo pp AddHead và AddTail

void addHead(SinglyLinkedList &l, Node* getNode){
    if (l.pHead == NULL){
        l.pHead = Node;
        l.pTail = Node;
    } else {
        Node -> pNext = l.pHead;
        l.pHead = Node;
    }
}

int main(){
    LinkedList list;
    CreateList(list);
    return 0;
}