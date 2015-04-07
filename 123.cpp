// Copyright 2015 <Anton Sidorov>
#include <conio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <iterator>
#include "Exceptions.h"
#include "Group.h"
#include "Student.h"

using std::cout;
using std::cin;
using std::string;
using std::list;
using std::endl;

int FindGroup(string gr, list<StudyGroup> l) {
    int k = 0;
    for (list<StudyGroup>::iterator i = l.begin(); i != l.end(); i++) {
        if (gr == i->GetGroupName()) {
            k = 1;
        }
    }
    return k;
}

int main(int argc, char * argv[]) {
    setlocale(LC_ALL, "rus");
    int a, *points, index, count = 0;
    string Grou, Cura, *Subj, Sub, FN, SN, PT;
    char c;
    list <StudyGroup> MyList;
    while (1) {
        system("cls");
        cout << "0:Add group\n";
        cout << "1:Add student\n";
        cout << "2:Print\n";
        cout << "3:Delete group\n";
        cout << "4:Delete student by link\n";
        cout << "5:Debtors\n";
        cout << "6:Excellent students\n";
        cout << "7:Average score for all subjects\n";
        cout << "8:Average score for one subject\n";
        cout << "9:Delete student by sequence number\n";
        cout << "e:Exit\n";
        c = _getch();
        switch (c) {
        case '0': {
                fflush(stdin);
                cout << "Enter group name:" << endl;
                getline(cin, Grou);
                try {
                    if (FindGroup(Grou, MyList) == 1) {
                        throw GroupAlreadyExist();
                    }
                    cout << "Enter Curatir's FIO:" << endl;
                    getline(cin, Cura);
                    cout << "Enter number of subjects:" << endl;
                    cin  >>  a;
                    Subj = new string[a];
                    cout << "Enter list of subjects:" << endl;
                    fflush(stdin);
                    for (int i = 0; i < a; i++) {
                        getline(cin, Subj[i]);
                    }
                    StudyGroup gruppa(a, Grou, Cura, Subj);
                    MyList.push_back(gruppa);
                    count++;
                    delete []Subj;
                    cout << "Group has been added";
                    system("pause");
                    break;
                }
                catch(GroupAlreadyExist &mm) {
                    cout << mm.what() << "\n";
                }
                system("pause");
                break;
            }

        case '1': {
                try {
                    if (MyList.empty()) {
                        throw NoAnyGroup();
                    }
                    cout << "Enter group:";
                    fflush(stdin);
                    getline(cin, Grou);
                    try {
                        if (FindGroup(Grou, MyList) != 1) {
                            throw GroupNotFound();
                        }
                        for (list<StudyGroup>::iterator i=MyList.begin();
                            i != MyList.end(); i++) {
                            if (i->GetGroupName() == Grou) {
                                a = i->GetNumOfSubjects();
                                cout << "Enter student's second name:";
                                fflush(stdin);
                                getline(cin, SN);
                                cout << "Enter student's first name:";
                                fflush(stdin);
                                getline(cin, FN);
                                cout << "Enter student's pathronymic:";
                                fflush(stdin);
                                getline(cin, PT);
                                points = new int[a];
                                cout << "Enter points\n";
                                for (int j=0; j < a; j++) {
                                    cout << i->GetSubject(j) << " ";
                                    fflush(stdin);
                                    cin >> points[j];
                                }
                                Students st(FN, SN, PT, points, a);
                                try {
                                    if (i->HasLink(st) == true) {
                                        throw StudentAlreadyExist();
                                    }
                                    i->Add(st);
                                    cout << "Student has been added\n";
                                }
                                catch(StudentAlreadyExist &m) {
                                    cout << m.what();
                                }
                            }
                        }
                    }
                    catch(GroupNotFound &s) {
                        cout << s.what();
                    }
                }
                catch(NoAnyGroup &c) {
                    cout << c.what();
                }
                system("pause");
                break;
            }

        case '2':
            try {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                for (list<StudyGroup>::iterator i=MyList.begin();
                    i != MyList.end(); i++) {
                    cout << i;
                }
            }
            catch(NoAnyGroup &c) {
                cout << c.what();
            }
            system("pause");
            break;

        case '3': {
                try {
                    if (MyList.empty()) {
                        throw NoAnyGroup();
                    }
                    cout << "Enter group: ";
                    fflush(stdin);
                    getline(cin, Grou);
                    try {
                        if (FindGroup(Grou, MyList) == 0) {
                            throw GroupNotFound();
                        }
                        for (list<StudyGroup>::iterator i = MyList.begin();
                            i != MyList.end();) {
                            if (i->GetGroupName() == Grou) {
                                i = MyList.erase(i);
                            } else {
                                i++;
                            }
                        }
                        cout << "Group has been deleted";
                    }
                    catch(GroupNotFound &s) {
                        cout << s.what();
                    }
                }
                catch(NoAnyGroup &c) {
                    cout << c.what();
                }
                system("pause");
                break;
            }

        case '4': {
                try {
                    if (MyList.empty()) {
                        throw NoAnyGroup();
                    }
                    cout << "Enter group: ";
                    fflush(stdin);
                    getline(cin, Grou);
                    try {
                        if (FindGroup(Grou, MyList) == 0) {
                            throw GroupNotFound();
                        }
                        for (list<StudyGroup>::iterator i = MyList.begin();
                            i != MyList.end(); i++) {
                            if (i->GetGroupName() == Grou) {
                                cout << "Enter student's second name: ";
                                fflush(stdin);
                                getline(cin, SN);
                                cout << "Enter student's first name: ";
                                fflush(stdin);
                                getline(cin, FN);
                                cout << "Enter student's pathronymic: ";
                                fflush(stdin);
                                getline(cin, PT);
                                try {
                                    if (i->Has(SN, FN, PT) == false) {
                                        throw StudentNotFound();
                                    }
                                    Students s = i->GetLink(SN, FN, PT);
                                    i->RemoveByLink(s);
                                }
                                catch(StudentNotFound &zz) {
                                    cout << zz.what() << "\n";
                                }
                            }
                        }
                    }
                    catch(GroupNotFound &s) {
                        cout << s.what();
                    }
                }
                catch(NoAnyGroup &c) {
                    cout << c.what();
                }
                system("pause");
                break;
            }

        case '5': {
                try {
                    if (MyList.empty()) {
                        throw NoAnyGroup();
                    }
                    cout << "Enter group: ";
                    fflush(stdin);
                    getline(cin, Grou);
                    try {
                        if (FindGroup(Grou, MyList) == 0) {
                            throw GroupNotFound();
                        }
                        for (list<StudyGroup>::iterator i = MyList.begin();
                            i != MyList.end(); i++) {
                            if (i->GetGroupName() == Grou) {
                                i->FindDuty();
                            }
                        }
                    }
                    catch(GroupNotFound &s) {
                        cout << s.what();
                    }
                }
                catch(NoAnyGroup &c) {
                    cout << c.what();
                }
                system("pause");
                break;
            }

        case '6': {
                try {
                    if (MyList.empty()) {
                        throw NoAnyGroup();
                    }
                    cout << "Enter group: ";
                    fflush(stdin);
                    getline(cin, Grou);
                    try {
                        if (FindGroup(Grou, MyList) == 0) {
                            throw GroupNotFound();
                        }
                        for (list<StudyGroup>::iterator i = MyList.begin();
                            i != MyList.end(); i++) {
                            if (i->GetGroupName() == Grou) {
                                i->FindExcellent();
                            }
                        }
                    }
                    catch(GroupNotFound &s) {
                        cout << s.what();
                    }
                }
                catch(NoAnyGroup &c) {
                    cout << c.what();
                }
                system("pause");
                break;
            }

        case '7': {
                try {
                    if (MyList.empty()) {
                        throw NoAnyGroup();
                    }
                    cout << "Enter group: ";
                    fflush(stdin);
                    getline(cin, Grou);
                    try {
                        if (FindGroup(Grou, MyList) == 0) {
                            throw GroupNotFound();
                        }
                        for (list<StudyGroup>::iterator i = MyList.begin();
                            i != MyList.end(); i++) {
                            if (i->GetGroupName() == Grou) {
                                i->SrAllSubjects();
                            }
                        }
                    }
                    catch(GroupNotFound &s) {
                        cout << s.what();
                    }
                }
                catch(NoAnyGroup &c) {
                    cout << c.what();
                }
                system("pause");
                break;
            }

        case '8': {
                try {
                    if (MyList.empty()) {
                        throw NoAnyGroup();
                    }
                    cout << "Enter group: ";
                    fflush(stdin);
                    getline(cin, Grou);
                    try {
                        if (FindGroup(Grou, MyList) == 0) {
                            throw GroupNotFound();
                        }
                        for (list<StudyGroup>::iterator i = MyList.begin();
                            i != MyList.end(); i++) {
                            if (i->GetGroupName() == Grou) {
                                cout << "Enter subject: ";
                                fflush(stdin);
                                getline(cin, Sub);
                                index = i->FindIndexSubject(Sub);
                                try {
                                    if (index == -1) {
                                    throw SubjectNotFound();
                                    }
                                    i->SrOneSubject(index);
                                }
                                catch (SubjectNotFound &gg) {
                                    cout << gg.what() << " ";
                                }
                            }
                        }
                    }
                    catch(GroupNotFound &s) {
                        cout << s.what();
                    }
                }
                catch(NoAnyGroup &c) {
                    cout << c.what();
                }
                system("pause");
                break;
            }

        case '9': {
                try {
                    if (MyList.empty()) {
                        throw NoAnyGroup();
                    }
                    cout << "Enter group: ";\
                    fflush(stdin);
                    getline(cin, Grou);
                    try {
                        if (FindGroup(Grou, MyList) == 0) {
                            throw GroupNotFound();
                        }
                        for (list<StudyGroup>::iterator i = MyList.begin();
                            i != MyList.end(); i++) {
                            if (i->GetGroupName() == Grou) {
                                cout << "Enter sequence number: ";
                                fflush(stdin);
                                cin >> a;
                                try {
                                    if ((a > i->GetNumOfStudents()) ||
                                        (a == 0)) {
                                        throw StudentIndexNotFound();
                                    }
                                    i->RemoveByIndex(a);
                                }
                                catch(StudentIndexNotFound &ggg) {
                                    cout << ggg.what() << " ";
                                }
                            }
                        }
                    }
                    catch(GroupNotFound &s) {
                        cout << s.what();
                    }
                }
                catch(NoAnyGroup &c) {
                    cout << c.what();
                }
                system("pause");
                break;
            }

        case 'e':
            return 0;

        default:
            cout << "Error, try again\n";
            system("Pause");
        }
    }
    system("pause");
    return 0;
}

