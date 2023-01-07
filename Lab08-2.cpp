#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct Node
{
    T _data;
    Node *next;
};

template<typename T>
class LinkedList
{
    private:
    Node<T>* _head;
    Node<T>* _tail;

    public:
    LinkedList()
    {
        _head = NULL;
        _tail = NULL;
    }
    ~LinkedList() {}

    void add(T value)
    {
        Node<T> *temp = new Node<T>();
        temp->_data = value;
        temp->next = NULL;

        if (_head == NULL)
        {
            _head = temp;
            _tail = temp;
        }
        else
        {
            _tail->next = temp;
            _tail = temp;
        }
    }

    Node<T>* head()
    {
        return _head;
    }

    Node<T>* tail()
    {
        return _tail;
    }

    void remove(T value)
    {
        Node<T> *current = _head;
        Node<T> *prev = NULL;
        bool found = false;

        while (current != NULL)
        {
            if (current->_data == value)
            {
                found = true;
                break;
            }
            prev = current;
            current = current->next;
        }

        if(!found)
        {
            cout << " value not found in list.." << endl;
        }
        else
        {
            if (prev == NULL)
            {
                _head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current;
            cout << value << " removed from list.." << endl;
        }
    }

    void show()
    {
        Node<T> *current = _head;
        while (current != NULL)
        {
            cout << current->_data << " -> ";
            current = current->next;
        }
        cout <<"NULL\n";
    }
};

int main() 
{
    LinkedList<int> li;
    for (int i = 10; i > 0; --i) 
    {
        li.add(i);
    }
    li.show();

    li.remove(1);
    li.remove(5);
    li.remove(4);
    li.show();

    return 0;
}