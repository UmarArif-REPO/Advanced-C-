// CO2402: Advanced C++
// Week 3: Introduction to classes, the counter class

#include <iostream>

// Definition for a simple counter
class CCounter
{
private:
	int mAmount = 0;       // Stores the current count value
	int mTop = 0;          // Keeps a record of the number of operations
public:
	CCounter();            // Primary constructor
	CCounter(int number);  // Constructor that sets mAmount to number
	void Set(int number);  // Set count to the value of number
	int  Get(); 	       // Get the current value of amount
	void Increment();      // Increment count by 1 (trivial)
	void Decrement();      // Decrement count by 1
	void AssignTop();      // Resets the value of mAmount and assigns the value to mTop
	void DisplayValues();  // Displays both mAmount and mTop
	void TheRainInSpain(); // Will count the number of times this is outputted to the console
};

// Exercise 5: Constructors
CCounter::CCounter()
{
	mAmount = 0;
}

CCounter::CCounter(int number)
{
	mAmount = number;
}

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
	std::cout << "The rain in Spain" << std::endl;
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
	void Set(std::string name, float mark); // Set the name and mark if and when you should please
	void Get();                             // Get the name and mark
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
	CCounter* myCount = new CCounter(); // Declare object of type CCounter

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
	CCounter* newCounter = new CCounter(0);
	for (int i = 0; i < 10; i++)
	{
		newCounter->TheRainInSpain();
	}
	newCounter->AssignTop();
	newCounter->DisplayValues();
	std::cout << std::endl << std::endl;

	// Exercise 4: a Student class
	CStudent* student = new CStudent("Markus", 87.98f);
	student->Set("Mark", 87.98f);
	student->Get();
	std::cout << std::endl << std::endl;

	delete (myCount, newCounter, student);
	system("pause");
}
