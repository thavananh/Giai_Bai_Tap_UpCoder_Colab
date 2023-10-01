#include <iostream>
#include <vector>
using namespace std;

class Key
{
private:
    int _a;
public:
    Key(int a = 0)
    {
        this->_a = a;
    }
    friend bool operator == (Key x1, Key x2)
    {
        return x1._a == x2._a; 
    }
};

class Record
{
private:
    int _a;
public:
    operator Key()
    {
        return Key(_a);
    }
    Record(int a = 0) : _a(a){}
    friend istream& operator >> (istream& is, Record &record)
    {
        is >> record._a;
        return is;
    }
};


template<class T>
class List
{
private:
    int n;
    std::vector<T> v;

public:
    List() : n(0) {} // Hàm khởi tạo mặc định

    List(int size, const T& value) : n(size), v(size, value) {} // Hàm khởi tạo với kích thước và giá trị được chỉ định

    // Các phương thức khác của lớp List

    void input()
    {
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            T temp;
            cin >> temp;
            v.push_back(temp);
        }
        
    }

    void retrieve(int pos, T &data)
    {
        data = v[pos];
    }
    int size()
    {
       return this->n; 
    }
};

string sequential_search(List<Record>list, Key target, int &pos)
{
    int s = list.size();
    for (size_t pos = 0; pos < s; pos++)
    {
        Record data;
        list.retrieve(pos, data);
        if (data == target)
        {
            return "success";
        }
    }
    return "not found";   
}

int main()
{
    List<Record>list;
    list.input();
    Key key(5);
    int pos = 0;
    cout << sequential_search(list, key, pos);
    system("pause");
}