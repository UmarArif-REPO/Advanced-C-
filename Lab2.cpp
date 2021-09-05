// CO2402: Advanced C++
// Week 3: Introduction to classes, the counter class hello

#include <iostream>

// Definition for a simple counter
class CCounter
{
private:
	int mAmount; // Stores the current count value
	int mTop = 0;
public:
	void Set(int number);  // Set count to the value of number
	int  Get(); 		   // Get the current value of amount
	void Increment();  	   // Increment count by 1 (trivial)
	void Decrement();      // Decrement count by 1
	void AssignTop();      // Resets the value of mAmount and assigns the value to mTop
	void DisplayValues();  // Displays both mAmount and mTop
	void TheRainInSpain(); // Will count the number of times this is outputted to the console
};

// Set counter to the value of number
void CCounter::Set(int number)
{
	mAmount = number;
}

// Get the current value of the counter
int CCounter::Get()
{
	return mAmount;
}

// Increment the counter by 1 (trivial)
void CCounter::Increment()
{
	mAmount++;
}

// Exercise 2: modifying the Counter class - Decrement the counter by 1
void CCounter::Decrement()
{
	mAmount--;
}

// Assigns then resets mAmount
void CCounter::AssignTop()
{
	mTop += mAmount;
	mAmount = 0;
}

// Displays member variables
void CCounter::DisplayValues()
{
	std::cout << "Amount: " << Get() << "    Top: " << mTop << std::endl;
}

//  Exercise 3: using the Counter class - Counting the number of operations
void CCounter::TheRainInSpain()
{
	std::cout << "The rain in spain" << std::endl;
	Increment();
}

// Exercise 4: a Student class
class CStudent
{
private:
	std::string mName;
	float mMark;
public:
	CStudent(std::string name, float mark)  // Constructor
		: mName(name), mMark(mark) {}
	void Set(std::string name, float mark); // 
	void Get();                             // 
};

void CStudent::Set(std::string name, float mark)
{
	mName = name;
	mMark = mark;
}

void CStudent::Get()
{
	std::cout << "Name: " << mName << "      Mark: " << mMark << std::endl;
}

int main()
{
	// Exercise 1: starting with the Counter class
	CCounter* myCount = new CCounter; // Declare object of type CCounter

	myCount->Set(6); // Set the value to 6

	for (int i = 0; i < 4; ++i)
	{
		myCount->Increment();  // Increment 4 times to change the value to 10
	}

	myCount->AssignTop();
	myCount->DisplayValues();

	// Exercise 2: modifying the Counter class - Decrement by 3 to display 7
	for (int i = 10; i > 7; --i)
	{
		myCount->Decrement();
	}

	myCount->AssignTop();
	myCount->DisplayValues();

	int tmp = myCount->Get();
	std::cout << tmp << std::endl << std::endl;

	// Exercise 3: using the Counter class 
	CCounter* newCounter = new CCounter;
	newCounter->Set(0);
	for (int i = 0; i < 100; i++)
	{
		newCounter->TheRainInSpain();
	}
	newCounter->AssignTop();
	newCounter->DisplayValues();

	// Exercise 4: a Student class

	delete (myCount, newCounter);
	system("pause");
}

