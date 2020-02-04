// MyStaticLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "MyStaticLib.h"
#include <cstring>

int Multiply(int a, int b)
{
	return a * b;
}

extern "C" int SimpleMultiply(int a, int b)
{
	return Multiply(a, b);
}

extern "C" void FillMyMemory(char * buffer, int * size)
{
	*size = 1920 * 1028 * 4;
	auto src = new char[*size];
	memcpy(buffer, src, (size_t)*size);
	// memset(buffer, 128, *size);
}