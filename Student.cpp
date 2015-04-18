// Copyright 2015 <Anton Sidorov>
#include <iostream>
#include <list>
#include <string>
#include "Student.h"
#include "Exceptions.h"

using std::cout;
using std::cin;
using std::string;
using std::list;

Students::Students() {
    FirstName = "";
    SecondName = "";
    Patronymic = "";
}

Students::Students(const string& FirstName, const string& SecondName,
    const string& Patronymic, const list<int>& Points) {
    this->FirstName = FirstName;
    this->SecondName = SecondName;
    this->Patronymic = Patronymic;
    this->Points = Points;
}

Students::Students(const Students& St) {
    FirstName = St.FirstName;
    SecondName = St.SecondName;
    Patronymic = St.Patronymic;
    Points = St.Points;
}

const string& Students::GetFirstName() const {
    return FirstName;
}
const string& Students::GetSecondName() const {
    return SecondName;
}
const string& Students::GetPatronymic() const {
    return Patronymic;
}

const list<int>& Students::GetStudentPoints() const {
    return Points;
}

void Students::SetFirstName(const string& name) {
    FirstName = name;
}

void Students::SetSecondName(const string& name) {
    SecondName = name;
}

void Students::SetPatronymic(const string& name) {
    Patronymic = name;
}

void Students::SetListPoints(const list<int>& Point) {
    Points = Point;
}

Students& Students::operator=(const Students& St) {
    if (this != &St) {
    FirstName = St.FirstName;
    SecondName = St.SecondName;
    Patronymic = St.Patronymic;
    Points = St.Points;
    }
    return *this;
}

bool Students::operator<(const Students& St) const {
    float sr1 = 0, sr2 = 0, NumOfSub1 = 0, NumOfSub2 = 0;
    for (list<int>::const_iterator it = Points.begin();
        it != Points.end(); ++it) {
        sr1+=(*it);
        NumOfSub1++;
    }
    list<int> l = St.Points;
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        sr2+=(*it);
        NumOfSub2++;
    }
    sr1/=NumOfSub1;
    sr2/=NumOfSub2;
    return sr1 < sr2;
}

bool Students::operator>(const Students& St) const {
    float sr1 = 0, sr2 = 0, NumOfSub1 = 0, NumOfSub2 = 0;
    for (list<int>::const_iterator it = Points.begin();
        it != Points.end(); ++it) {
        sr1+=(*it);
        NumOfSub1++;
    }
    list<int> l = St.Points;
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        sr2+=(*it);
        NumOfSub2++;
    }
    sr1/=NumOfSub1;
    sr2/=NumOfSub2;
    return sr1 > sr2;
}

bool Students::operator == (const Students& St) const {
    if ((St.FirstName == FirstName) && (St.SecondName == SecondName) &&
        (St.Patronymic == Patronymic) && (St.Points == Points)) {
        return true;
    } else {
        return false;
    }
}

bool Students::operator != (const Students& st) const {
    return !(operator == (st));
}
