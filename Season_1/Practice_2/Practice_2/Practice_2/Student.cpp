#include "Student.h"
using namespace std;

int Student::Add(const std::string& studentName)
{
	try
	{
		_studentName.push_back(studentName);
		cout << "\n adding Compelete \n";
		return 1;
	}
	catch (exception e)
	{
		cout << "\n something went wrong \n" << e.what();
		return 0;
	}
}

int Student::Delete(const std::string& studentName)
{
	try
	{
		auto findStudentId = find(_studentName.begin(), _studentName.end(), studentName);
		int indexFound = findStudentId - _studentName.begin();
		if (findStudentId != _studentName.end())
		{
			_studentName.erase(_studentName.begin() + indexFound);
			cout << "deleting Compelete \n";
			return 1;
		}
		cout << "object not found \n";
		return 0;
	}
	catch (const std::exception&)
	{
		return 0;
	}
}

void Student::ShowStudentIdList()
{
	for (int i = 0; i < _studentName.size(); ++i) {
		cout << "Student "<< "Member: "<< i+1 << "\t" << _studentName[i] << "\n";
		if (i+1 == _studentName.size()) {
			cout << "\n number of Student: " << i+1;
		}
	}
}
