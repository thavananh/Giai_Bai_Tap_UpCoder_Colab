#include <iostream>
using namespace std;

template <typename T>
class LinkedList;

template <typename T>
class Node
{
    friend LinkedList<T>;
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
            addHead(pAdd);
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
        if (_pHead != NULL)
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
};

int main()
{
    LinkedList<int>list;
    for (size_t i = 0; i < 5; i++)
    {
        list.addTail(i);
    }
    list.display();
    system("pause");
}