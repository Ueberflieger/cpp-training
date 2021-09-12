#include <array>
#include <deque>
#include <map>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    // Arrays
    // An array is a fixed size linear container
    cout << "Arrays" << endl << "---------" << endl;
    cout << "Create an array" << endl;
    array<int, 3> myarray = {1,22,55};

    cout << "Array: Print individual values" << endl;
    cout << myarray.at(1) << endl;
    cout << myarray.at(2) << endl;

    cout << "Array: Print size and max_size" << endl;
    cout << "size: " << myarray.size() << endl;
    cout << "max_size: " << myarray.max_size() << endl;

    cout << "Array: Access first and last" << endl;
    cout << "first: " << myarray.front() << endl;
    cout << "back: " << myarray.back() << endl;

    cout << "Print in a loop" << endl;
    for (auto i: myarray)
    {
        cout << i << endl;
    }

    // Vectors
    // Vectors, compared to arrays are dynamic
    // Vectors store it's values in a contiguous storage location
    cout << "Vectors" << endl << "---------" << endl;
    cout << "Create a vector" << endl;
    vector<int> myvector;

    myvector.push_back(11);
    myvector.push_back(22);
    myvector.push_back(32);
    myvector.push_back(44);

    cout << "Print individual values of the vector:" << endl;
    cout << myvector[0] << endl;
    cout << myvector[2] << endl;

    cout << "You can print elements with a pointer + offset" << endl;
    cout << *(&myvector[1] + 2) << endl;

    cout << "Print vector in a loop:" << endl;
    for (auto i: myvector)
    {
        cout << i << endl;
    }

    cout << "Insert in the middle" << endl;
    myvector.insert(myvector.begin() + 2, 355);
    
    cout << "Print vector again after inserting one value at position 2:" << endl;
    for (auto i: myvector)
    {
        cout << i << endl;
    }

    // Deque
    // Double ended queue
    // They support adding data efficiently at both ends.
    // Deque's do store it's values in a contigous storage location.
    // Accessing elements by pointer will cause undefined behavior.
    cout << "Deques" << endl << "---------" << endl;
    cout << "Create a deque" << endl;
    deque<int> mydeque;

    cout << "Insert values 3, 4 at the front" << endl;
    mydeque.push_front(3);
    mydeque.push_front(4);

    cout << "Insert values 99, 33 at the back" << endl;
    mydeque.push_back(99);
    mydeque.push_back(33);

    cout << "Print deque after inserting values:" << endl;
    for (auto i: mydeque)
    {
        cout << i << endl;
    }

    // Stack
    // LIFO
    cout << "Stack" << endl << "---------" << endl;
    cout << "Create a stack" << endl;
    stack<int> mystack;
    
    cout << "check if the stack is empty: " << mystack.empty() << endl;

    cout << "Stack: Push a bunch of values on the stack" << endl;
    mystack.push(12);
    mystack.push(34);
    mystack.push(45);
    mystack.push(56);
    
    cout << "Check the size of the stack" << endl;
    cout << "Size = " << mystack.size() << endl;

    cout << "Pop all values from the stack:" << endl;
    while (!mystack.empty())
    {
        cout << mystack.top() << endl;
        mystack.pop();
    }
    
    // Map
    // Maps are associative containers that store elements formed by a
    // combination of a key and a mapped value, following a specific
    // order.
    cout << "Create a map <string,int>" << endl;
    map<string, int>mymap;
    
    cout << "add key value pairs to map 'bla' = 2, 'ble' = 5, 'blu' = 7" << endl;
    mymap["bla"] = 2;
    mymap["ble"] = 5;
    mymap["blu"] = 7;

    cout << "Test a value of my map" << endl;
    cout << "Value of 'bla' is: " << mymap["bla"] << endl;

    cout << "iterate through map" << endl;
    string key;
    int val;
    for (auto const &p : mymap)
    {
        cout << "key = " << p.first << ", value = " << p.second << endl;
    }

    return 0;
}
