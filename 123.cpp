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

int FindGroup(string gr, const list<StudyGroup>& l) {
    int k = 0;
    for (list<StudyGroup>::const_iterator i = l.begin(); i != l.end(); i++) {
        if (gr == i->GetGroupName()) {
            k = 1;
        }
    }
    return k;
}

void AddGroup(list<StudyGroup>* Lis) {
    string Grou, Cura;
    int a;
    fflush(stdin);
    cout << "Enter group name:" << endl;
    getline(cin, Grou);
    if (FindGroup(Grou, (*Lis)) == 1) {
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
    StudyGroup Gruppa(Grou, Cura, Subj);
    Lis->push_back(Gruppa);
    cout << "Group has been added" << endl;
}

void AddStudent(list<StudyGroup>* Lis) {
    string Grou, SN, FN, PT;
    int a, Point;
    cout << "Enter group:"<< endl;
    fflush(stdin);
    getline(cin, Grou);
    if (FindGroup(Grou, (*Lis)) == 0) {
        throw GroupNotFound(Grou);
    }
    for (list<StudyGroup>::iterator i=Lis->begin();
        i != Lis->end(); i++) {
            if (i->GetGroupName() == Grou) {
                a = i->GetNumOfSubjects();
                cout << "Enter student's second name:" << endl;
                fflush(stdin);
                getline(cin, SN);
                cout << "Enter student's first name:" << endl;
                fflush(stdin);
                getline(cin, FN);
                cout << "Enter student's pathronymic:" << endl;
                fflush(stdin);
                getline(cin, PT);
                list <int> points;
                cout << "Enter points" << endl;
                for (int j=0; j < a; j++) {
                    cout << i->GetSubject(j) << " " << endl;
                    fflush(stdin);
                    cin >> Point;
                    points.push_back(Point);
                }
                Students st(FN, SN, PT, points);
                i->Add(st);
                cout << "Student has been added\n";
            }
    }
}

void PrintAll(const list<StudyGroup>& Lis) {
    for (list<StudyGroup>::const_iterator i=Lis.begin();
        i != Lis.end(); i++) {
            cout << i;
    }
}

void DeleteGroup(list<StudyGroup>* Lis) {
    string Grou;
    cout << "Enter group: " << endl;
    fflush(stdin);
    getline(cin, Grou);
    if (FindGroup(Grou, (*Lis)) == 0) {
        throw GroupNotFound(Grou);
    }
    for (list<StudyGroup>::iterator i = Lis->begin();
        i != Lis->end();) {
            if (i->GetGroupName() == Grou) {
            i = Lis->erase(i);
            } else {
                i++;
            }
    }
    cout << "Group has been deleted" << endl;
}

void DeleteStudent(list<StudyGroup>* Lis) {
    string Grou, FN, SN, PT;
    cout << "Enter group: " << endl;
    fflush(stdin);
    getline(cin, Grou);
    if (FindGroup(Grou, (*Lis)) == 0) {
        throw GroupNotFound(Grou);
    }
    for (list<StudyGroup>::iterator i = Lis->begin();
        i != Lis->end(); i++) {
            if (i->GetGroupName() == Grou) {
                cout << "Enter student's second name: " << endl;
                fflush(stdin);
                getline(cin, SN);
                cout << "Enter student's first name: " << endl;
                fflush(stdin);
                getline(cin, FN);
                cout << "Enter student's pathronymic: " << endl;
                fflush(stdin);
                getline(cin, PT);
                Students s = i->GetLink(SN, FN, PT);
                i->RemoveByLink(s);
            }
    }
}

void Debtors(const list<StudyGroup>& Lis) {
    string Grou;
    cout << "Enter group: " << endl;
    fflush(stdin);
    getline(cin, Grou);
    if (FindGroup(Grou, Lis) == 0) {
        throw GroupNotFound(Grou);
    }
    for (list<StudyGroup>::const_iterator i = Lis.begin();
        i != Lis.end(); i++) {
            if (i->GetGroupName() == Grou) {
                list<Students> List = i->FindDuty();
                if (List.empty()) {
                    cout << "No any debtors in "
                        << i->GetGroupName() << " group" << endl;
                    return;
                }
                for (list<Students>::iterator it = List.begin();
                    it != List.end(); ++it) {
                        cout << it->GetSecondName() << " "
                            << it->GetFirstName() << " "
                            << it->GetPatronymic() << endl;
                }
            }
    }
}

void Excellent(const list<StudyGroup>& Lis) {
    string Grou;
    cout << "Enter group: " << endl;
    fflush(stdin);
    getline(cin, Grou);
    if (FindGroup(Grou, Lis) == 0) {
        throw GroupNotFound(Grou);
    }
    for (list<StudyGroup>::const_iterator i = Lis.begin();
        i != Lis.end(); i++) {
            if (i->GetGroupName() == Grou) {
                list<Students> List = i->FindExcellent();
                if (List.empty()) {
                    cout << "No any excellent students in "
                        << i->GetGroupName() << " group" << endl;
                    return;
                }
                for (list<Students>::iterator it = List.begin();
                    it != List.end(); ++it) {
                        cout << it->GetSecondName() << " "
                            << it->GetFirstName() << " "
                            << it->GetPatronymic() << endl;
                }
            }
    }
}

void AverageAll(const list<StudyGroup>& Lis) {
    string Grou;
    cout << "Enter group: " << endl;
    fflush(stdin);
    getline(cin, Grou);
    if (FindGroup(Grou, Lis) == 0) {
        throw GroupNotFound(Grou);
    }
    for (list<StudyGroup>::const_iterator i = Lis.begin();
        i != Lis.end(); i++) {
            if (i->GetGroupName() == Grou) {
                i->SrAllSubjects();
            }
    }
}

void AverageOne(const list<StudyGroup>& Lis) {
    string Grou, Sub;
    cout << "Enter group: " << endl;
    fflush(stdin);
    getline(cin, Grou);
    if (FindGroup(Grou, Lis) == 0) {
        throw GroupNotFound(Grou);
    }
    for (list<StudyGroup>::const_iterator i = Lis.begin();
        i != Lis.end(); i++) {
            if (i->GetGroupName() == Grou) {
                cout << "Enter subject: " << endl;
                fflush(stdin);
                getline(cin, Sub);
                int Index = i->FindIndexSubject(Sub);
                i->SrOneSubject(Index);
            }
    }
}

void DeleteStByInd(list<StudyGroup>* Lis) {
    string Grou;
    unsigned int a;
    cout << "Enter group: " << endl;
    fflush(stdin);
    getline(cin, Grou);
    if (FindGroup(Grou, (*Lis)) == 0) {
        throw GroupNotFound(Grou);
    }
    for (list<StudyGroup>::iterator i = Lis->begin();
        i != Lis->end(); i++) {
            if (i->GetGroupName() == Grou) {
                cout << "Enter sequence number: " << endl;
                fflush(stdin);
                cin >> a;
                i->RemoveByIndex(a);
                cout << "Student has been deleted" << endl;
            }
    }
}

int main(int argc, char * argv[]) {
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
        char c = _getch();
        try {
            switch (c) {
            case '0': {
                AddGroup(&MyList);
                system("pause");
                break;
                    }

            case '1': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                AddStudent(&MyList);
                system("pause");
                break;
                      }

            case '2':
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                PrintAll(MyList);
                system("pause");
                break;

            case '3': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                DeleteGroup(&MyList);
                system("pause");
                break;
                      }

            case '4': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                DeleteStudent(&MyList);
                system("pause");
                break;
                      }

            case '5': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                Debtors(MyList);
                system("pause");
                break;
                      }

            case '6': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                Excellent(MyList);
                system("pause");
                break;
                      }

            case '7': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                AverageAll(MyList);
                system("pause");
                break;
                      }

            case '8': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                AverageOne(MyList);
                system("pause");
                break;
                      }

            case '9': {
                if (MyList.empty()) {
                    throw NoAnyGroup();
                }
                DeleteStByInd(&MyList);
                system("pause");
                break;
                      }

            case 'e':
                return 0;

            default:
                cout << "Error, try again" << endl;
                system("Pause");
        }
        }
        catch(exception &ex) {
            cout << ex.what() << endl;
            system("pause");
        }
    }
    system("pause");
    return 0;
}

