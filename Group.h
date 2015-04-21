// Copyright 2015 <Anton Sidorov>
#pragma once
#include <conio.h>
#include <string>
#include <list>
#include <iterator>
#include "Student.h"

using std::cout;
using std::cin;
using std::string;
using std::ostream;

class StudyGroup {
    string Group, Curator;
    list<string> Subjects;
    list <Students> Student;

 public:
    StudyGroup();
    StudyGroup(const string& Gr, const string& Cur,
        const list<string>& Sub);
    StudyGroup(const StudyGroup& St);
    bool Has(const string& SN, const string& FN, const string& PT);
    bool HasLink(const Students& St);
    void Add(const Students& St);
    list<Students> FindDuty() const;
    list<Students> FindExcellent() const;
    void SrAllSubjects() const;
    void SrOneSubject(int Ind) const;
    int FindIndexSubject(const string& Sub) const;
    Students& GetLink(const string& SN, const string& FN, const string& PT);
    void RemoveByLink(const Students& St);
    void RemoveByIndex(unsigned int Ind);
    const list<Students>& GetStudentList() const;
    const string& GetGroupName() const;
    int GetCount() const;
    int GetNumOfSubjects() const;
    const string& GetSubject(int N) const;
    void SetGroupName(const string& Name);
    void SetStudentList(const list<Students>& Lis);
    friend ostream& operator <<(ostream& out,
        list<StudyGroup>::const_iterator It);
    StudyGroup& operator =(const StudyGroup& St);
    bool operator <(const StudyGroup& St) const;
    bool operator >(const StudyGroup& St) const;
    bool operator  ==(const StudyGroup& st) const;
    bool operator !=(const StudyGroup& st) const;
    Students& Get(unsigned int Index);
};
