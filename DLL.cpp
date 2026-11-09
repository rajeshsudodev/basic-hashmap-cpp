// Design 
#include <iostream>
#include <list>
using std:: cout;
using std:: endl;

template <typename T>
struct Node{
    Node  *next; // compiler automatically insert consider as Node<T>* 
    Node<T> *prev;
    T data;
};

template <typename T>
class doublyLinkedList
{
private :   
    Node<T> *Tail = nullptr;
    Node<T> *Head = nullptr;
    size_t size = 0;
public: 

    doublyLinkedList(void);
    ~doublyLinkedList();

    void pushfront(T);
    void pushback(T);
    void popfront();
    void popback();
    void Traverse() const;
    size_t Size() const;
    bool Empty() const;
    void Clear();
    Node<T>* createNode(T data);
};

template <typename T>
doublyLinkedList<T>:: doublyLinkedList(void)
{
    cout << "Linked List Initialized\n";
    Head = Tail = nullptr;
}

template <typename T>
Node<T>* doublyLinkedList<T>:: createNode(T data)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

// Empty Check  
template <typename T>   
bool doublyLinkedList<T>:: Empty() const
{
    return ( !Head && !Tail) ? true : false;
}

template <typename T>
void doublyLinkedList<T>:: pushfront(T data ){

    
    Node<T>* newNode = createNode(data);
    if(Empty()) // if head is empty 
    {
        Head = Tail = newNode;
        ++size;
        return;
    }
    
    // if List is Not Empty 
    newNode->next = Head; // Establish the connection between  newnode <--> Head 
    Head->prev = newNode;

    Head = newNode;
    ++size;
}

template <typename T>
void doublyLinkedList<T>:: pushback(T data ){

    if(Empty())  // If Tail is empty we conclude List is Empty
    { 
        pushfront(data);
        return ;
    }

    // if  list is Not Empty 
    Node<T>* newNode = createNode(data);

    newNode->prev = Tail;   // Establish the connection between tail <--> newnode 
    Tail->next = newNode;
    Tail = newNode;
    ++size;
}
template <typename T>
size_t doublyLinkedList<T>:: Size() const
{
    return size;
}

template <typename T>
void doublyLinkedList<T>:: popback(){

    if(Empty()) return ;

    // Edge Case 
    if(size == 1) { 
        
        delete Head;
        Head = Tail = nullptr;
        --size;
        return  ;
    }

    // Preserve Tail
    Node<T>* Temp = Tail; // Temporary loacation to store and delete the Node;
    
    Tail = Tail->prev;
    Tail->next = nullptr; // Disconnect the pointer 

    // Resource clean     
    delete Temp;
    Temp = nullptr; // To avoid Dangling Pointer
    --size;
}

template <typename T>
void doublyLinkedList<T>:: Traverse() const {

    Node<T>* Temp = Head;

    cout << "Null <-> ";
    while(Temp != nullptr)
    {
        cout << Temp->data << " <-> ";
        Temp = Temp->next;
    } 
    cout << "Null\n";
    return ;
}

template <typename T>
void doublyLinkedList<T>:: popfront(){

    if(Empty()) return ;
    if(size == 1) {
        delete Head ;
        Head = Tail = nullptr;
        --size;
        return;
    }


    // Preserve the Head 
    Node<T>* Temp = Head ;

    // Disconnect the Head 
    Head = Head->next;
    Head->prev = nullptr;
    
    // Resource clearn up
    delete Temp;
    Temp = nullptr;

    --size;
}

template <typename T>
doublyLinkedList<T>:: ~doublyLinkedList(){

    Clear();

}
template <typename T>
void doublyLinkedList<T>:: Clear()
{

    
    Node<T>* Temp = Head;
    if(Empty()) return ;

    while(Temp != nullptr)
    {
        // Preserve current Node 
        Node<T>* curr = Temp;
        Temp = Temp->next;  

        // Release / Clean Resources 
        delete curr; 
        curr = nullptr;
    }

    Head = Tail =nullptr;
    size = 0;
    cout << "List Resource Cleaned\n";
    return ;
}

void stringList ()
{
    
    doublyLinkedList<std:: string> strList;
    strList.pushback("one");
    strList.pushback("two");
    strList.pushback("three");
    cout << strList.Size() << endl;

    strList.Traverse();
    strList.Clear();
}

void intList() 
{
    doublyLinkedList<int> list;
    
    cout << list.Size() << endl;

    for(auto i = 1 ; i < 11 ; ++i)
    { list.pushback(i*10);}

    list.Traverse(); 
    list.Size();
    
    list.Clear();
}

int main()
{

    // intList();
    stringList();


    return 0;
}