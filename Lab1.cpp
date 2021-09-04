// C++ Lab 1 - Testing methods

#include <iostream>
#include <array>
#include <fstream>

// Used throughout the application to create neat indentations
void MakeIndentation() { std::cout << std::endl; }

// Exercise 3: Currency conversion functions 
double PoundToDollars(double amount) { return amount * 1.5; }

// Exercise 4: Temperature conversion function
float DegreesToFarenheit(float degrees) { return ((9.0f / 5.0f) * degrees) + 32; }

// Exercise 5: Obtaining the cube of a number 
int Cubed(int number) { return number * number * number; };

// Exercise 6: student marks
struct SStudent
{
	std::string name;
	float mark;
};

// Exercise 8: structures and functions
struct SCar
{
	std::string colour;
	std::string make;
	float mileage;
	int doors;
};

void PrintCarDetails(SCar& car)
{
	std::cout << "Make: " << car.make
		<< "\nMileage: " << car.mileage
		<< "\nColour: " << car.colour
		<< "\nDoors: " << car.doors << std::endl;
}

int main()
{
	// Exercise 1: Displaying numbers - display the integers 1 to 10 in the console window
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << ", ";
	}
	MakeIndentation(); MakeIndentation();

	// Exercise 2: While loop - If the sum of two numbers is > 100 break the loop
	int a, b, sum = 0;
	while (sum <= 100)
	{
		std::cout << "Please enter two numbers: " << sum << std::endl;
		std::cin >> a >> b;
		sum += a;
		sum += b;
	}
	MakeIndentation();

	// Exercise 3: Currency conversion functions 
	std::cout << "Please enter an amount you wish to convert: ";
	double amount = 0;
	std::cin >> amount;
	std::cout << char(156) << amount << " converts to $" << PoundToDollars(amount)
		<< " using an exchange rate of 1.5 dollars per pound" << std::endl;
	MakeIndentation();

	// Exercise 4: Temperature conversion function
	float degrees = 0;
	std::cout << "Please enter temperature in degrees: ";
	std::cin >> degrees;
	std::cout << degrees << " degrees C = " << DegreesToFarenheit(degrees) << " degrees F " << std::endl;
	MakeIndentation();

	// Exercise 5: Obtaining the cube of a number 
	int number = 0;
	std::cout << "Enter number to be cubed: ";
	std::cin >> number;
	std::cout << number << " cubed = " << Cubed(number) << std::endl;
	MakeIndentation();

	// Exercise 6: student marks
	SStudent student{ "Marcus", 88.20 };
	std::cout << "Name: " << student.name << "                 Mark: " << student.mark << std::endl;
	MakeIndentation();

	// Exercise 7: add two arrays
	std::array<int, 3> array1 = { 1,2,3 };
	std::array<int, 3> array2 = { 4,5,6 };
	std::array<int, 3> array3{};
	for (int i = 0; i < array1.size(); ++i)
	{
		array3[i] = (array1[i] + array2[i]);
		std::cout << array3[i] << ", ";
	}
	MakeIndentation(); MakeIndentation();

	// Exercise 8: structures and functions
	SCar car = { "Yellow", "Toyota Arius", 180000.0f, 5 };
	PrintCarDetails(car);
	MakeIndentation();

	// Exercise 9: Write to a file
	std::ofstream offile;
	offile.open("myfile.txt");
	offile << "hello world" << std::endl;
	offile.close();

	// Exercise 10: the start of a text editor
	std::ofstream offile;
	offile.open("myfile.txt", std::ios_base::app);
	char ch = '1';
	while (ch != '=')
	{
		std::cin >> ch;
		offile << "\n" << ch;
	}
	offile.close();
	MakeIndentation();

	system("pause");
	return 0;
}
