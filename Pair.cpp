// Design
#include <iostream>
#include <utility>

using std:: cout;
using std:: endl;

template <typename T1 , typename T2>
struct Pair{
    T1 first;
    T2 second;
};


int main()
{
    Pair<int, std:: string> p1;

    p1.first = 10;
    p1.second = "rajesh";

    Pair<int, std:: string > p2{11, "rajesh"};
    cout << p1.first << " " << p1.second << endl; 
    cout << p2.first << " " << p2.second << endl; 

    
    return 0;
}