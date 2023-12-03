#include <iostream>
using namespace std;

template <typename T>
struct node 
{
    T data;
    node *next;
};

template <typename T>
node<T>* makeNode(T x)
{
    node<T>* newNode = new node<T>();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

template <typename T>
void duyet(node<T> *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

template <typename T>
int count(node<T> *head)
{
    int dem = 0;
    while (head != NULL)
    {
        dem++;
    }
    return dem;
}

template <typename T>
void pushFront(node<T> *&head, int x)
{
    node<T> *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

template <typename T>
void pushLast(node<T> *&head, int x)
{
    node<T> *newNode = makeNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node<T>* tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

template <typename T>
void pushAt(node<T> *&head, int x, int i)
{
    node<T> *newNode = makeNode(x);
    if (head == NULL || i == 0)
    {
        head = newNode;
        return;
    }
    int index = 0;
    node<T>* tmp = head;
    while (tmp->next != NULL && index < i - 1)
    {
        tmp = tmp->next;
        index++;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
}

template <typename T>
void removeFirst(node<T>*& head)
{
    if (head == NULL)
    {
        return;
    }
    node<T>*tmp = head; 
    head = head->next;
    delete tmp;
}

template <typename T>
void removeLast(node<T>*& head)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    node<T>*tmp1 = head;
    node<T>*tmp2 = NULL;
    while (tmp1->next != NULL)
    {
        tmp2 = tmp1;
        tmp1 = tmp1->next;
    }
    delete tmp1;
    tmp2->next = NULL;
}

template <typename T>
void removeAt(node<T>*& head, int i)
{
    if (head == NULL)
    {
        return;
    }
    if (i == 0)
    {
        node<T>*tmp1 = head;
        head = head->next;
        delete tmp1;
        return;
    }
    int index = 0;
    node<T>*current = head;
    node<T>*prev = NULL;
    while (current != NULL && index < i)
    {
        prev = current;
        current = current->next;
        index++;
    }
    prev->next = current->next;
    delete current;
}

int main()
{
    node<int> *head = NULL;
    for (size_t i = 0; i < 10; i++)
    {
        pushFront(head, i);
    }
    duyet<int>(head);
    cout << '\n';
    pushLast(head, 100);
    duyet<int>(head);
    cout << '\n';
    pushAt(head, 19, 1);
    duyet<int>(head);
    cout << '\n';
    removeFirst(head);
    duyet<int>(head);
    cout << '\n';
    removeLast(head);
    duyet<int>(head);
    cout << '\n';
    removeAt(head, 9);
    duyet<int>(head);
    system("pause");
}