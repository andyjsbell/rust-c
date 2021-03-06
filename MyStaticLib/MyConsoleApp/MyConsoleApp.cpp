// MyConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <MyStaticLib.h>
#include <chrono>
int main()
{
    std::cout << "Hello World!\n";
	std::cout << SimpleMultiply(10, 2) << std::endl;
	int size = 1920 * 1028 * 4;

	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	char* buffer = new char[size];
	FillMyMemory(buffer, &size);

	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
