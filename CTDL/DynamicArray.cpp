#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class DynamicArray {
    T* arr;
    int _iCapacity; // length của array
    int _iSize; // số element hiện tại của array
public:
    DynamicArray(int capacity = 0) : _iCapacity(capacity), _iSize(0)
    {
        if (_iCapacity < 0)
        {
            throw std::invalid_argument("Size cannot be negative");
        }
        arr = new T[_iCapacity];
    }
    DynamicArray(const DynamicArray& dynamicarray) : _iCapacity(dynamicarray._iCapacity), _iSize(dynamicarray._iSize)
    {
        if (_iCapacity < 0)
        {
            throw std::invalid_argument("Size cannot be negative");
        }
        arr = new T[_iCapacity];
        for (size_t i = 0; i < _iSize; i++)
        {
            arr[i] = dynamicarray.arr[i];
        }
        
    }
    ~DynamicArray()
    {
        _iSize = 0;
        _iCapacity = 0;
        delete[] arr;
    }
    DynamicArray operator = (DynamicArray param_dynamicArray)
    {
        this->_iCapacity = param_dynamicArray._iCapacity;
        this->_iSize = param_dynamicArray._iSize;
        this->arr = new T[_iCapacity];
        for (int i = 0 ; i < _iCapacity; i++)
        {
            this->arr[i] = param_dynamicArray.arr[i];
        }
        return *this;
    }
    int length()
    {
        return _iSize;
    }
    int capacity()
    {
        return _iCapacity;
    }
    void add_item(T a)
    {
        if (_iSize >= _iCapacity - 1)
        {
            if (_iCapacity == 0)
            {
                _iCapacity = 1;
            }
            else
            {
                _iCapacity *= 2;
            }
        }
        T* newArr = new T[_iCapacity];
        for (int i = 0; i < _iSize; i++)
        {
            newArr[i] = arr[i];
        }
        arr = newArr;
        arr[_iSize] = a;
        _iSize++;
    }
    T getElement(int index)
    {
        return arr[index];
    }
    int firstIndexOf(T a)
    {
        for (size_t i = 0; i < _iSize; i++)
        {
            if (arr[i] == a)
            {
                return i;
            }
        }
        return -1;
    }
    int lastIndexOf(T a)
    {
        int result = -1;
        for (size_t i = 0; i < _iSize; i++)
        {
            if (arr[i] == a)
            {
                result = i;
            }
        }
        return result;
    }
    void removeElement(T value, int index = -1)
    {
        if (index != -1)
        {
            _iSize--;
            for (size_t i = index; i < _iSize - 1; i++)
            {
                arr[i] = arr[i+1];
            }
        }
        else
        {
            for (size_t i = 0; i < _iSize; i++)
            {
                if (value == arr[i])
                {
                    _iSize--;
                    if (i != _iSize - 1)
                    {
                        arr[i] = arr[i + 1];
                    }
                    else
                    {
                        arr[i] = NULL;
                    }   
                }
            }
        }
    }
    void setElement(int val, int index)
    {
        arr[index] = val;
    }
    bool contain(int val)
    {
        for (size_t i = 0; i < length(); i++)
        {
            if (arr[i] == val)
            {
                return true;
            }
        }
    }
    int countDuplicate(int val)
    {
        int rs = 0;
        for (size_t i = 0; i < length(); i++)
        {
            if (arr[i] == val)
            {
                rs++;
            }
        }
        return rs;
    }
    bool isEmpty()
    {
        return _iSize == 0;
    }
    int binarySearch(int val)
    {
        int leftArr = 0;
        int rightArr = length() - 1;
        while (leftArr <= rightArr)     //o(logN)
        {
            int mid = (leftArr + rightArr)/2; 
            if (arr[mid] == val)
            {
                return mid;
            }
            else if (arr[mid] < val)
            {
                rightArr = mid - 1;
            }
            else
            {
                leftArr = mid + 1;
            }
        }
        return -1;
    }

    void swapHaha(T& a, T& b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }

    void acsend_SelectionSort()
    {
        for (size_t i = 0; i < length(); i++)
        {
            int _minIndex = i;
            for (size_t j = i+1; j < length(); j++)
            {
                if (arr[j] < arr[_minIndex])
                {
                    _minIndex = j;
                }
            }
            if (i != _minIndex)
            {
                swapHaha(arr[i], arr[_minIndex]);
            }
            
        }
    }

    void descend_SelectionSort()
    {
        for (size_t i = 0; i < length(); i++)
        {
            T _maxIndex = i;
            for (size_t j = i+1; j < length(); j++)
            {
                if (arr[j] > arr[_maxIndex])
                {
                    _maxIndex = j;
                }
            }
            if (i != _maxIndex)
            {
                swapHaha(arr[i], arr[_maxIndex]);
            }
            
        }
    }
};


int main()
{
    DynamicArray<int> arr;
    cout << "Nhap so luong phan tu: ";
    int n; cin >> n;
    arr = DynamicArray<int>(n);
    for (size_t i = 0; i < n; i++)
    {
        arr.add_item(i);
    }
    arr.add_item(11);
    arr.add_item(11);
    arr.add_item(11);
    arr.add_item(11);
    arr.add_item(11);
    arr.add_item(11);
    arr.add_item(11);
    arr.add_item(11);
    arr.add_item(11);
    for (size_t i = 0; i < arr.length(); i++)
    {
        cout << arr.getElement(i) << " ";
    }
    arr.removeElement(4);
    cout << '\n';
    for (size_t i = 0; i < arr.length(); i++)
    {
        cout << arr.getElement(i) << " ";
    }
    cout << '\n';
    int searchIndex = arr.binarySearch(100);
    cout << (searchIndex != -1 ? "Found at: " + to_string(searchIndex) : "Not found");
    cout << '\n';
    cout << (arr.isEmpty() ? "True" : "False");
    cout << '\n';
    arr.descend_SelectionSort();
    for (size_t i = 0; i < arr.length(); i++)
    {
        cout << arr.getElement(i) << " ";
    }
    arr.acsend_SelectionSort();
    cout << '\n';
    for (size_t i = 0; i < arr.length(); i++)
    {
        cout << arr.getElement(i) << " ";
    }
    cout << '\n';
    system("pause");
    
}