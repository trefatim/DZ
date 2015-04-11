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
    NumOfSub = 0;
    FirstName = "";
    SecondName = "";
    Patronymic = "";
}

Students::Students(const string& FirstName, const string& SecondName,
    const string& Patronymic, list<int> points, const int N) {
    NumOfSub = N;
    this->FirstName = FirstName;
    this->SecondName = SecondName;
    this->Patronymic = Patronymic;
    this->points = points;
}

Students::Students(const Students& st) {
    NumOfSub = st.NumOfSub;
    FirstName = st.FirstName;
    SecondName = st.SecondName;
    Patronymic = st.Patronymic;
    points = st.points;
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
    return points;
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

void Students::SetListPoints(list<int> point) {
    points = point;
}

Students& Students::operator=(const Students& st) {
    if ((*this) == st) {
        throw AssignmentError();
    }
    FirstName = st.FirstName;
    SecondName = st.SecondName;
    Patronymic = st.Patronymic;
    NumOfSub = st.NumOfSub;
    points = st.points;
    return *this;
}

bool Students::operator<(const Students& st) const {
    float sr1 = 0, sr2 = 0;
    for (list<int>::const_iterator it = points.begin();
        it != points.end(); ++it) {
        sr1+=(*it);
    }
    list<int> l = st.points;
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        sr2+=(*it);
    }
    sr1/=NumOfSub;
    sr2/=st.NumOfSub;
    return sr1 < sr2;
}

bool Students::operator>(const Students& st) const {
    float sr1 = 0, sr2 = 0;
    for (list<int>::const_iterator it = points.begin();
        it != points.end(); ++it) {
        sr1+=(*it);
    }
    list<int> l = st.points;
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        sr2+=(*it);
    }
    sr1/=NumOfSub;
    sr2/=st.NumOfSub;
    return sr1 > sr2;
}

bool Students::operator == (const Students& st) const {
    if ((st.FirstName == FirstName) && (st.SecondName == SecondName) &&
        (st.Patronymic == Patronymic) && (st.NumOfSub == NumOfSub) &&
        (st.points == points)) {
        return true;
    } else {
        return false;
    }
}

bool Students::operator != (const Students& st) const {
    return !(operator == (st));
}
