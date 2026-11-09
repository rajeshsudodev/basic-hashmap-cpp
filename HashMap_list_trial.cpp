#include <iostream>
#include <unordered_map>
#include <list>
#include <forward_list>

using std:: cout;
using std:: endl;

// Design Hashmap 
template <typename T>
class HashTable
{
    static const uint hashGroups = 11;
    std:: list < std:: pair<int,std:: string> > list[hashGroups];

};


void push_back(std:: list<int> &list)
{
    for(uint i {0}; i <= 10 ; ++i)
    {
        list.push_back(i*10);
    }
}

void print( std:: list<int> &list)
{
    // for(uint i {1}; i <= 10; ++i)
    // {
    //     std::list<int>:: iterator current = std:: next(list.begin() , i);
    //     cout << *current << " ";

    // }
    // cout << endl;

    for(std:: list<int>:: iterator it = list.begin() ; it != list.end() ; ++it)
    {
        cout << *it << " " ;
    }
    cout << endl;
}
int main()
{
    // std:: unordered_map<int, int> mp;
        
    // std:: list <int> list;
    
    // for(uint i {0};  i < 10 ; ++i){
    //     list.push_back(i*10);
    // }
    
    // for(auto &val : list)  // why &val printing actual address  , i guess auto value act like a lvalue for storing the current value
    // cout << val << " " << &val << endl;
    // cout << endl;
    // std:: list<int> list[2] = {10 , 12};
    std:: list<int> list[2];
    
    push_back(list[0]);
    push_back(list[1]);
    // list[0].push_back(10);
    // list[1].push_back(10);

    print(list[0]);
    print(list[1]);
    // cout << *(list[0].begin()) << " " << *(list[1].begin()) << endl;

    cout << "size of list : " << list[0].size() /* sizeof(list[0]) */ << endl;
    // std:: string name[11] = {"one" , "Two"};
    // cout << name[0] << endl;
    // cout << sizeof(name) << endl;
    std:: forward_list<int> fdList{1,2,3,4,5};
    cout <<"size of fdList : " << sizeof(fdList) << endl;
    cout << "Max size : " << fdList.max_size() << endl;
    for(auto &x :  fdList) cout << x << " -> ";
    cout << endl;
    return 0;
}