#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class LinkedList;
template <typename T>
class Stack;
template <typename T>
class Queue;
template <typename T>
class Node
{
    
    friend LinkedList<T>;
    friend Stack<T>;
    friend Queue<T>;
private:
    T _data; // lưu dữ liệu
    Node* _pNext; // lưu địa chỉ ô kế tiếp
public:
    Node(T data) // tạo một node mới
    {
        this->_data = data;
        this->_pNext = NULL;
    }
    void display()
    {
        cout << this->_data;
    }
};

bool snt(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
    {
        return true;
    }
    if (n % 2 == 0)
        return false;
    for (size_t i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

template <typename T>
class LinkedList
{
private:
    Node<T>* _pHead;
    Node<T>* _pTail;
    int _iSize;
public:
    LinkedList()
    {}
    ~LinkedList()
    {}

    void display()
    {
        Node<T>* pWalker = _pHead;
        while (pWalker != NULL)
        {
            pWalker->display();
            cout << " ";
            pWalker = pWalker->_pNext;
        }
    }
    void addHead(T data)
    {
        Node<T>* pAdd = new Node<T>(data);
        if (this->_pHead == NULL)
        {
            this->_pHead = this->_pTail = pAdd; 
        }
        else
        {
            pAdd->_pNext = this->_pHead;
            this->_pHead = pAdd;
        } 
        _iSize++;       
    }
    void addTail(T data)
    {
        Node<T>* pAdd = new Node<T>(data);
        if (this->_pHead == NULL)
        {
            this->_pHead = this->_pTail = pAdd;
        }
        else
        {
            this->_pTail->_pNext = pAdd;
            this->_pTail = pAdd;
        }
        _iSize++;
    }
    void addAfter(Node<T>* node, T data)
    {
        Node<T>* pAdd = new Node<T>(data);
        if (node != NULL)
        {
            pAdd->_pNext = node->_pNext;
            node->_pNext = pAdd;
            if (node == _pTail)
            {
                _pTail = pAdd;
            }
        }
        else
        {
            addHead(pAdd->_data);
        }
        _iSize++;
    }

    void pushAt(T data, int position)
    {
        Node<T>* newNode = new Node<T>(data);
        if (_pHead == NULL || position == 0) 
        {
            newNode->_pNext = _pHead;
            _pHead = newNode;
            if (_pTail == NULL) _pTail = newNode;
        }
        else
        {
            Node<T>* temp = _pHead;
            for (int i = 0; temp != NULL && i < position - 1; i++)
            {
                temp = temp->_pNext;
            }
            if (temp != NULL)
            {
                newNode->_pNext = temp->_pNext;
                temp->_pNext = newNode;
                if (temp == _pTail) _pTail = newNode;
            }
            else 
            {
                // Nếu vị trí lớn hơn kích thước danh sách, chèn vào cuối
                _pTail->_pNext = newNode;
                _pTail = newNode;
            }
        }
        _iSize++;
    }

    Node<T>* search(T data) // trả về NULL nghĩa là không tìm ra giá trị
    {
        Node<T>* p = _pHead;
        while (p != NULL && p->_data != data)
        {
            p = p->_pNext;
        }
        return p;
    }
    Node<T>* searchPre(Node<T>* node)
    {
        Node<T>* p = _pHead;
        while (p != NULL && p->_pNext != node)
        {
            p = p->_pNext;
        }
        return p;
    }
    void removeHead()
    {
        if (this->_pHead != NULL)
        {
            Node<T>* pTemp = _pHead; //lưu lại ô nhớ của ô cần xoá
            this->_pHead = _pHead->_pNext;
            delete pTemp;
            if (_pHead == NULL) //thoả điều kiện khi xoá trong danh sách liên kết có đúng 1 phần tử
            {
                _pTail = NULL;
            }
        }
    }
    void removeTail()
    {
        if (_pHead != NULL) // Thoả điều kiện khi DSLK rỗng
        {
            Node<T> *pTemp = _pTail; //lưu lại ô nhớ của ô cần xoá
            _pTail = searchPre(_pTail);
            delete pTemp;
            if (_pTail != NULL)
            {
                _pTail->_pNext = NULL;
            }
            else //thoả điều kiện khi xoá trong danh sách liên kết có đúng 1 phần tử
            {
                _pHead = NULL;
            }
        }
    }
    void removeAfter(Node<T>* node)
    {
        Node<T>* pTemp;
        if (node != NULL)
        {
            pTemp = node->_pNext;
            if (pTemp != NULL) // xử lý trường hợp xoá node tail, vì là node tail nên phía sau chắc chắn NULL
            {
                if (pTemp == _pTail) // xử lý trường hợp khi xoá pTemp là node tail, cập nhật node tail ra trước pTemp
                {
                    _pTail = node;
                }
                node->_pNext = pTemp->_pNext;
                delete pTemp;
            }   
        }
        else
        {
            removeHead();
        }
        _iSize--;
    }

    void removeAt(int position)
    {
        if (_pHead == NULL) // Kiểm tra nếu danh sách rỗng
        {
            return;
        }

        if (position == 0) // Loại bỏ node đầu tiên
        {
            Node<T>* temp = _pHead;
            _pHead = _pHead->_pNext;
            delete temp;
            if (_pHead == NULL) _pTail = NULL;
        }
        else
        {
            Node<T>* current = _pHead;
            Node<T>* prev = NULL;
            for (int i = 0; current != NULL && i < position; i++)
            {
                prev = current;
                current = current->_pNext;
            }
            if (current != NULL)
            {
                prev->_pNext = current->_pNext;
                if (current == _pTail) _pTail = prev;
                delete current;
            }
        }
        _iSize--;
    }

    void removeWhereData(T data)
    {
        Node<T>* pWalker = _pHead;
        Node<T>* pTemp = NULL;
        while (pWalker != NULL && pWalker->_data != data)
        {
            pTemp = pWalker;
            pWalker = pWalker->_pNext;
        }
        if (pWalker == NULL) //trường hợp khi không tìm thấy
        {
            return;
        }
        if (pTemp != NULL)
        {
            if (pWalker == _pTail)
            {
                _pTail = pTemp;
                _pTail->_pNext = NULL;
            }
            pTemp->_pNext = pWalker->_pNext;
            delete pWalker;
        }
    } 
    void clear()
    {
        while (_pHead != NULL)
        {
            removeHead();
        }   
    }
    void selectionSortTangDan()
    {
        Node<T>* pMin;
        Node<T>*p, *q;
        for (p = _pHead; p->_pNext != NULL; p = p->_pNext)
        {
            pMin = p;
            for (q = p->_pNext; q != NULL; q = q->_pNext)
            {
                if (q->_data < pMin->_data)
                {
                    min = q;
                }
            }
            swap(pMin->_data, p->_data);
        }
    }
    void snt()
    {
        Node<T>*p;
        for (p = _pHead; p->_pNext != NULL; p = p->_pNext)
        {
            if (/* condition */)
            {
                /* code */
            }
            
        }
    }
};

template <typename T>
class Stack
{
private:
    Node<T>* _pTop; // Đỉnh của Stack
    int _size; // Kích thước của Stack

public:
    Stack() : _pTop(NULL), _size(0) {} // Constructor

    bool isEmpty()
    {
        return _pTop == NULL;
    }

    void push(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->_pNext = _pTop;
        _pTop = newNode;
        _size++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            Node<T>* temp = _pTop;
            _pTop = _pTop->_pNext;
            delete temp;
            _size--;
        }
    }

    T top()
    {
        if (!isEmpty())
        {
            return _pTop->_data;
        }
        else
        {
            throw std::out_of_range("Stack is empty");
        }
    }

    void display()
    {
        Node<T>* current = _pTop;
        while (current != NULL)
        {
            cout << current->_data << " ";
            current = current->_pNext;
        }
    }

    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    int getSize()
    {
        return _size;
    }
};

template <typename T>
class Queue {
private:
    Node<T>* front; // Con trỏ đến phần tử đầu hàng đợi
    Node<T>* rear;  // Con trỏ đến phần tử cuối hàng đợi
    int size;       // Kích thước của hàng đợi

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    // Kiểm tra hàng đợi có rỗng không
    bool isEmpty() {
        return size == 0;
    }

    // Thêm một phần tử vào cuối hàng đợi
    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->_pNext = newNode;
            rear = newNode;
        }
        size++;
    }

    // Loại bỏ phần tử đầu hàng đợi
    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot pop." << endl;
            return;
        }
        Node<T>* temp = front;
        front = front->_pNext;
        delete temp;
        size--;
    }

    // Lấy giá trị của phần tử đầu hàng đợi
    T top() {
        if (isEmpty()) 
        {
            cerr << "Queue is empty. No top element." << endl;
            throw runtime_error("Queue is empty.");
        }
        return front->_data;
    }   

    // Hiển thị toàn bộ hàng đợi
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            Node<T>* current = front;
            while (current != nullptr) {
                current->display();
                if (current->_pNext != nullptr) {
                    cout << " <- ";
                }
                current = current->_pNext;
            }
            cout << endl;
        }
    }

    // Xóa toàn bộ phần tử trong hàng đợi
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Lấy kích thước của hàng đợi
    int getSize() {
        return size;
    }

    ~Queue() {
        clear(); // Xóa toàn bộ các phần tử khi đối tượng bị hủy
    }
};



int main()
{
/*
    --------------TEST PHẦN MỀM---------------------------
    LinkedList<int>list;
    for (size_t i = 0; i < 5; i++)
    {
        list.addHead(i);
    }
    list.display();
    cout << '\n';
    list.pushAt(5, 1);
    list.display();
    cout << '\n';
    list.removeWhereData(5);
    list.display();
    cout << '\n';
    list.removeAt(1);
    list.display();
    cout << '\n';
    Stack<int>stc;
    stc.push(5);
    //stc.push(4);
    cout << stc.top() << '\n';
    Queue<int>q;
    q.push(5);
    q.push(4);
    cout << q.top() << '\n';
*/

/*Bài 1a. Nhập danh sách liên kết đơn các số nguyên bằng cách thêm từng phần tử vào cuối danh sách
    LinkedList<int>list;
    int x;
    while (cin >> x)
    {
        list.addTail(x);
    }
*/
/*Bài 1b. Xuất danh sách ra màn hình
    LinkedList<int>list;
    int x;
    while (cin >> x)
    {
        list.addTail(x);
    }
    list.display();
    cout << '\n';
*/
/*Bài 1c. Liệt kê các số nguyên tố có trong danh sách*/
    LinkedList<int>list;
    int x;
    while (cin >> x)
    {
        list.addTail(x);
    }
    list.display();
    cout << '\n';
    system("pause");
}