#include "Stack.h"

#include <iostream>
#include <string>

Stack::Stack()
{
	//this->core = nullptr;
}


void Stack::push(const std::string& dates)
{
	core.push_back(dates);
	//return true;
}

std::string Stack::pop()
{
	std::string temp;
	if (!core.empty())
	{
		temp = core.back();
		core.pop_back();
		return temp;
	}
	return "Empty";
}

std::string Stack::peek()
{
	if (!core.empty())
		core.back();
	else
		return "Empty";
		//return std::cout << "failed" << std::endl;
}

bool Stack::isEmpty()
{
	return this->core.empty();
}