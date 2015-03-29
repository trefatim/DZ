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
	string Group, Curator, *Subjects;
	list <Students> student;
public:
	StudyGroup();
	StudyGroup(const int &NoSub, const string &Gr, const string &Cur,string *Sub);
	StudyGroup(const StudyGroup &st);
	~StudyGroup();
	int getCount()const;
	string get_GroupName()const;
	//==============================================
	list <Students> get_list();
	void set_list(list<Students> lis);
	bool has(const string &SN,const string &FN, const string &PT, list<Students> l);
	void add(const Students &st, list<StudyGroup>::iterator it);
	void find_Duty(list<Students> l,const int &n);
	void find_Excellent(list<Students> l, int n);
	void srAllSub(list<Students> l,const int &nSub,const int &nStud);
	void srOneSub(list<Students> l,const int &nStud,const int &ind);
	int find_Sub(const string &Sub, list<StudyGroup>::iterator it);
	Students& get(const int& i, list<Students> l);
	void remove(const Students &st, list<Students> l, list<StudyGroup>::iterator itt);
	void remoove(const int &i, list<Students> l, list<StudyGroup>::iterator itt);
	//==============================================
	int get_NumOfSubj()const;
	string get_Subject(const int &n)const;
	void set_NumOfStud(const int &n);
	friend ostream& operator <<(ostream &out, list<StudyGroup>::iterator it);
	StudyGroup& operator =(const StudyGroup &st);
	bool operator <(const StudyGroup &st);
	bool operator >(const StudyGroup &st);
	bool operator ==(const StudyGroup &st);
	bool operator !=(const StudyGroup &st);
};