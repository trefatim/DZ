// Copyright 2015 <Anton Sidorov>
#pragma once
#include <string>
#include <list>

using std::cout;
using std::cin;
using std::string;
using std::list;

class Students {
    list<int> Points;
    string FirstName, SecondName, Patronymic;
 public:
    Students();
    Students(const string& FirstName, const string& SecondName,
        const string& Patronymic, const list<int>& Points);
    Students(const Students& St);
    const string& GetSecondName() const;
    const string& GetFirstName() const;
    const string& GetPatronymic() const;
    const list<int>& GetStudentPoints() const;
    void SetSecondName(const string& Name);
    void SetFirstName(const string& Name);
    void SetPatronymic(const string& Name);
    void SetListPoints(const list<int>& Point);
    Students& operator =(const Students& St);
    bool operator <(const Students& St) const;
    bool operator >(const Students& St) const;
    bool operator  ==(const Students& St) const;
    bool operator !=(const Students& St) const;
};
