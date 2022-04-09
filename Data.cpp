#include "Data.h"
//cpp file that defines Data's operations

Data::Data(int a, int b, string c, string d, string e, string f, string g, int h)
{
	this->record = a;
	this->idNum = b;
	this->name = c;
	this->email = d;
	this->credits = e;
	this->major = f;
	this->studentYear = g;
	this->absence = h;
}

Data::Data(const Data& copyFrom)
{
	this->record = copyFrom.record;
	this->idNum = copyFrom.idNum;
	this->name = copyFrom.name;
	this->email = copyFrom.email;
	this->credits = copyFrom.credits;
	this->major = copyFrom.major;
	this->studentYear = copyFrom.studentYear;
	this->absence = copyFrom.absence;
}

Data::~Data()
{
	cout << "Destructor called!" << endl;
}

void Data::operator=(const Data& assign)
{
	this->record = assign.record;
	this->idNum = assign.idNum;
	this->name = assign.name;
	this->email = assign.email;
	this->credits = assign.credits;
	this->major = assign.major;
	this->studentYear = assign.studentYear;
	this->absence = assign.absence;
}

// GETTERS
int Data::getRecord() const
{
	return this->record;
}

int Data::getidNum() const
{
	return this->idNum ;
}
string Data::getName() const
{
	return this->name;
}
string Data::getEmail() const
{
	return this->email;
}
string Data::getCredits() const
{
	return this->credits;
}
string Data::getMajor() const
{
	return this->major;
}
string Data::getStudentYear() const
{
	return this->studentYear;
}
int Data::getNumofAbsence() const
{
	return this->absence;
}

Stack& Data::getAttendanceRec()
{
	return this->attendanceRec;
}

//SETTER
void Data::setAbsence(bool check, string date)
{
	if (check == true)
	{
		this->absence++;
		this->attendanceRec.push(date);
	}
}

void Data::setModAbsence(bool check)
{
	if (check == true)
	{
		this->absence--;
		this->attendanceRec.pop();
	}
}

