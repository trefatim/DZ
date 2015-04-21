// Copyright 2015 <Anton Sidorov>
#include <conio.h>
#include <string>
#include <list>
#include <iterator>
#include <iostream>
#include "Group.h"
#include "Exceptions.h"

enum {ExcellentPoint = 85, BadPoint = 60};

using std::cout;
using std::cin;
using std::string;
using std::list;
using std::advance;
using std::endl;

StudyGroup::StudyGroup() {
    Group = "";
    Curator = "";
}

StudyGroup::StudyGroup(const string& Gr, const string& Cur,
    const list<string>& Sub) {
    Group = Gr;
    Curator = Cur;
    Subjects = Sub;
}

StudyGroup::StudyGroup(const StudyGroup& St) {
    Group = St.Group;
    Curator = St.Curator;
    Subjects = St.Subjects;
    Student = St.Student;
}

int StudyGroup::GetCount() const {
    return Student.size();
}

const string& StudyGroup::GetGroupName() const {
    return Group;
}

int StudyGroup::GetNumOfSubjects() const {
    return Subjects.size();
}

bool StudyGroup::Has(const string& SN, const string& FN, const string& PT) {
    for (list<Students>::iterator i = Student.begin();
        i != Student.end(); i++) {
        if ((i->GetSecondName() == SN) && (i->GetFirstName() == FN) &&
            (i->GetPatronymic() == PT)) {
            return true;
        }
    }
    return false;
}

bool StudyGroup::HasLink(const Students& St) {
    for (list<Students>::iterator i = Student.begin();
        i != Student.end(); i++) {
        if ((*i) == St) {
            return true;
        }
    }
    return false;
}

const string& StudyGroup::GetSubject(int N) const {
    int count = 0;
    for (list<string>::const_iterator it = Subjects.begin();
        it != Subjects.end(); ++it) {
        if (count == N) {
            return (*it);
        }
        count++;
    }
    throw WrongSubjectIndex();
}

int StudyGroup::FindIndexSubject(const string& Sub) const {
    int i = 0;
    for (list<string>::const_iterator it = Subjects.begin();
        it != Subjects.end(); ++it) {
        if (Sub == (*it)) {
            return i;
        }
        i++;
    }
    throw SubjectNotFound(Sub);
}

ostream& operator  << (ostream& out, list<StudyGroup>::const_iterator it) {
    cout << "\nGroup: " << it->Group;
    cout << "\nCurator: " << it->Curator;
    cout << "\nNumber of students: " << it->Student.size();
    cout << "\nNumber of subjects: " << it->Subjects.size();
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

const list<Students>& StudyGroup::GetStudentList() const {
    return Student;
}

void StudyGroup::SetStudentList(const list<Students>& Lis) {
    Student = Lis;
}

void StudyGroup::SetGroupName(const string& Name) {
    Group = Name;
}

list<Students> StudyGroup::FindDuty() const {
    if (Student.size() == 0) {
        throw NoAnyStudents(Group);
    }
    int k, k1 = 0;
    list<Students> l;
    for (list<Students>::const_iterator i = Student.begin();
        i != Student.end(); i++) {
        k = 0;
        list<int> arr = i->GetStudentPoints();
        for (list<int>::iterator j = arr.begin(); j != arr.end(); ++j) {
            if ((*j) < BadPoint) {
                k = 1;
                k1++;
            }
        }
        if (k == 1) {
            l.push_back(*i);
        }
    }
    return l;
}

list<Students> StudyGroup::FindExcellent() const {
    if (Student.size() == 0) {
        throw NoAnyStudents(Group);
    }
    int k, k1 = 0;
    list<Students> l;
    for (list<Students>::const_iterator i = Student.begin();
        i != Student.end(); i++) {
        k = 0;
        list<int> arr = i->GetStudentPoints();
        for (list<int>::iterator j = arr.begin(); j != arr.end(); ++j) {
            if ((*j) >= ExcellentPoint) {
                k++;
            }
        }
        if (k == Subjects.size()) {
            l.push_back(*i);
            k1++;
        }
    }
    return l;
}

void StudyGroup::SrAllSubjects() const {
    if (Student.size() == 0) {
        throw NoAnyStudents(Group);
    }
    int k = 0;
    float sr = 0;
    for (list<Students>::const_iterator i = Student.begin();
        i != Student.end(); i++) {
        k = 0;
        list<int> arr = i->GetStudentPoints();
        for (list<int>::iterator j = arr.begin(); j != arr.end(); ++j) {
            k+=(*j);
        }
        sr = sr+(k/Subjects.size());
    }
    sr/=Student.size();
    cout << sr;
}

void StudyGroup::SrOneSubject(int Ind) const {
    if (Student.size() == 0) {
        throw NoAnyStudents(Group);
    }
    float sr = 0;
    for (list<Students>::const_iterator i = Student.begin();
        i != Student.end(); i++) {
            list<int> arr = i->GetStudentPoints();
            int count = 0;
            for (list<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
                if (count == Ind) {
                    sr+=(*it);
                }
                count++;
            }
    }
    sr/=Student.size();
    cout << sr;
}

StudyGroup& StudyGroup::operator =(const StudyGroup& St) {
    if (this != &St) {
    Group = St.Group;
    Curator = St.Curator;
    Subjects = St.Subjects;
    Student = St.Student;
    }
    return *this;
}

bool StudyGroup::operator<(const StudyGroup& St) const {
    return Student.size() < St.Student.size();
}

bool StudyGroup::operator>(const StudyGroup& St) const {
    return Student.size() < St.Student.size();
}

bool StudyGroup::operator == (const StudyGroup& St) const {
    return Group == St.Group;
}

bool StudyGroup::operator != (const StudyGroup& St) const {
    return !(operator == (St));
}

void StudyGroup::Add(const Students& St) {
    if (HasLink(St) == true) {
        throw StudentAlreadyExist(St.GetSecondName(), St.GetFirstName(),
            St.GetPatronymic());
    }
    Student.push_back(St);
}

Students& StudyGroup::GetLink(const string& SN, const string& FN,
    const string& PT) {
        if (Student.size() == 0) {
        throw NoAnyStudents(Group);
        }
        for (list<Students>::iterator it = Student.begin();
        it != Student.end(); it++) {
            if ((it->GetFirstName() == FN) && (it->GetSecondName() == SN) &&
                (it->GetPatronymic() == PT)) {
                    return (*it);
            }
        }
        throw StudentNotFound(SN, FN, PT);
}

void StudyGroup::RemoveByLink(const Students& St) {
    for (list<Students>::iterator it = Student.begin(); it != Student.end();) {
        if ((*it) == St) {
            it = Student.erase(it);
            cout << "Student has been deleted";
        } else {
            it++;
        }
    }
}

void StudyGroup::RemoveByIndex(unsigned int Ind) {
    if (Student.size() == 0) {
        throw NoAnyStudents(Group);
    }
    if (Ind+1 > Student.size()) {
        throw StudentIndexNotFound(Ind);
    }
    list<Students>::iterator it = Student.begin();
    advance(it, Ind);
    Student.erase(it);
}

Students& StudyGroup::Get(unsigned int Index) {
    if (Index+1 > Student.size()) {
        throw StudentIndexNotFound(Index);
    }
    list<Students>::iterator it = Student.begin();
    advance(it, Index);
    return (*it);
}
