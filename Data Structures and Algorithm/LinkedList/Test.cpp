#include <bits/stdc++.h>
using namespace std;

typedef struct tagNode { // Tạo 1 Node để lưu thông tin
    int data; // Lưu thông tin dữ liệu
    tagNode* pNext; // tạo 1 con trỏ trỏ đến Node
} Node;

typedef struct tagList { // Tạo 1 danh sách liên kết
    Node* pHead; // Tạo 1 con trỏ trỏ đến đầu của list
    Node* pTail; // Tạo 1 con trỏ trỏ đến đuôi của list
} LinkedList;

void CreateList(LinkedList &l) { // Tạo 1 danh sách rỗng (NULL)
    l.pHead = NULL;
    l.pTail = NULL;
}

Node* CreateNode(int x) {
    Node *p;
    p = new Node; // Cấp phát vùng nhớ cho 1 Node
    if (p == NULL) exit(1);
    p -> data = x;
    p -> pNext = NULL;
    return p;
}

void AddHead(LinkedList &l, Node* node){
    if (l.pHead == NULL) {
        l.pHead = node;
        l.pTail = node;
    } else {
        node -> pNext = l.pHead;
        l.pHead = node;
    }
}

void AddTail(LinkedList &l, Node* node){
    if (l.pHead == NULL) {
        l.pHead = node;
        l.pTail = node;
    } else {
        l.pTail -> pNext = node;
        l.pTail = node;
    }
}

void InsertAfterQ(LinkedList &l, Node* p, Node* q) {
    if  (q != NULL) {
        p -> pNext = q -> pNext;
        q -> pNext = p;
        if (l.pTail == q) {
            l.pTail = p;
        }
    } else {
        AddHead(l, p);
    }
}

// Xóa ở đầu
int RemoveHead(LinkedList& l, int& x)
{
	if (l.pHead != NULL)
	{
		Node* node = l.pHead;
		x = node->data;      // Lưu giá trị của node head lại
		l.pHead = node->pNext;
		delete node;         // Hủy node head đi
		if (l.pHead == NULL)
			l.pTail = NULL;
		return 1;
	}
	return 0;
}

int RemoveAfterQ(LinkedList& l, Node* q, int& x) {
	if (q != NULL) {
		Node* p = q -> pNext;
		if (p != NULL) {
			if (l.pTail == p)
				l.pTail = q;
			q -> pNext = p -> pNext;
			x = p -> data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}

// Duyệt danh sách và in
void PrintList(LinkedList l)
{
	if (l.pHead != NULL)
	{
		Node* node = l.pHead;
		while (node != NULL)
		{
			cout << node->data << ' ';
			node = node->pNext; // Chuyển sang node tiếp theo
		}
	}
}

// Lấy giá trị node bất kỳ
Node* GetNode(LinkedList& l, int index)
{
	Node* node = l.pHead;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->pNext;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;
}

// Tìm kiếm phần tử trong danh sách
Node* Search(LinkedList l, int x)
{
	Node* node = l.pHead;
	while (node != NULL && node->data != x)
		node = node->pNext;
	if (node != NULL)
		return node;
	return NULL;
}

// Đếm số phần tử của danh sách
int Length(LinkedList l)
{
	int count = 0;
	Node* node = l.pHead;
	while (node != NULL)
	{
		count++;
		node = node->pNext;
	}
	return count;
}

// Xóa danh sách
void DestroyList(LinkedList& l)
{
	int x;
	Node* node = l.pHead;
	while (node != NULL)
	{
		RemoveHead(l, x);
		node = l.pHead;
	}
	l.pTail = NULL;
}

int main(){
    LinkedList list;
    CreateList(list);
    return 0;
}