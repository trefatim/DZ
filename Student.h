// Copyright 2015 <Anton Sidorov>
#pragma once
#include <string>
#include <list>

using std::cout;
using std::cin;
using std::string;
using std::list;

class Students {
    int NumOfSub;
    list<int> points;
    string FirstName, SecondName, Patronymic;
 public:
    Students();
    Students(const string& FirstName, const string& SecondName,
        const string& Patronymic, list<int> points, const int N);
    Students(const Students& st);
    const string& GetSecondName() const;
    const string& GetFirstName() const;
    const string& GetPatronymic() const;
    const list<int>& GetStudentPoints() const;
    void SetSecondName(const string& name);
    void SetFirstName(const string& name);
    void SetPatronymic(const string& name);
    void SetListPoints(list<int> point);
    Students& operator =(const Students& st);
    bool operator <(const Students& st) const;
    bool operator >(const Students& st) const;
    bool operator  ==(const Students& st) const;
    bool operator !=(const Students& st) const;
};
