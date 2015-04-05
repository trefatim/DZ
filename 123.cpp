#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <list>
#include <iterator>
#include "Exceptions.h"
#include "Group.h"
#include "Student.h"
using namespace std;

int FindGroup(string gr, list<StudyGroup> l)
{
	int k=0;
	for (list<StudyGroup>::iterator i=l.begin(); i!=l.end(); i++)
	{
		if(gr==i->GetGroupName())
		{
			k=1;
		}
	}
	return k;
}

int main(int argc, char * argv[])
{
	setlocale(LC_ALL,"rus");
	int a, *points, index, count=0;
	string Grou, Cura, *Subj, Sub, FN, SN, PT;
	char c;
	list <StudyGroup> MyList;
	while (1)
	{
		system("cls");
		cout<<"0:Добавить группу\n";
		cout<<"1:Добавить студента\n";
		cout<<"2:Печать\n";
		cout<<"3:Удалить группу\n";
		cout<<"4:Удалить студента по ссылке\n";
		cout<<"5:Должники\n";
		cout<<"6:Отличники\n";
		cout<<"7:Средний балл по всем предметам\n";
		cout<<"8:Средний балл до однму прдемету\n";
		cout<<"9:Удалить студента по порядоковому номеру\n";
		cout<<"e:Выход\n";
		c=_getch();
		switch (c)
		{
		case '0':
			{
				fflush(stdin);
				cout<<"Введите название группы:"<<endl;
				getline(cin,Grou);
				try
				{
					if(FindGroup(Grou,MyList)==1)
					{
						throw GroupAlreadyExist();
					}
					cout<<"Введите ФИО куратора:"<<endl;
					getline(cin,Cura);
					cout<<"Введите кол-во предметов:"<<endl;
					cin>>a;
					Subj=new string[a];
					cout<<"Введите список предметов:"<<endl;
					fflush(stdin);
					for (int i=0; i<a; i++)
					{
						getline(cin,Subj[i]);
					}
					StudyGroup gruppa(a,Grou,Cura,Subj);
					MyList.push_back(gruppa);
					count++;
					delete []Subj;
					cout<<"Группа добавлена";
					system("pause");
					break;
				}
				catch(GroupAlreadyExist &mm)
				{
					cout<<mm.what()<<"\n";
				}
				system("pause");
				break;
			}

		case '1':
			{
				try
				{
					if(MyList.empty())
					{
						throw NoAnyGroup();
					}
					cout<<"Введите группу, куда добавить студента:";
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (FindGroup(Grou, MyList)!=1)
						{
							throw GroupNotFound();
						}
						for (list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end(); i++)
						{
							if(i->GetGroupName()==Grou)
							{
								a=i->GetNumOfSubjects();
								cout<<"Введите фамилию студента:";
								fflush(stdin);
								getline(cin,SN);
								cout<<"Введите имя студента:";
								fflush(stdin);
								getline(cin,FN);
								cout<<"Введите отчество студента:";
								fflush(stdin);
								getline(cin,PT);
								points=new int[a];
								cout<<"Введите баллы\n";
								for(int j=0; j<a; j++)
								{
									cout<<i->GetSubject(j)<<" ";
									fflush(stdin);
									cin>>points[j];
								}
								Students st(FN, SN, PT, points,a);
								try
								{
									if (i->HasLink(st)==true)
									{
										throw StudentAlreadyExist();
									}
									i->Add(st);
									
									cout<<"Студент добавлен\n";
								}
								catch(StudentAlreadyExist &m)
								{
									cout<<m.what();
								}
							}
						}
					}
					catch(GroupNotFound &s)
					{
						cout<<s.what();
					}
				}
				catch(NoAnyGroup &c)
				{
					cout<<c.what();
				}
				system("pause");
				break;
			}

		case '2':
			try
			{
				if(MyList.empty())
				{
					throw NoAnyGroup();
				}
				for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end(); i++)
				{
					cout<<i;
				}
			}
			catch(NoAnyGroup &c)
			{
				cout<<c.what();
			}
			system("pause");
			break;

		case '3':
			{
				try
				{
					if(MyList.empty())
					{
						throw NoAnyGroup();
					}	
					cout<<"Введите группу: ";
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if(FindGroup(Grou, MyList)==0)
						{
							throw GroupNotFound();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();)
						{
							if (i->GetGroupName()==Grou)
							{
								i=MyList.erase(i);
							}
							else
							{
								i++;
							}
						}
						cout<<"Группа удалена";
					}
					catch(GroupNotFound &s)
					{
						cout<<s.what();
					}
				}
				catch(NoAnyGroup &c)
				{
					cout<<c.what();
				}
				system("pause");
				break;
			}

		case '4':
			{
				try
				{
					if(MyList.empty())
					{
						throw NoAnyGroup();
					}
					cout<<"Введите группу, из которой удалить студента: ";\
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (FindGroup(Grou, MyList)==0)
						{
							throw GroupNotFound();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->GetGroupName()==Grou)
							{
								cout<<"Введите фамилию студента: ";
								fflush(stdin);
								getline(cin,SN);
								cout<<"Введите имя студента: ";
								fflush(stdin);
								getline(cin,FN);
								cout<<"Введите отчество студента: ";
								fflush(stdin);
								getline(cin,PT);
								try
								{
									if(i->Has(SN,FN,PT)==false)
									{
										throw StudentNotFound();
									}
									Students s=i->GetLink(SN,FN,PT);
									i->RemoveByLink(s);
								}
								catch(StudentNotFound &zz)
								{
									cout<<zz.what()<<"\n";
								}
							}
						}
					}
					catch(GroupNotFound &s)
					{
						cout<<s.what();
					}
				}
				catch(NoAnyGroup &c)
				{
					cout<<c.what();
				}
				system("pause");
				break;
			}

		case '5':
			{
				try
				{
					if(MyList.empty())
					{
						throw NoAnyGroup();
					}
					cout<<"Введите группу, в которой искать должников: ";\
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (FindGroup(Grou, MyList)==0)
						{
							throw GroupNotFound();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->GetGroupName()==Grou)
							{
								i->FindDuty();
							}
						}
					}
					catch(GroupNotFound &s)
					{
						cout<<s.what();
					}
				}
				catch(NoAnyGroup &c)
				{
					cout<<c.what();
				}
				system("pause");
				break;
			}
	
		case '6':
			{
				try
				{
					if(MyList.empty())
					{
						throw NoAnyGroup();
					}
					cout<<"Введите группу, в которой искать отличников: ";
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (FindGroup(Grou, MyList)==0)
						{
							throw GroupNotFound();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->GetGroupName()==Grou)
							{
								i->FindExcellent();
							}
						}
					}
					catch(GroupNotFound &s)
					{
						cout<<s.what();
					}
				}
				catch(NoAnyGroup &c)
				{
					cout<<c.what();
				}
				system("pause");
				break;
			}

		case '7':
			{
				try
				{
					if(MyList.empty())
					{
						throw NoAnyGroup();
					}
					cout<<"Введите группу: ";
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (FindGroup(Grou, MyList)==0)
						{
							throw GroupNotFound();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->GetGroupName()==Grou)
							{
								i->SrAllSubjects();
							}
						}
					}
					catch(GroupNotFound &s)
					{
						cout<<s.what();
					}
				}
				catch(NoAnyGroup &c)
				{
					cout<<c.what();
				}
				system("pause");
				break;
			}

		case '8':
			{
				try
				{
					if(MyList.empty())
					{
						throw NoAnyGroup();
					}
					cout<<"Введите группу: ";
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (FindGroup(Grou, MyList)==0)
						{
							throw GroupNotFound();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->GetGroupName()==Grou)
							{
								cout<<"Введите предмет: ";
								fflush(stdin);
								getline(cin,Sub);
								index=i->FindIndexSubject(Sub);
								try
								{
									if (index==-1)
									{
									throw SubjectNotFound();
									}
									i->SrOneSubject(index);
								}
								catch (SubjectNotFound &gg)
								{
									cout<<gg.what()<<" ";
								}
							}
						}
					}
					catch(GroupNotFound &s)
					{
						cout<<s.what();
					}
				}
				catch(NoAnyGroup &c)
				{
					cout<<c.what();
				}
				system("pause");
				break;
			}

		case '9':
			{
				try
				{
					if(MyList.empty())
					{
						throw NoAnyGroup();
					}
					cout<<"Введите группу, из которой удалить студента: ";\
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (FindGroup(Grou, MyList)==0)
						{
							throw GroupNotFound();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->GetGroupName()==Grou)
							{
								cout<<"Введите порядковый номер студента: ";
								fflush(stdin);
								cin>>a;
								try
								{
									if((a>i->GetNumOfStudents())||(a==0))
									{
										throw StudentIndexNotFound();
									}
									i->RemoveByIndex(a);
								}
								catch(StudentIndexNotFound &ggg)
								{
									cout<<ggg.what()<<" ";
								}
							}
						}
					}
					catch(GroupNotFound &s)
					{
						cout<<s.what();
					}
				}
				catch(NoAnyGroup &c)
				{
					cout<<c.what();
				}
				system("pause");
				break;
			}
	
		case 'e':
			return 0;

		default:
			cout<<"Ошибка, попробуйте еще раз\n";
			system("Pause");
		}
	}
	system("pause");
	return 0;
}
