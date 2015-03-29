#pragma once
#include <string>
using namespace std;

class Students
{
	int *points, NumOfSub;
	string FirstName,SecondName,Patronymic;
public:
	Students();
	Students(const string &FirstName,const string &SecondName,const string &Patronymic, int* points,const int &N);
	Students(const Students &st);
	~Students();
	string get_SecondName() const;
	string get_FirstName() const;
	string get_Patronymic() const;
	int* get_StudentPoints() const;
	Students& operator =(const Students &st);
	bool operator <(const Students &st);
	bool operator >(const Students &st);
	bool operator ==(const Students &st);
	bool operator !=(const Students &st);
};