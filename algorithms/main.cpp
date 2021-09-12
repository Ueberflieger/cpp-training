/* 
   The header <algorithm> defines a collection of functions especially designed
   to be used on ranges of elements.
   A range is any sequence of objects that can be accessed through iterators
   or pointers, such as an array or an instance of some of the STL containers
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

template<class T>
void printv(vector<T> v)
{
    for (auto i: v)
    {
        cout << "[" << i << "] ";
    }

    if (v.size())
    {
        cout << endl;
    }
}

int main(void)
{
    vector<int> myvec;

    cout << "Create vector with elements -12, 0, 202, 23, -5, 30" << endl;
    myvec.push_back(-12);
    myvec.push_back(0);
    myvec.push_back(202);
    myvec.push_back(23);
    myvec.push_back(-5);
    myvec.push_back(30);


    // test if all are smaller than 203
    // the expression [](int i){return i<203} is a lambda function, where
    // [] is the capture: defines what is captured from the outside world
    //                    can be one of
    //                    [x] : a value
    //                    [&x]: a reference
    //                    [&]: any variable currently in scope, by reference
    //                    [=]: any variable currently in scope, by value
    //
    // () is the argument list
    // {} is the function body
    cout << "Test if all elements are smaller than 203 with all_of" << endl;
    cout << "Elements are smaller: " << all_of(myvec.begin(), myvec.end(), [](int i){return i<203;}) << endl;

    cout << "for_each: apply a function on each value in collection (add 1 to each element)" << endl;
    for_each(myvec.begin(), myvec.end(), [](int &i){i = i + 1;});
    printv(myvec);

    cout << "Find element with value '203' in vector" << endl;
    std::vector<int>::iterator it = find(myvec.begin(), myvec.end(), 203);
    cout << "Found: " << (it != myvec.end()) << endl;
    cout << "Iterator now points to the value: " << *it << endl;

    // swap
    cout << "swap two vectors" << endl;
    vector<int> myvec2(myvec.size());
    swap(myvec2, myvec);
    printv(myvec2);
    swap(myvec2, myvec); // swap back to continue working with myvec

    // Reverse
    cout << "Reverse vector" << endl;
    reverse(myvec.begin(), myvec.end());
    printv(myvec);

    // Rotate
    cout << "Rotate vector by 1" << endl;
    rotate(myvec.begin(), myvec.begin() + 1, myvec.end());
    printv(myvec);
    
    cout << "Rotate vector so that end is at first place" << endl;
    rotate(myvec.begin(), myvec.end() - 1,  myvec.end());
    printv(myvec);

    // Shuffle
    cout << "Shuffle vector 3 times:" << endl;
    unsigned seed;
    seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(myvec.begin(), myvec.end(), default_random_engine(seed));
    printv(myvec);
    seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(myvec.begin(), myvec.end(), default_random_engine(seed));
    printv(myvec);
    seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(myvec.begin(), myvec.end(), default_random_engine(seed));
    printv(myvec);

    // Sort
    cout << "Sort vector" << endl;
    cout << "Check if sorted" << endl;
    cout << "Is sorted? " << is_sorted(myvec.begin(), myvec.end()) << endl;
    sort(myvec.begin(), myvec.end());
    printv(myvec);

    // lower_bound
    // has to be done on a sorted range
    cout << "find first element thats bigger than 25" << endl;
    it = lower_bound(myvec.begin(), myvec.end(), 25);
    cout << "found: " << *it << endl;

    // equal_range
    cout << "find a range that is equal to a value" << endl;
    vector<int> myvec3 = {1, 2, 2, 3, 4};

    pair<vector<int>::iterator, vector<int>::iterator> bounds;
    bounds = equal_range(myvec3.begin(), myvec3.end(), 2);
    cout << "lower bound = " << bounds.first - myvec3.begin() << ", upper bound = " << bounds.second - myvec3.begin() << endl;

    // binary_search
    cout << "Do a binary search, search 24" << endl;
    bool b;
    b = binary_search(myvec.begin(), myvec.end(), 24);
    cout << "Found = " << b << endl;
    cout << "Now search 25 (doesn't exist in vector)" << endl;
    b = binary_search(myvec.begin(), myvec.end(), 25);
    cout << "Found = " << b << endl;

    // merge sorted
    cout << "merge two sorted vectors" << endl;
    cout << "v1 = {-1, 4, 6, 7, 9}" << endl;
    cout << "v2 = {6, 8, 9, 12, 22}" << endl;
    vector<int>v1 = {-1, 4, 6, 7, 9};
    vector<int>v2 = {6, 8, 9, 12, 22};
    vector<int>v3(v1.size() + v2.size());

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    printv(v3);

    // heap
    cout << "Make a heap out of a vector" << endl;
    vector<int>v4 = {3,7,2,3,9,6};
    printv(v4);
    make_heap(v4.begin(), v4.end());
    printv(v4);
    cout << "Push -2 onto the heap" << endl;
    v4.push_back(-2);
    push_heap(v4.begin(), v4.end());
    printv(v4);

    // and now pop
    pop_heap(v4.begin(), v4.end());
    cout << "Temporarily we lost heap condition: is_heap() == " << is_heap(v4.begin(), v4.end()) << endl;
    int v = v4.back();
    v4.pop_back();
    cout << "Pop: " << v << endl;
    cout << "Now we have a heap again: is_heap() == " << is_heap(v4.begin(), v4.end()) << endl;
    printv(v4);

    return 0;
}
