#define _CRTDBG_MAP_ALLOC // Exercise 9: memory leak 
#include <crtdbg.h> 
#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;

// Template function used throughout the code to print out vectors of varying sizes
template<typename T>
void printV(vector<T> v)
{
    for (T i : v) cout << i << ", ";
    cout << endl;
}

// Exercise 5: Find last - returns the index of the last occurrence of the integer in the vector
int LastOccurence(vector<int>::iterator it, vector<int> v, int input)
{
    for (it = v.begin(); it != v.end(); it++)
    {
        if (input == *it) return *it;
    }
}

// Exercise 8: cat structure
struct SCat
{
    string name;
    int age;
};

int main()
{
    // Exercise 1: Display the contents of a vector using the array syntax
    int arr[] = { 3, 5, 7, 14 };                      // A bunch of random numbers that'll be pushed into vector v1
    const int arrSize = sizeof(arr) / sizeof(arr[0]); // Size of the array

    vector<int> v1;
    for (int i = 0; i < arrSize; i++)
    {
        v1.push_back(arr[i]); // arr values pushed into vector v1
    }
    printV(v1); // Template prints out vector

    // Exercise 2: Display the contents of a vector using an iterator 
    vector<int>::iterator it;
    for (it = v1.begin(); it != v1.end(); it++)
    {
        cout << (*it) << ", " << endl;
    }

    // Exercise 3: Count instances - number of times a given value appears in the array
    vector<int> v3 = { 4, 6, 7, 8, 9 };
    int noOfInstances = 0;
    int input;
    cout << "Enter a number and fin the number of instances in the vector" << endl;
    cin >> input;
    for (int i = 0; i < v3.back(); i++)
    {
        if (input == v3[i]) noOfInstances++;
        else break;
    }

    // Exercise 4: Double up - Copy the same thing twice
    vector<int> v5 = { 3, 5, 7, 9 };
    vector<int> v4;
    for (it = v3.begin(); it != v3.end(); it++)
    {
        v4.push_back(*it);
        v4.push_back(*it);
    }
    printV(v4);

    // Exercise 5: Find last - returns the index of the last occurrence of the integer in the vector
    vector<int> v6 = { 4, 5, 7, 8, 4, 3, 7 };
    cout << LastOccurence(it, v6, 7) << endl;

    // Exercise 6: sizeof - checking the sizes of variables
    int size[50];
    cout << "Char bytes " << sizeof(char) << endl;
    cout << "Int bytes " << sizeof(int) << endl;
    cout << "Float bytes " << sizeof(float) << endl;
    cout << "Double bytes " << sizeof(double) << endl;
    cout << "Arr[50] bytes " << sizeof(size) << endl;

    // Exercise 7: memory allocation of a known data type
    int* num1 = new int;
    *num1 = 4;
    cout << *num1 << endl;
    delete(num1);

    // Exercise 8: cat structure
    SCat* cat = new SCat;
    cat->age = 12;
    cat->name = "Bob";
    cout << "Name is " << cat->name << " Age: " << cat->age << endl;
    delete(cat);

    // Exercise 9: memory leak - checks for them
    _CrtDumpMemoryLeaks(); 
    system("pause");
}