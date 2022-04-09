#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <chrono> //This will be used for time
#include <ctime> // As well as this
#include <sstream> //To use istringstream
#include <fstream> //For file opening
#include <algorithm> // Used to find data in a vector

#include "List.h"
#include "Data.h"

using std::cout;
using std::endl;

// This function returns the date in the form of year,date, month
string getTime()
{
    time_t t = time(0);   // get time now

    struct tm* now = localtime(&t);

	string send;
    //2022 - 4 - 1: Year, Month, Day

	send = std::to_string(now->tm_year + 1900) + '-'

		+ std::to_string(now->tm_mon + 1) + '-'

		+ std::to_string(now->tm_mday);
	return send;
}

// Open the excel file and load the info into the linked list
void importCourseList(List<Data>& start)
{
	std::ifstream infile("classList.csv");

	if (!infile.is_open())
	{
		cout << "file failed to open. :(" << endl;
		exit(1);
	}

	int rec;
	int id;
	string nam;
	string emil;
	string cred;
	string maj;
	string year;


	string line;
	getline(infile, line);
	while (getline(infile, line))
	{
		std::istringstream iss (line, ',');
		iss >> rec;

		std::getline(iss, line, ',');
		std::getline(iss, line, ',');
		id = stoi(line);
		std::getline(iss, line, '"');
		std::getline(iss, line, '"');

		nam = line;

		std::getline(iss, line, ',');
		std::getline(iss, line, ',');

		emil = line;

		std::getline(iss, line, ',');

		cred = line;
		std::getline(iss, line, ',');

		maj = line;
		std::getline(iss, line, ',');

		year = line;

		Data temp(rec, id, nam, emil, cred, maj, year, 0);
		start.insertFront(temp);
	}

	infile.close();

}

// load the master.txt file into the linked list
void loadMasterList(List<Data>& start)
{
	std::ifstream infile("master.txt");
	if (!infile.is_open())
	{
		cout << "file failed to open. :(" << endl;
		exit(1);
	}

	string line;
	int rec;
	int id;
	string nam;
	string emil;
	string cred;
	string maj;
	string year;
	int numofA;

	while (getline(infile, line))
	{

		std::istringstream iss(line, ',');
		iss >> rec;

		std::getline(iss, line, ',');
		std::getline(iss, line, ',');
		id = stoi(line);
		std::getline(iss, nam, ',');
		std::getline(iss, line, ',');

		nam = nam + " " + line;

		std::getline(iss, emil, ',');
		std::getline(iss, cred, ',');
		std::getline(iss, maj, ',');
		std::getline(iss, year, ',');
		std::getline(iss, line, '\0');
		numofA = stoi(line);


		Data temp(rec, id, nam, emil, cred, maj, year, numofA);
		start.insertFront(temp);
	}
	infile.close();

}

// Store the linked list to a file called master.txt
void storeMasterList(List<Data>& start)
{
	std::ofstream outfile("master.txt");
	
	List<Data> temp = start;

	while (temp.getHead() != nullptr)
	{
		outfile << temp.getHead()->getData().getRecord() << ",";
		outfile << temp.getHead()->getData().getidNum() << ",";
		outfile << temp.getHead()->getData().getName() << ",";
		outfile << temp.getHead()->getData().getEmail() << ",";
		outfile << temp.getHead()->getData().getCredits() << ",";
		outfile << temp.getHead()->getData().getMajor() << ",";
		outfile << temp.getHead()->getData().getStudentYear() << ",";
		outfile << temp.getHead()->getData().getNumofAbsence() << endl;
		//outfile << 0 << "\0";
		//outfile << endl;

		temp = temp.getHead()->getNext();
	}

	outfile.close();
} //

// Mark absences of the students in the linked list
void markAbsences(List<Data>& start)
{
	List<Data> temp = start;
	cout << "Today is " << getTime() << endl;

	while ( start.getHead() != nullptr)
	{
		//bool attendance = false;
		int input;
		cout << "Is " << start.getHead()->getData().getName() << " absent today?" << endl;
		cout << "0. for yes, and 1. for no" << endl;
		std::cin >> input;
		while (input != 0 && input != 1)
		{
			cout << "Err: try again!" << endl;
			std::cin >> input;
		}
		if (input == 0)
			start.getHead()->getData().setAbsence(true, getTime());//help
		else
			start.getHead()->getData().setAbsence(false, getTime());

		start = start.getHead()->getNext();
	}
	start = temp.getHead();
}

// edit the absence of students in the linked list
void editAbsence(List<Data>& start)
{
	string search;
	bool success = false;
	cout << "Who's absence will you be editing?" << endl;
	cout << "Enter name or ID #" << endl;
	std:: cin >> search;

	List<Data> temp = start.getHead();

	while (temp.getHead() != nullptr)
	{
		if (temp.getHead()->getData().getName() == search ||
			temp.getHead()->getData().getidNum() == stoi(search))
		{
			success = true;
			string searchDate;
			cout << "what date would you like to edit? Enter in the following format (YYYY-M-D)" << endl;
			std::cin >> searchDate;
			if (std::find(temp.getHead()->getData().getAttendanceRec().core.begin(),
				temp.getHead()->getData().getAttendanceRec().core.end(),
				searchDate) != temp.getHead()->getData().getAttendanceRec().core.end())
			{
				int input;
				cout << "Mark as: 1. No change, 2. Remove" << endl;
				std::cin >> input;
				while (input != 1 && input != 2)
				{
					cout << "Err, try again." << endl;
					std::cin >> input;
				}
				switch (input)
				{
					case 1:
						break;
					case 2:
						temp.getHead()->getData().setModAbsence(true);
						break;
				}
			}

		}
		else
		{
			cout << "Student could not be found!" << endl;
		}
		temp = temp.getHead()->getNext();
	}
}

// Printing the desired data
void generateReport(List<Data>& start)
{
	List<Data> temp = start;
	int input = 0;

	cout << "What kind of report?" << endl;
	cout << "1. latest absence of all students" << endl;
	cout << "2. Students with a specific # of absence" << endl;
	std::cin >> input;
	while (input != 1 && input != 2)
	{
		cout << "Err, try again." << endl;
		std::cin >> input;
	}
	switch (input)
	{
		case 1:
		{
			while (temp.getHead() != nullptr)
			{
				cout << temp.getHead()->getData().getName() << endl;
				if (temp.getHead()->getData().getAttendanceRec().core.empty())
				{
					cout << "No absence!" << endl;
				}
				else
				{
					cout << temp.getHead()->getData().getAttendanceRec().core.back() << endl;
				}
				temp = temp.getHead()->getNext();
			};
			break;
		}
		case 2:
		{
			int searchNum;
			cout << "How many absences?" << endl;
			std::cin >> searchNum;
			while (searchNum < 1)
			{
				cout << "Value cannot be less than 1, try again." << endl;
				std::cin >> searchNum;
			}
			cout << "The following students have at least " << searchNum << " days of absence:" << endl;
			while (temp.getHead() != nullptr)
			{
				if (temp.getHead()->getData().getNumofAbsence() >= searchNum)
				{
					cout << temp.getHead()->getData().getName() << endl;
				}
				temp = temp.getHead()->getNext();
			}
			break;
		}
	}
}

// Menu
void menu(List<Data> &start)
{
	int input = 0;
	cout << "Welcome! " << endl;
	cout << "Option 1: Import Course List " << endl;
	cout << "Option 2: Load Master List " << endl;
	cout << "Option 3: Store Master List " << endl;
	cout << "Option 4: Mark Absence" << endl;
	cout << "Option 5: Edit Absence" << endl;
	cout << "Option 6: Generate Report" << endl;
	cout << "Option 7: Exit" << endl;
	std::cin >> input;
	while (!(input >= 1 && input <= 7))
	{
		cout << "Wrong input, please try again. " << endl;
		std::cin >> input;
	}

	switch (input)
	{
	case 1:
		importCourseList(start);
		menu(start);
		break;
	case 2:
		loadMasterList(start);
		menu(start);
		break;
	case 3:
		storeMasterList(start);
		menu(start);
		break;
	case 4:
		markAbsences(start);
		menu(start);
		break;
	case 5:
		editAbsence(start);
		menu(start);
		break;
	case 6:
		generateReport(start);
		menu(start);
		break;
	case 7:
		exit;
	}

}


int main()
{
	List<Data> start;
	menu(start);


	return 0;
}