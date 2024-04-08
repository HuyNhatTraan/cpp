#include <bits/stdc++.h>
using namespace std;

template <typename T>
void swapNe(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void nhap(int arr[100], int &n) {
    cout << "Hãy nhập số phần tử bạn muốn random: "; cin >> n;
    srand((int)time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
    cout << "Mảng sau khi đã random: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void LinearSearch(int arr[100], int n) {
    int key;
    bool daTimThay = false;
    cout << "Hãy nhập số cần tìm trong mảng: "; cin >> key;
    for (int i = 0; i < n; i++){
        if (arr[i] == key) {
            daTimThay = true;
            break;
        }
    } if (!daTimThay) { 
        cout << "Đã tìm thấy số đấy trong mảng: " << key << endl;
    } else {
        cout << "Không tìm thấy số đấy trong mảng. Vui lòng thử lại!" << endl;
    }
}

void BinarySearch(int arr[100], int left, int right, int n) {
    int key;
    bool daTimThay = false;
    cout << "Hãy nhập số cần tìm trong mảng: "; cin >> key;

    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            daTimThay = true;
            break;
        } else if (arr[mid] < key) {
            left = mid - 1;
        } else {
            right = mid + 1;
        }
    }
    if (!daTimThay) {
        cout << "Đã tìm thấy số trong mảng: " << key << endl;
    } else {
        cout << "Không tìm thấy số này trong mảng. Vui lòng thử lại!" << endl;
    }
}

void InterchangeSort(int arr[100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; i < n; j++) {
            if (arr[j] < arr[j + 1]) {
                swapNe(arr[j], arr[j + 1]);
            }
        }
    }
}

void SelectionSort(int arr[100], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i)
            swapNe(arr[i], arr[minIdx]);
    }
    
}

void BubbleSort(int arr[100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j + 1]) {
                swapNe(arr[j], arr[j - 1]);
            }
        }
    }
}

void InsertionSort(int arr[100], int n) {
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j <= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}

int Partition(int arr[100], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j = high; j++) {
        if (arr[j] < pivot) {
            i++;
            swapNe(arr[i], arr[j]);
        }
    }
    swapNe(arr[low], arr[i]);
    return i;
}

void QuickSort(int arr[100], int low, int high) {
    if (low <= high) {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

struct tagNode {
    int Value;
    tagNode* pNext;
};

struct LinkedList {
    tagNode* pHead;
    tagNode* pTail;
};

struct Stack{
    tagNode* top;
};

struct Queue {
    tagNode* pHead;
    tagNode *pTail;
};

void CreateList(LinkedList &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

void CreateStack(Stack &s) {
    s.top = NULL;
}

void CreateQueue(Queue &q) {
    q.pHead = NULL;
    q.pTail = NULL;
}

tagNode* CreateNode(int data) {
    tagNode* p = new tagNode;
    if (p == NULL) {
        cout << "Không đủ bộ nhớ để tạo. Vui lòng thử lại! " << endl;
    }
    p -> Value = data;
    p -> pNext = NULL;
    return p;
}

void AddHead(LinkedList &l, tagNode* node) {
    if (l.pHead == NULL) {
        l.pHead = node;
        l.pTail = node;
    } else {
        node -> pNext = l.pHead;
        l.pHead = node;
    }
}

void AddTail(LinkedList &l, tagNode* node) {
    if (l.pHead == NULL) {
        l.pHead = node;
        l.pTail = node;
    } else {
        l.pTail -> pNext = node;
        l.pTail = node;
    }
}

void FreeLinkedList(LinkedList& l) {
    tagNode* node = l.pHead;
    while (node != NULL) {
        tagNode* next = node -> pNext;
        int data = node -> Value;
        delete node;
        node = next;
    }
    l.pHead = NULL;
    l.pTail = NULL;
}   

int StackIsEmpty(Stack &s) {
    if (s.top == NULL) 
        return 1;
    return 0;
}

int QueueIsEmpty(Queue &q) {
    if (q.pHead == NULL)
        return 1;
    return 0;
}

void Push(Stack &s, tagNode* node) {
    if (StackIsEmpty(s)) {
        s.top = node;
    } else {
        node -> pNext = s.top;
        s.top = node;
    }
}

int Pop(Stack &s) {
    if (StackIsEmpty(s))
        return 0;
    tagNode* node = s.top;
    int data = node -> Value;
    delete node;
    return data;
}   

int Top(Stack &s) {
    if (StackIsEmpty(s))
        return 0;
    return s.top -> Value;
}

void EnQueue(Queue &q, tagNode* node) {
    if (q.pHead == NULL) {
        q.pHead = node;
        q.pTail = node;
    } else {
        q.pTail -> pNext = node;
        q.pTail = node;
    }
}

int DeQueue(Queue &q) {
    if (QueueIsEmpty(q) == 0) {
        return 0;
    }
    tagNode* node = q.pHead;
    int data = node -> Value;
    q.pHead = node -> pNext;
    delete node;
    if (q.pHead == NULL) {
        q.pTail = NULL;
    }
    return data;
}

int main() {
    // Tự truyền đi lol u already know it
}