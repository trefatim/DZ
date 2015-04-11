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
using std::exception;

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
    int point, a, index, count = 0;
    string Grou, Cura, Sub, FN, SN, PT;
    char c;
    list <StudyGroup> MyList;
    list <Students> List;
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
        try {
            switch (c) {
            case '0': {
                fflush(stdin);
                cout << "Enter group name:" << endl;
                getline(cin, Grou);
                if (FindGroup(Grou, MyList) == 1) {
                    throw GroupAlreadyExist(Grou);
                }
                cout << "Enter Curator's FIO:" << endl;
                getline(cin, Cura);
                cout << "Enter number of subjects:" << endl;
                cin  >>  a;
                list<string> Subj;
                string Subject;
                cout << "Enter list of subjects:" << endl;
                fflush(stdin);
                for (int i = 0; i < a; i++) {
                    getline(cin, Subject);
                    Subj.push_back(Subject);
                }
                StudyGroup gruppa(a, Grou, Cura, Subj);
                MyList.push_back(gruppa);
                count++;
                cout << "Group has been added";
                system("pause");
                break;
                    }

            case '1': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                cout << "Enter group:";
                fflush(stdin);
                getline(cin, Grou);
                if (FindGroup(Grou, MyList) == 0) {
                    throw GroupNotFound(Grou);
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
                        list <int> points;
                        cout << "Enter points\n";
                        for (int j=0; j < a; j++) {
                            cout << i->GetSubject(j) << " ";
                            fflush(stdin);
                            cin >> point;
                            points.push_back(point);
                        }
                        Students st(FN, SN, PT, points, a);
                        i->Add(st);
                        cout << "Student has been added\n";
                    }
                }
                system("pause");
                break;
                      }

            case '2':
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                for (list<StudyGroup>::iterator i=MyList.begin();
                    i != MyList.end(); i++) {
                        cout << i;
                }
                system("pause");
                break;

            case '3': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                cout << "Enter group: ";
                fflush(stdin);
                getline(cin, Grou);
                if (FindGroup(Grou, MyList) == 0) {
                    throw GroupNotFound(Grou);
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
                system("pause");
                break;
                      }

            case '4': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                cout << "Enter group: ";
                fflush(stdin);
                getline(cin, Grou);
                if (FindGroup(Grou, MyList) == 0) {
                    throw GroupNotFound(Grou);
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
                        Students s = i->GetLink(SN, FN, PT);
                        i->RemoveByLink(s);
                        }
                }
                system("pause");
                break;
                      }

            case '5': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                cout << "Enter group: ";
                fflush(stdin);
                getline(cin, Grou);
                if (FindGroup(Grou, MyList) == 0) {
                    throw GroupNotFound(Grou);
                }
                for (list<StudyGroup>::iterator i = MyList.begin();
                    i != MyList.end(); i++) {
                        if (i->GetGroupName() == Grou) {
                            List = i->FindDuty();
                            for (list<Students>::iterator it = List.begin();
                                it != List.end(); ++it) {
                                    cout << it->GetSecondName() << " "
                                    << it->GetFirstName() << " "
                                    << it->GetPatronymic() << "\n";
                            }
                        }
                }
                system("pause");
                break;
                      }

            case '6': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                cout << "Enter group: ";
                fflush(stdin);
                getline(cin, Grou);
                if (FindGroup(Grou, MyList) == 0) {
                    throw GroupNotFound(Grou);
                }
                for (list<StudyGroup>::iterator i = MyList.begin();
                    i != MyList.end(); i++) {
                        if (i->GetGroupName() == Grou) {
                            List = i->FindExcellent();
                            for (list<Students>::iterator it = List.begin();
                                it != List.end(); ++it) {
                                    cout << it->GetSecondName() << " "
                                    << it->GetFirstName() << " "
                                    << it->GetPatronymic() << "\n";
                            }
                        }
                }
                system("pause");
                break;
                      }

            case '7': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                cout << "Enter group: ";
                fflush(stdin);
                getline(cin, Grou);
                if (FindGroup(Grou, MyList) == 0) {
                    throw GroupNotFound(Grou);
                }
                for (list<StudyGroup>::iterator i = MyList.begin();
                    i != MyList.end(); i++) {
                        if (i->GetGroupName() == Grou) {
                        i->SrAllSubjects();
                    }
                }
                system("pause");
                break;
                      }

            case '8': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                cout << "Enter group: ";
                fflush(stdin);
                getline(cin, Grou);
                if (FindGroup(Grou, MyList) == 0) {
                    throw GroupNotFound(Grou);
                }
                for (list<StudyGroup>::iterator i = MyList.begin();
                    i != MyList.end(); i++) {
                        if (i->GetGroupName() == Grou) {
                            cout << "Enter subject: ";
                            fflush(stdin);
                            getline(cin, Sub);
                            index = i->FindIndexSubject(Sub);
                            i->SrOneSubject(index);
                        }
                }
                system("pause");
                break;
                      }

            case '9': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                cout << "Enter group: ";\
                fflush(stdin);
                getline(cin, Grou);
                if (FindGroup(Grou, MyList) == 0) {
                    throw GroupNotFound(Grou);
                }
                for (list<StudyGroup>::iterator i = MyList.begin();
                    i != MyList.end(); i++) {
                        if (i->GetGroupName() == Grou) {
                            cout << "Enter sequence number: ";
                            fflush(stdin);
                            cin >> a;
                            i->RemoveByIndex(a);
                            cout << "Student has been deleted";
                        }
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
        catch(exception &ex) {
            cout << ex.what();
            system("pause");
        }
    }
    system("pause");
    return 0;
}

