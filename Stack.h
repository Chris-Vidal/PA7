#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
////#include <string>
////#include <chrono>
#include <ctime>
//// 
#include <vector>
#include <string>

//#include "StackNode.h"

typedef struct Stack
{
	std::vector<std::string> core;

	Stack();

	void push(const std::string& dates);
	 std::string pop();
	 std::string peek();
	 bool isEmpty();
}Stack;