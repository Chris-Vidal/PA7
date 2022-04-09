#pragma once

#include "Stack.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Data
{
private:
	int record;
	int idNum;
	int absence;

	string name;
	string email;
	string credits;
	string major;
	string studentYear;
	Stack attendanceRec;

public:
	Data(int a = 0, int b = 0,string c = "", string d = "", string e = "", string f = "", string g = "", int h = 0);

	int getRecord() const;
	int getidNum() const;
	string getName() const;
	string getEmail() const;
	string getCredits() const;
	string getMajor() const;
	string getStudentYear() const;
	int getNumofAbsence() const;
	Stack& getAttendanceRec();

	Data(const Data& copyFrom);
	void operator=(const Data& assign);
	~Data();
	void setAbsence(bool check, string date);
	void setModAbsence(bool check);

};