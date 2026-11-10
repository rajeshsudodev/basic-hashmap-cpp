// Simple HashTable Implementation Practice 
// Type - separate Chaining 

/** 
 * HEADERS
 */
#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <utility>

using std:: cout , std:: endl , std:: cin;


/** 
 *  HashTable Design
 */
class HashTable{
private: 
    // static const unsigned int hashGroups = 10; 
    static constexpr std:: size_t bucketCount = 10;
    std:: list< std:: pair<int, std:: string>> table[bucketCount];// why static const is required for bucketCount for using again in the private members
    size_t size = 0;
    public:

    // Default constructor only allowed 
    HashTable() {}

    // copy and move Constructor forebidden
    HashTable(const HashTable&) = delete;
    HashTable(HashTable&&) = delete;

    // copy and move Assignment forebidden
    HashTable& operator=(const HashTable&) = delete;
    HashTable& operator=( HashTable&&) = delete;


    void traversal(void) const ;
    bool tableEmpty() const ;
    void insertItem(int , std:: string);
    void erase(int) ;
    unsigned int hash(const int) const;
    std:: list<std:: pair<int , std:: string>>::iterator find(const int key);
    size_t bucketSize(const int key) const;
    size_t Size() const ;
    std:: string* searchTable(const int key) ;

};


/** 
 * retuns address of value from the HashTable by using key 
 * ensure key must exists in table
 * use dereference operator to get actual data
 */

std:: string* HashTable:: searchTable(const int key ) 
{
    unsigned int bucketIndex = hash(key);
    std::list<std:: pair <int, std:: string >> :: iterator it = find(key);

    if(it == std:: end(table[bucketIndex]))
    {
        return nullptr;
    }
    
    return &(it->second);
    // unsigned int bucketIndex = hash(key);

}

size_t HashTable:: Size() const{
    return size;
}

/**
 * Traversing Whole HashTable
 * Traverses Each Bucket 
 */
void HashTable:: traversal(void) const
{
    
    for(unsigned bucket {0} ; bucket < bucketCount; ++bucket)
    {
        cout << bucket << " : ";
        if(table[bucket].size()) { 
            cout << 0  << endl;
            continue;
        }
        
        std:: list< std:: pair< int, std:: string >> :: const_iterator cit = std:: begin(table[bucket]);
        for( cit ; cit != std:: end(table[bucket]) ; ++cit)
        // for(std:: list<std:: pair<int , std:: string>> :: iterator it = table[bucket].begin() ; it != table[bucket].end(); ++it)

        { 

            cout << cit->first << " " << cit->second << " | ";
        }
        cout << endl;
    }
}

/**
 * Function Member find 
 * If required key found then returns iterator of pair 
 * If not found returns current list's end
 */
std::list <std:: pair<int , std:: string>>::iterator HashTable:: find(const int key)
{
    unsigned int bucketIndex = hash(key);

    // if(table[bucketIndex].empty()) return NULL;
    std:: list<std:: pair < int , std:: string>>:: iterator it = table[bucketIndex].begin();
    
    for(it; it != table[bucketIndex].end(); ++it)
    {
        if(it->first == key) return it; // return pair it  when the key found / exists in list<pair<>>
    }
    return it;  // returns end of the current list's end
}

/**
 * Generates a hash key by using modulo of BucketCount 
 * Returns the generated hash key
 */

 unsigned int HashTable:: hash(const int key)  const
{
    unsigned int bucketIndex = key % bucketCount;  
    return bucketIndex;
}

/**
 * add the key and value at end of the list according to the generated hash key
 */

void HashTable:: insertItem(int key , std:: string value) 
{


    unsigned int bucketIndex = hash(key);
    std:: list<std:: pair<int ,std:: string>> :: iterator it = find(key);
    if(it != std:: end (table[bucketIndex])) {
        cout << "Key : " << key << " Already Exists , Modifiying in place !\n";
        it->second = value;
        return ;
    }
    table[bucketIndex].push_back({key, value});



    ++size;
}

/**
 * Erase elements according to the provided key  
 */
void HashTable:: erase(const int key)  
{
    unsigned int bucketIndex = hash(key);

    // for(std:: list< std:: pair<int , std:: string >> :: iterator it; it != table[bucketIndex].end(); ++it)
    // {
    //     if(it->first == key) 
    // }
    std:: list<std:: pair < int , std:: string >>:: iterator it = find(key);

    // if(it == table[bucketIndex].end()) 
    if(it == std:: end(table[bucketIndex])) 
    {
        cout << "Item " << key << " not Exists !\n";
        return ;
    }
    table[bucketIndex].erase(it);
    --size;
} 

/**

* takes key as a given input 
 * returns the count of elements in the bucket which holds the key
 */
size_t HashTable:: bucketSize(const int key) const
{
    unsigned int bucketIndex = hash(key);
    size_t size = 0;
    // for(std:: list< std:: pair <int , std:: string>>:: iterator it ;  it != table[bucketIndex].end(); ++it)
    // for(auto it = table[bucketIndex].begin() ; it != table[bucketIndex].end() ; ++it)
    // {
    //     ++size;
    // }

    // Simply 
    // size = table[bucketIndex].size();
    return table[hash(key)].size();
}


/**
 * Checking whether HashTable is Empty 
 * Navive - Traversing each bucket and tracking its size 
 * simply return if is size true (non - zero)
 */
bool HashTable:: tableEmpty() const
{
    // return (!size) ? true : false ;
    return size == 0;
    // unsigned int sum {};
    // for(unsigned int i {}; i < bucketCount ; ++i)
    // {
    //     sum += table[i].size();
    // }

    // if(!sum) return true;
    // return false;
}
int main()
{
  
    HashTable hashMap;

    cout << "is empty : " << std:: boolalpha  << hashMap.tableEmpty() << '\n';

    cout<< "size : " << hashMap.Size() << '\n';
    hashMap.insertItem(1, "one");
    hashMap.insertItem(2, "two");
    hashMap.insertItem(3, "three");
    hashMap.insertItem(4, "four");
    hashMap.insertItem(5, "five");
    hashMap.insertItem(6, "six");
    hashMap.insertItem(7, "seven");
    hashMap.insertItem(7, "updated seven");
    cout<< "size : " << hashMap.Size() << '\n';

    hashMap.traversal();
    
    {   

        if(std:: string* value = hashMap.searchTable(6)) cout << *value << '\n';
        else cout << "Key not found !\n";
    }
    {
        hashMap.erase(100);
    }
    hashMap.erase(6);
    hashMap.traversal();
    
    cout << '\n';
    hashMap.insertItem(1, "one");
    hashMap.insertItem(11, "Eleven");
    hashMap.insertItem(21, "Twenty one");
    hashMap.insertItem(31, "Thirty one");
    hashMap.insertItem(41, "Fourty one");
    hashMap.traversal();
    cout << "Key 7 value : " << *(hashMap.searchTable(7)) << endl;
    return 0;
}