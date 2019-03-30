#include <iostream>

using namespace std;

template <typename T>
class container
{
private:
    class Node
    {
    public:
        T Data;
        Node *next;
        Node() {
        next = nullptr;
        };
        ~Node() {delete next; };
    };
Node *first;
Node *last;
unsigned container size;

public:
    container()
    {
        container_size = 0;
        first = nullptr;
        last = first;
    }
void add(T new data)
    {
        if(container size == 0)
        {
            first = new Node;
            first->Data = new_data;
            first->next = new Node;
            last = first;
        }
        else
        {
            last->next = new Node;
            last = last->next;
            last->Data = new_data;
        }
        container size++;
    }
    void del()
    {
        node *temp = first;
        while(temp->next != last)
            temp = temp->next;
        last = temp;
        temp = temp->next;
        delete temp;
        last->next = nullptr;
        container size--;
    }
    void clear()
    {
        Node *temp = first;
        while(first != last)
            del();
        first = last = new Node;
        container size--;
        delete temp;
    }
    void show()
    {
        if(container size == 0)
        {
            cout << "container_is_empty!" << endl;
            return;
        }
        Node *temp = first;
        while(temp != nullptr)
        {
            cout << temp->Data << endl;
            temp = temp->next;
        }
        cout << "container_size = " << container_size << endl << endl;
    }
    Container<T> search(T search)
    {
        Container<T> temp;
        Node *current = first;
        while(current != nullptr) {
            if(current->Data == search)
                temp.add(current->Data);
            current = current->next;
        }
        return temp;
    }
    virtual ~container() {clear(); };
};
int main()
{
    container<char> char_list_1;

    char_list_1.add('h');
    char_list_1.add('w');
    char_list_1.add('o');
    char_list_1.add('r');
    char_list_1.add('l');
    char_list_1.add('d');

    cout << "list_1 : " << endl;
    char list 1.show();
    char list 1.del();
    cout << "list_1_after_del_last_element: " << endl;
    char_list_1.show();
    char search = 'o';
    cout  << "search \"" << search << "\"in_list_1: " << endl << "list_2: " << endl;
    container<char> char list 2 = char list 1.search(search);
    char list 2.show();
    char list 2.clear();
    cout << "list_2_after_clear: " << endl;
    char list 2.show();

    return 0;
}
