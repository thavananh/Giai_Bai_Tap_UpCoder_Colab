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
    friend bool operator >= (Key x1, Key x2)
    {
        return x1._a >= x2._a;
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
    friend ostream& operator << (ostream& os, Record record)
    {
        os << record._a << " ";
        return os;
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

    void replaceVec(int pos, T data)
    {
        auto it = v.begin() + pos;
        
        v.insert(it, data);   
        n = v.size();
    }

    void retrieve(int pos, T &data)
    {
        data = v[pos];
    }

    int size()
    {
       return this->n; 
    }

    void output()
    {
        for (size_t i = 0; i < n; i++)
        {
            cout << v[i];
        }
        
    }
};

template <class T>
class Ordered_list : public List<T>
{
public:
    Ordered_list(int n = 0) : List<T>(n, Record()) {}
    Ordered_list(int n, T value) : List<T>(n, Record(value)) {}
    string insert(Record data) // sort;
    {
        int s = Ordered_list::size();
        int pos;
        for (pos = 0; pos < s; pos++)
        {
            Record list_data;
            Ordered_list::retrieve(pos, list_data);
            Key temp = static_cast<Key>(data);
            if (list_data >= temp)
            {
                break;
            }
        }
        return replace(pos, data);
    }
    string replace(int position, Record data)
    {
        if (position > Ordered_list::size() - 1)
        {
            return "Insert failed";
        }
        Ordered_list::replaceVec(position, data);
        return "Insert success";              
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
    Ordered_list<Record>list_coThuTu;
    list_coThuTu.input();
    list_coThuTu.insert(Record(2));
    list_coThuTu.output();
    system("pause");
}