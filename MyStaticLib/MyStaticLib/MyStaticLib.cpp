// MyStaticLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "MyStaticLib.h"

int Multiply(int a, int b)
{
	return a * b;
}

extern "C" int SimpleMultiply(int a, int b)
{
	return Multiply(a, b);
}
