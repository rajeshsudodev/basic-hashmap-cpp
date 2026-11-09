// HashTable Simple Implementation Practice 

/** 
 * HEADERS
 */
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <list>
#include <utility>

using std:: cout;
using std:: endl;


/** 
 * Design HashTable
 */
class HashTable{
private: 
    static const unsigned int hashGroups = 10; 
    std:: list< std:: pair<int, std:: string>> table[hashGroups];// why static const is required for hashGroups for using again in the private members
    size_t size = 0;
    unsigned int bucketCount = 0;
public:

    // HashTable() = delete;
    // HashTable(const HashTable&) = delete;
    // HashTable(HashTable&&) = delete;

    void traversal(void) const ;
    void pushBack(int , std:: string);
    void erase(int) ;
    unsigned int hash(const int);
    std:: list<std:: pair<int , std:: string>>::iterator find(const int key);
    size_t bucketSize(const int key);
    size_t Size() const ;
    std:: string* searchTable(const int key);

};


/** 
 * retuns address of value from the HashTable by using key 
 * ensure key must exists in table
 * use dereference operator to get actual data
 */

std:: string* HashTable:: searchTable(const int key )
{
    std::list<std:: pair <int, std:: string >> :: iterator it = find(key);

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
        if(table[bucket].empty()) { cout << 0  << endl;continue;}
        
        // for(std:: list<std:: pair<int , std:: string>> :: iterator it = table[bucket].begin() ; it != table[bucket].end(); ++it)

        for(auto it = table[bucket].begin() ; it != table[bucket].end() ; ++it)
        { 

            cout << it->first << " " << it->second << " | ";
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
unsigned int HashTable:: hash(const int key)  
{
    unsigned int bucketIndex = key % hashGroups;  
    return bucketIndex;
}

/**
 * add the key and value at end of the list according to the generated hash key
 */

void HashTable:: pushBack(int key , std:: string value) 
{

    unsigned int bucketIndex = hash(key);
    table[bucketIndex].push_back({key, value});
    
    if(!(table[bucketIndex].empty())) ++bucketCount;  // tracking bucket count
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

    if(it == table[bucketIndex].end()) 
    {
    return ;
    }
    table[bucketIndex].erase(it);
    --size;
} 

/**
 * Give input of the key 
 * returns the count of elements in the bucket which holds the key
 */
size_t HashTable:: bucketSize(const int key)
{
    unsigned int bucketIndex = hash(key);
    size_t size = 0;
    // for(std:: list< std:: pair <int , std:: string>>:: iterator it ;  it != table[bucketIndex].end(); ++it)
    for(auto it = table[bucketIndex].begin() ; it != table[bucketIndex].end() ; ++it)
    {
        ++size;
    }
    return size;
}

int main()
{
  
    HashTable hashMap;

    cout << hashMap.Size() << endl;
    hashMap.pushBack(1, "one");
    hashMap.pushBack(2, "two");
    hashMap.pushBack(3, "three");
    hashMap.pushBack(4, "four");
    hashMap.pushBack(5, "five");
    hashMap.pushBack(6, "six");
    hashMap.pushBack(7, "seven");
    cout << hashMap.Size() << endl;

    hashMap.traversal();
    
    {
        auto it = hashMap.find(6);
        if(it->first != 0) 
        cout << it->first << " " << it->second << endl;
    }
    {
        auto it = hashMap.find(100);
        if(it->first != 0)
        cout << it->first << " " << it->second << endl;
    }
    
    hashMap.erase(6);
    hashMap.traversal();


    cout << "Key 7 value : " << *(hashMap.searchTable(7)) << endl;
    return 0;
}



  
    // std:: unordered_map <int ,std:: string> map;

    // map[0] = "zero";
    // map[1] = "one";
    // map[2] = "two";
    // map[3] = "three";
    // map[4] = "four";
    // map[5] = "five";
    // map[6] = "six";
    // map[7] = "seven";
    // map[8] = "eight";
    // map[9] = "nine";
    // map[10] = "ten";
    // map[11] = "eleven";
    // map[12] = "twelve";
    // map[13] = "thirteen";
    // map[14] = "fourteen";

    // cout << "Size : " << map.size() << endl;
    // cout << "Bucket Count : " << map.bucket_count() << endl;
    // map_traversal(map);
    // map.erase(14);
    // map.erase(13);
    // map.erase(100);
    
    // map_traversal(map);