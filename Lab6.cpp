#include <iostream> 
#include <string> 
#include <algorithm> 
#include <vector> 

using namespace std;

const int SIZE = 10; // constant for the maximum size of the unsorted array and for each of the buckets. 

class BucketSort
{
private:
    int unsortedData[SIZE]; // the data to be sorted 
    int bucket1[SIZE];      // stack implementation for bucket 1 
    int bucket1Top;         // stack top for bucket 1 
    int bucket2[SIZE];      // stack implementation for bucket 2 
    int bucket2Top;         // stack top for bucket 2 
    int bucket3[SIZE];      // stack implementation for bucket 3 
    int bucket3Top;         // stack top for bucket 3 
    vector<int> data;       // to concatenate integer array 
public:
    void display();
    void doSort();
    void initialiseClass(int data[SIZE]);
    void displayBuckets();
};
void InsertionSort(int arr[], int arrSize);
void Concatenate(int arr[], int arr2[], int m, int n);
void BucketSort::display()
{
    cout << "Unsorted: ";
    for (auto i : unsortedData) cout << i << " ";
    cout << endl;
}

// Set up the class. 
// Set top of each bucket to 0 and then create the array of unsortedData. 
// Note that this member function is being used in the place of a constructor. 
void BucketSort::initialiseClass(int data[SIZE])
{
    bucket1Top = 0;
    bucket2Top = 0;
    bucket3Top = 0;
    for (int i = 0; i < SIZE; i++)
    {
        unsortedData[i] = data[i];
    }
}

void BucketSort::doSort()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (unsortedData[i] >= 1 && unsortedData[i] <= 10)
        {
            bucket1[bucket1Top] = unsortedData[i];
            bucket1Top++;
        }
        else if (unsortedData[i] >= 11 && unsortedData[i] <= 20)
        {
            bucket2[bucket2Top] = unsortedData[i];
            bucket2Top++;
        }
        else if (unsortedData[i] >= 21 && unsortedData[i] <= 30)
        {
            bucket3[bucket3Top] = unsortedData[i];
            bucket3Top++;
        }
    }
    InsertionSort(bucket1, bucket1Top);
    InsertionSort(bucket2, bucket2Top);
    InsertionSort(bucket3, bucket3Top);
}

// Displays all of the items currently on the stack in order from the bottom of the stack 
// to the top of the stack. 
void BucketSort::displayBuckets()
{
    cout << "Bucket 1: ";
    for (int i = 0; i < bucket1Top; i++) cout << bucket1[i] << " ";
    cout << endl;
    cout << "Bucket 2: ";
    for (int i = 0; i < bucket2Top; i++) cout << bucket2[i] << " ";
    cout << endl;
    cout << "Bucket 3: ";
    for (int i = 0; i < bucket3Top; i++) cout << bucket3[i] << " ";
    cout << endl;
    for (int i = 0; i < bucket1Top; i++)
    {
        data.push_back(bucket1[i]);
    }
    for (int i = 0; i < bucket2Top; i++)
    {
        data.push_back(bucket2[i]);
    }
    for (int i = 0; i < bucket3Top; i++)
    {
        data.push_back(bucket3[i]);
    }
    cout << "Sorted:   ";
    for (int i : data) cout << i << " ";
    cout << endl;
}

int main()
{
    BucketSort* myBucket = new BucketSort;
    // This a fudge to deal with the fact that we're avoiding constructors for the time being. 
    // However, it works well enough. 
    int data[SIZE] = { 4, 13, 23, 12, 7, 28, 9, 15, 2, 21 };
    myBucket->initialiseClass(data);
    myBucket->display();
    myBucket->doSort();
    myBucket->displayBuckets();
    system("pause");
}

// Used to sort the buckets
void InsertionSort(int arr[], int arrSize)
{
    int i, j, key;
    for (j = 1; j < arrSize; j++)
    {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

// Brings the buckets together
void Concatenate(int arr[], int arr2[], int m, int n)
{
    memcpy(arr + m, arr2, sizeof(arr2));
}