#pragma once
#include <string>
#include <list>
using namespace std;

class Students
{
	int NumOfSub;
	list<int> points;
	string FirstName,SecondName,Patronymic;
public:
	Students();
	Students(const string& FirstName,const string& SecondName,const string& Patronymic, int* points,const int& N);
	Students(const Students& st);
	string GetSecondName()const;
	string GetFirstName()const;
	string GetPatronymic()const;
	list<int> GetStudentPoints()const;
	void SetSecondName(const string& name);
	void SetFirstName(const string& name);
	void SetPatronymic(const string& name);
	void SetListPoints(list<int> point);
	Students& operator =(const Students& st);
	bool operator <(const Students& st);
	bool operator >(const Students& st);
	bool operator ==(const Students& st)const;
	bool operator !=(const Students& st)const;
};