#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <list>
#include <iterator>
#include <exception>
#include "Group.h"
#include "Student.h"
using namespace std;

class MyException1 : public exception
{
public:
	string what() 
	{
		return "There's no any group\n";
	}
};

class MyException2 : public exception
{
public:
	const char* what() 
	{
		return "������ �� �������\n";
	}
};

int find_group(string gr, list<StudyGroup> l)
{
	int k=0;
	for (list<StudyGroup>::iterator i=l.begin(); i!=l.end(); i++)
	{
		if(gr==i->get_GroupName())
		{
			k=1;
		}
	}
	return k;
}

int main(int argc, char * argv[])
{
	setlocale(LC_ALL,"rus");
	int a,aa, *points, NumOfSt, index, count=0;
	string Grou, Cura, *Subj, Sub, FN, SN, PT;
	char c;
	list <StudyGroup> MyList;
	list <Students> l;
	while (1)
	{
		system("cls");
		cout<<"0:�������� ������\n";
		cout<<"1:�������� ��������\n";
		cout<<"2:������\n";
		cout<<"3:������� ������\n";
		cout<<"4:������� ��������\n";
		cout<<"5:��������\n";
		cout<<"6:���������\n";
		cout<<"7:������� ���� �� ���� ���������\n";
		cout<<"8:������� ���� �� ����� ��������\n";
		cout<<"9:�������� �������� �� ������\n";
		cout<<"d:�������� �������� �� ������������ ������\n";
		cout<<"e:�����\n";
		c=_getch();
		switch (c)
		{
		case '0':
			{
				fflush(stdin);
				cout<<"������� �������� ������:"<<endl;
				getline(cin,Grou);
				cout<<"������� ��� ��������:"<<endl;
				getline(cin,Cura);
				cout<<"������� ���-�� ���������:"<<endl;
				cin>>a;
				Subj=new string[a];
				cout<<"������� ������ ���������:"<<endl;
				fflush(stdin);
				for (int i=0; i<a; i++)
				{
					getline(cin,Subj[i]);
				}
				StudyGroup gruppa(a,Grou,Cura,Subj);
				MyList.push_back(gruppa);
				count++;
				cout<<"������ ���������";
				break;
			}

		case '1':
			{
				try
				{
					if(MyList.empty())
					{
						throw MyException1();
					}
					cout<<"������� ������, ���� �������� ��������:";
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (find_group(Grou, MyList)!=1)
						{
							throw MyException2();
						}
						for (list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end(); i++)
						{
							if(i->get_GroupName()==Grou)
							{
								a=i->get_NumOfSubj();
								cout<<"������� ������� ��������:";
								fflush(stdin);
								getline(cin,SN);
								cout<<"������� ��� ��������:";
								fflush(stdin);
								getline(cin,FN);
								cout<<"������� �������� ��������:";
								fflush(stdin);
								getline(cin,PT);
								points=new int[a];
								cout<<"������� �����\n";
								for(int j=0; j<a; j++)
								{
									cout<<i->get_Subject(j)<<" ";
									fflush(stdin);
									cin>>points[j];
								}
								Students st(FN, SN, PT, points,a);
								i->add(st,i);
								cout<<"������� ��������\n";
							}
						}
					}
					catch(MyException2 &s)
					{
						cout<<s.what();
					}
				}
				catch(MyException1 &c)
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
					throw MyException1();
				}
				for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end(); i++)
				{
					cout<<i;
				}
			}
			catch(MyException1 &c)
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
						throw MyException1();
					}	
					cout<<"������� ������: ";
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if(find_group(Grou, MyList)==0)
						{
							throw MyException2();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();)
						{
							if (i->get_GroupName()==Grou)
							{
								i=MyList.erase(i);
							}
							else
							{
								i++;
							}
						}
						cout<<"������ �������";
					}
					catch(MyException2 &s)
					{
						cout<<s.what();
					}
				}
				catch(MyException1 &c)
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
						throw MyException1();
					}
					cout<<"������� ������, �� ������� ������� ��������: ";\
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (find_group(Grou, MyList)==0)
						{
							throw MyException2();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->get_GroupName()==Grou)
							{
								cout<<"������� ������� ��������: ";
								fflush(stdin);
								getline(cin,SN);
								cout<<"������� ��� ��������: ";
								fflush(stdin);
								getline(cin,FN);
								cout<<"������� �������� ��������: ";
								fflush(stdin);
								getline(cin,PT);
								l=i->get_list();
								if(i->has(SN,FN,PT,l)==false)
								{
									cout<<"������� �� ������";
								}
								else
								{
									l=i->get_list();
									for(list<Students>::iterator j=l.begin(); j!=l.end();)
									{
										if ((j->get_FirstName()==FN)&&(j->get_SecondName()==SN)&&(j->get_Patronymic()==PT))
										{
											j=l.erase(j);
										}
										else
										{
											j++;
										}
									}
									i->set_list(l);
									a=i->getCount();
									a--;
									i->set_NumOfStud(a);
									cout<<"������� ������";
								}
							}
						}
					}
					catch(MyException2 &s)
					{
						cout<<s.what();
					}
				}
				catch(MyException1 &c)
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
						throw MyException1();
					}
					cout<<"������� ������, � ������� ������ ���������: ";\
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (find_group(Grou, MyList)==0)
						{
							throw MyException2();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->get_GroupName()==Grou)
							{
								l=i->get_list();
								a=i->get_NumOfSubj();
								i->find_Duty(l,a);
							}
						}
					}
					catch(MyException2 &s)
					{
						cout<<s.what();
					}
				}
				catch(MyException1 &c)
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
						throw MyException1();
					}
					cout<<"������� ������, � ������� ������ ����������: ";
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (find_group(Grou, MyList)==0)
						{
							throw MyException2();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->get_GroupName()==Grou)
							{
								l=i->get_list();
								a=i->get_NumOfSubj();
								i->find_Excellent(l,a);
							}
						}
					}
					catch(MyException2 &s)
					{
						cout<<s.what();
					}
				}
				catch(MyException1 &c)
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
						throw MyException1();
					}
					cout<<"������� ������: ";
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (find_group(Grou, MyList)==0)
						{
							throw MyException2();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->get_GroupName()==Grou)
							{
								l=i->get_list();
								a=i->get_NumOfSubj();
								aa=i->getCount();
								i->srAllSub(l,a,aa);
							}
						}
					}
					catch(MyException2 &s)
					{
						cout<<s.what();
					}
				}
				catch(MyException1 &c)
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
						throw MyException1();
					}
					cout<<"������� ������: ";
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (find_group(Grou, MyList)==0)
						{
							throw MyException2();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->get_GroupName()==Grou)
							{
								cout<<"������� �������: ";
								fflush(stdin);
								getline(cin,Sub);
								index=i->find_Sub(Sub,i);
								if (index==-1)
								{
									cout<<"������� �� ������";
								}
								else
								{
									NumOfSt=i->getCount();
									l=i->get_list();
									i->srOneSub(l,NumOfSt,index);
								}	
							}
						}
					}
					catch(MyException2 &s)
					{
						cout<<s.what();
					}
				}
				catch(MyException1 &c)
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
						throw MyException1();
					}
					cout<<"������� ������, �� ������� ������� ��������: ";\
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (find_group(Grou, MyList)==0)
						{
							throw MyException2();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->get_GroupName()==Grou)
							{
								cout<<"������� ���������� ����� ��������: ";
								fflush(stdin);
								cin>>a;
								if((a>i->getCount())||(a==0))
								{
									cout<<"������ ���";
								}
								else
								{
									l=i->get_list();
									Students s=i->get(a,l);
									i->remove(s,l,i);
								}
							}
						}
					}
					catch(MyException2 &s)
					{
						cout<<s.what();
					}
				}
				catch(MyException1 &c)
				{
					cout<<c.what();
				}
				system("pause");
				break;
			}

		case 'd':
			{
				try
				{
					if(MyList.empty())
					{
						throw MyException1();
					}
					cout<<"������� ������, �� ������� ������� ��������: ";\
					fflush(stdin);
					getline(cin,Grou);
					try
					{
						if (find_group(Grou, MyList)==0)
						{
							throw MyException2();
						}
						for(list<StudyGroup>::iterator i=MyList.begin(); i!=MyList.end();i++)
						{
							if(i->get_GroupName()==Grou)
							{
								cout<<"������� ���������� ����� ��������: ";
								fflush(stdin);
								cin>>a;
								if((a>i->getCount())||(a==0))
								{
									cout<<"������ ���";
								}
								else
								{
									l=i->get_list();
									i->remoove(a,l,i);
								}
							}
						}
					}
					catch(MyException2 &s)
					{
						cout<<s.what();
					}
				}
				catch(MyException1 &c)
				{
					cout<<c.what();
				}
				system("pause");
				break;
			}
	
		case 'e':
			return 0;

		default:
			cout<<"������, ���������� ��� ���\n";
			system("Pause");
		}
	}
	system("pause");
	return 0;
}
