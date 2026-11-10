#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using std:: cout;
using std:: endl;

class Test{
    std:: pair <int , std:: string> pair;
    int value = 10;
public:
    int foo(int& x) /* const */ 
    {

        this->value = x;
        
        return value;
    }
};

int main()
{
    Test t1;
    int x = 1 ;
    cout << t1.foo(x) << endl;

    std:: vector<int> arr;
    std:: vector<int> arr2{};
    std:: vector<int> arr3{0};
    std:: vector<int> arr4(10);

    auto bItr = begin(arr);
    std:: vector<int> :: iterator it = begin(arr);
    std:: vector<int> :: iterator iterator = arr.begin();
    
    int sum {0};
    std:: string str {};
    
        cout << sizeof(sum) << std:: flush << '\n';
        cout << sum <<std:: flush << '\n';

    cout << "string\n";
    cout<< str.size() << std:: flush << '\n';
    cout << str << std:: flush << '\n';
    cout << "end" << '\n';
    cout << "end" << std:: flush << '\n';
    cout << "end" << endl;
    return 0;
}