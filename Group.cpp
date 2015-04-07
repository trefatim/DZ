// Copyright 2015 <Anton Sidorov>
#include <conio.h>
#include <string>
#include <list>
#include <iterator>
#include <iostream>
#include "Group.h"

using std::cout;
using std::cin;
using std::string;
using std::list;

StudyGroup::StudyGroup() {
    NumOfStud = 0;
    NumOfSubj = 0;
    Group = "";
    Curator = "";
}

StudyGroup::StudyGroup(const int& NoSub, const string& Gr, const string& Cur,
    string *Sub) {
    NumOfSubj = NoSub;
    NumOfStud = 0;
    Group = Gr;
    Curator = Cur;
    for (int i=0; i < NoSub; i++) {
        Subjects.push_back(Sub[i]);
    }
}

StudyGroup::StudyGroup(const StudyGroup& st) {
    NumOfStud = st.NumOfStud;
    NumOfSubj = st.NumOfSubj;
    Group = st.Group;
    Curator = st.Curator;
    Subjects = st.Subjects;
    student = st.student;
}

int StudyGroup::GetNumOfStudents()const {
    return NumOfStud;
}

string StudyGroup::GetGroupName()const {
    return Group;
}

int StudyGroup::GetNumOfSubjects()const {
    return NumOfSubj;
}

void StudyGroup::SetNumOfStud(const int& n) {
    NumOfStud = n;
}

void StudyGroup::SetNumOfSubjects(const int& n) {
    NumOfSubj = n;
}

bool StudyGroup::Has(const string& SN, const string& FN, const string& PT) {
    for (list<Students>::iterator i = student.begin();
        i != student.end(); i++) {
        if ((i->GetSecondName() == SN) && (i->GetFirstName() == FN) &&
            (i->GetPatronymic() == PT)) {
            return true;
        }
    }
    return false;
}

bool StudyGroup::HasLink(const Students& st) {
    for (list<Students>::iterator i = student.begin();
        i != student.end(); i++) {
        if ((*i) == st) {
            return true;
        }
    }
    return false;
}

string StudyGroup::GetSubject(const int& n) {
    int count = 0;
    for (list<string>::iterator it = Subjects.begin();
        it != Subjects.end(); ++it) {
        if (count == n) {
            return (*it);
        }
        count++;
    }
    return "";
}

int StudyGroup::FindIndexSubject(const string& Sub) {
    int i = 0;
    for (list<string>::iterator it = Subjects.begin();
        it != Subjects.end(); ++it) {
        if (Sub == (*it)) {
            return i;
        }
        i++;
    }
    return -1;
}

ostream& operator  << (ostream& out, list<StudyGroup>::iterator it) {
    cout << "\nGroup: " << it->Group;
    cout << "\nCurator: " << it->Curator;
    cout << "\nNumber of students: " << it->NumOfStud;
    cout << "\nNumber of subjects: " << it->NumOfSubj;
    cout << "\nSubjects: ";
    list<string> ll = it->Subjects;
    for (list<string>::iterator itt = ll.begin(); itt != ll.end(); ++itt) {
        cout << (*itt) << " ";
    }
    list <Students> l = it->GetStudentList();
    for (list<Students>::iterator j = l.begin(); j != l.end(); j++) {
        cout << "\nStudent: " << j->GetSecondName() << " "
             << j->GetFirstName() << " " <<  j->GetPatronymic();
        cout << "\nPoints: ";
        list<int> arr = j->GetStudentPoints();
        for (list<int>::iterator i = arr.begin(); i != arr.end(); ++i) {
            cout << (*i) << " ";
        }
    }
    cout << "\n";
    return out;
}

list <Students> StudyGroup::GetStudentList()const {
    return student;
}

void StudyGroup::SetStudentList(list<Students> lis) {
    student = lis;
}

void StudyGroup::SetGroupName(const string& name) {
    Group = name;
}

void StudyGroup::FindDuty() {
    int k, k1 = 0;
    for (list<Students>::iterator i = student.begin();
        i != student.end(); i++) {
        k = 0;
        list<int> arr = i->GetStudentPoints();
        for (list<int>::iterator j = arr.begin(); j != arr.end(); ++j) {
            if ((*j) < 60) {
                k = 1;
                k1++;
            }
        }
        if (k == 1) {
            cout << i->GetSecondName() << " " << i->GetFirstName()
                << " " << i->GetPatronymic() << "\n";
        }
    }
    if (k1 == 0) {
        cout << "There's no any debtors";
    }
}

void StudyGroup::FindExcellent() {
    int k, k1 = 0;
    for (list<Students>::iterator i = student.begin();
        i != student.end(); i++) {
        k = 0;
        list<int> arr = i->GetStudentPoints();
        for (list<int>::iterator j = arr.begin(); j != arr.end(); ++j) {
            if ((*j) >= 85) {
                k++;
            }
        }
        if (k == NumOfSubj) {
            cout << i->GetSecondName() << " " << i->GetFirstName() << " "
                << i->GetPatronymic() << "\n";
            k1++;
        }
    }
    if (k1 == 0) {
        cout << "There's no any excellent students";
    }
}

void StudyGroup::SrAllSubjects() {
    if (NumOfStud == 0) {
        cout << "There's no any students";
    } else {
        int k = 0;
        float sr = 0;
        for (list<Students>::iterator i = student.begin();
            i != student.end(); i++) {
            k = 0;
            list<int> arr = i->GetStudentPoints();
            for (list<int>::iterator j = arr.begin(); j != arr.end(); ++j) {
                k+=(*j);
            }
            sr = sr+(k/NumOfSubj);
        }
        sr/=NumOfStud;
        cout << sr;
    }
}

void StudyGroup::SrOneSubject(const int& ind) {
    if (NumOfStud == 0) {
        cout << "There's no any students";
    } else {
        float sr = 0;
        for (list<Students>::iterator i = student.begin();
            i != student.end(); i++) {
            list<int> arr = i->GetStudentPoints();
            int count = 0;
            for (list<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
                if (count == ind) {
                    sr+=(*it);
                }
                count++;
            }
        }
        sr/=NumOfStud;
        cout << sr;
    }
}

StudyGroup& StudyGroup::operator =(const StudyGroup& st) {
    NumOfStud = st.NumOfStud;
    NumOfSubj = st.NumOfSubj;
    Group = st.Group;
    Curator = st.Curator;
    Subjects = st.Subjects;
    student = st.student;
    return *this;
}

bool StudyGroup::operator<(const StudyGroup& st)const {
    return NumOfStud < st.NumOfStud;
}

bool StudyGroup::operator>(const StudyGroup& st)const {
    return NumOfStud > st.NumOfStud;
}

bool StudyGroup::operator == (const StudyGroup& st)const {
    return Group == st.Group;
}

bool StudyGroup::operator != (const StudyGroup& st)const {
    return !(operator == (st));
}

void StudyGroup::Add(const Students& st) {
    student.push_back(st);
    NumOfStud++;
}

Students& StudyGroup::GetLink(const string& SN, const string& FN,
    const string& PT) {
    static Students st;
    int j = 0;
    for (list<Students>::iterator it = student.begin();
        it != student.end(); it++) {
        if ((it->GetFirstName() == FN) && (it->GetSecondName() == SN) &&
            (it->GetPatronymic() == PT)) {
            st = (*it);
        }
    }
    return st;
}

void StudyGroup::RemoveByLink(const Students& st) {
    for (list<Students>::iterator it = student.begin(); it != student.end();) {
        if ((*it) == st) {
            it = student.erase(it);
            NumOfStud--;
            cout << "Student has been deleted";
        } else {
            it++;
        }
    }
}

void StudyGroup::RemoveByIndex(const int& i) {
    int j = 0;
    for (list<Students>::iterator it = student.begin(); it != student.end();) {
        j++;
        if (j == i) {
            it = student.erase(it);
            NumOfStud--;
            cout << "Student has been deleted";
        } else {
            it++;
        }
    }
}
