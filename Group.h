#pragma once
#include "Student.h"
#include <string>
#include <conio.h>
#include <list>
#include <iterator>
using namespace std;

class StudyGroup
{
	int NumOfStud, NumOfSubj;
	string Group, Curator;
	list<string> Subjects;
	list <Students> student;
public:
	StudyGroup();
	StudyGroup(const int& NoSub, const string& Gr, const string& Cur,string* Sub);
	StudyGroup(const StudyGroup& st);
	bool Has(const string& SN,const string& FN, const string& PT);
	bool HasLink(const Students& st);
	void Add(const Students& st);
	void FindDuty();
	void FindExcellent();
	void SrAllSubjects();
	void SrOneSubject(const int& ind);
	int FindIndexSubject(const string& Sub);
	Students& GetLink(const string& SN,const string& FN, const string& PT);
	void RemoveByLink(const Students& st);
	void RemoveByIndex(const int& i);
	list <Students> GetStudentList()const;
	string GetGroupName()const;
	int GetNumOfStudents()const;
	int GetNumOfSubjects()const;
	string GetSubject(const int& n);
	void SetGroupName(const string& name);
	void SetNumOfSubjects(const int& n);
	void SetNumOfStud(const int& n);
	void SetStudentList(list<Students> lis);
	friend ostream& operator <<(ostream& out, list<StudyGroup>::iterator it);
	StudyGroup& operator =(const StudyGroup& st);
	bool operator <(const StudyGroup& st)const;
	bool operator >(const StudyGroup& st)const;
	bool operator ==(const StudyGroup& st)const;
	bool operator !=(const StudyGroup& st)const;
};