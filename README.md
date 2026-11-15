# Basic Generic HashTable Implementation in C++

A basic HashTable implementation in C++ using **Separate Chaining** for collision resolution.

## 📌 Overview

This project implements a basic HashTable from scratch using C++ Standard Library containers.

The HashTable stores integer keys and string values. It uses a fixed-size array of buckets, where each bucket contains a `std::list` of key-value pairs.

The primary objective of this project is to understand the internal working of a HashTable, including hashing, collision handling, insertion, searching, deletion, and traversal.

## ⚙️ Implementation Details

| Property              | Description           |
|-----------------------|-----------------------|
| Language              | C++                   |
| Standard              | C++17                 |
| Data Structure        | HashTable             |
| Collision Resolution  | Separate Chaining     |
| Bucket Storage        | Array of `std::list`  |
| Key Type              | Generic               |
| Value Type            | Generic               |
| Hash Function         | Modulo-based hashing  |
| Bucket Count          | 10 (Fixed)            |

### Internal Structure

```cpp
static constexpr std::size_t bucketCount = 10;

std::list<std::pair<int, std::string>> table[bucketCount];
```

Each bucket contains a linked list of key-value pairs. Multiple elements can be stored in the same bucket when collisions occur.

## 🔑 Hash Function

The implementation uses modulo-based hashing to calculate the bucket index.

```cpp
unsigned int bucketIndex = key % bucketCount;
```

For example, with 10 buckets:

| Key   | Bucket Index |
|---:   |---:          |
| 1     | 1            |
| 11    | 1            |
| 21    | 1            |
| 31    | 1            |
| 41    | 1            |

All these keys map to the same bucket, demonstrating collision handling through Separate Chaining.

## 🚀 Supported Operations

| Operation                 | Description                                                               |
|---------------------------|---------------------------------------------------------------------------|
| `insertItem(key, value)`  | Inserts a new key-value pair or updates an existing key                   |
| `find(key)`               | Searches for a key and returns its iterator                               |
| `searchTable(key)`        | Returns a pointer to the corresponding value, or `nullptr` if not found   |
| `erase(key)`              | Removes an element using its key                                          |
| `traversal()`             | Displays the contents of the HashTable                                    |
| `bucketSize(key)`         | Returns the number of elements in the corresponding bucket                |
| `Size()`                  | Returns the total number of stored elements                               |
| `tableEmpty()`            | Checks whether the HashTable is empty                                     |

## 🔄 Collision Handling – Separate Chaining

Separate Chaining handles collisions by maintaining a linked list at each bucket index.

When multiple keys generate the same bucket index, their key-value pairs are stored in the same linked list.

For example:

```text
Bucket 1:
    [1, "one"]
      |
    [11, "Eleven"]
      |
    [21, "Twenty one"]
      |
    [31, "Thirty one"]
```

This allows multiple elements to coexist at the same bucket without overwriting one another.

## ⏱️ Time Complexity

Let:
- `n` = Total number of stored elements.
- `B` = Number of buckets.

| Operation     | Average Case  | Worst Case |
|---            |---:           |---:        |
| Insertion     | O(1)          | O(n)       |
| Search        | O(1)          | O(n)       |
| Deletion      | O(1)          | O(n)       |
| Bucket Size   | O(1)          | O(n)       |
| Total Size    | O(1)          | O(1)       |
| Empty Check   | O(1)          | O(1)       |
| Traversal     | O(n + B)      | O(n + B)   |

Average-case complexity assumes a reasonably distributed hash function. Worst-case complexity occurs when multiple keys collide into the same bucket.

## 🛠️ Compilation and Execution

### Requirements
- C++ compiler (GCC or compatible).
- C++17 support.

### Compile

```bash
g++ -std=c++17 -Wall -Wextra -pedantic HashMap.cpp -o hashmap
```

### Execute

```bash
./hashmap
```

## ⚠️ Current Limitations

- Fixed bucket count of 10.
- No dynamic resizing or rehashing.
- Supports only integer keys and string values.
- No template-based generic implementation.
- Negative integer keys are not handled safely by the current modulo-based hash function.
- `searchTable()` returns a pointer to an internally stored value, whose validity depends on the lifetime and modification of the corresponding element.

This is a foundational implementation intended for learning HashTable internals rather than production use.

## 🎯 Learning Objectives

Through this project, the following concepts are explored:

- Understanding HashTable fundamentals.
- Hash functions and bucket indexing.
- Collision resolution using Separate Chaining.
- Linked lists as bucket storage.
- Key-value pair management.
- Searching and deletion in linked lists.
- Iterators and pointer-based access.
- Average-case and worst-case time complexity.

---

**Author:** Rajesh

**Project:** Basic HashTable Implementation in C++