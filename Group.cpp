#include "Group.h"
#include <string>
#include <conio.h>
#include <list>
#include <iterator>
#include <iostream>
using namespace std;

StudyGroup::StudyGroup()
{
	NumOfStud=0;
	NumOfSubj=0;
	Group="";
	Curator="";
	Subjects=NULL;
}

StudyGroup::StudyGroup(const int &NoSub,const string &Gr,const string &Cur,string *Sub)
{
	NumOfSubj=NoSub;
	NumOfStud=0;
	Group=Gr;
	Curator=Cur;
	Subjects= new string[NoSub];
	for (int i=0; i<NoSub; i++)
	{
		Subjects[i]=Sub[i];
	}
}

StudyGroup::StudyGroup(const StudyGroup &st)
{
	NumOfStud=st.NumOfStud;
	NumOfSubj=st.NumOfSubj;
	Group=st.Group;
	Curator=st.Curator;
	Subjects=new string[NumOfSubj];
	for (int i=0; i<NumOfSubj; i++)
	{
		Subjects[i]=st.Subjects[i];
	}
	list<Students> l=st.student;
	string FN,SN,PT;
	for(list<Students>::iterator it=l.begin(); it!=l.end(); it++)
	{
		FN=it->get_FirstName();
		SN=it->get_SecondName();
		PT=it->get_Patronymic();
		int *point=new int[NumOfSubj];
		for(int i=0;i<NumOfSubj;i++)
		{
			point[i]=it->get_StudentPoints()[i];
		}
		Students s(FN,SN,PT,point,NumOfSubj);
		student.push_back(s);
	}
}

StudyGroup::~StudyGroup()
{
	delete []Subjects;
}

int StudyGroup::getCount()const
{
	return NumOfStud;
}

string StudyGroup::get_GroupName() const
{
	return Group;
}

int StudyGroup::get_NumOfSubj() const
{
	return NumOfSubj;
}

void StudyGroup::set_NumOfStud(const int &n)
{
	NumOfStud=n;
}

bool StudyGroup::has(const string &SN,const string &FN,const string &PT,list<Students> l)
{
	for (list<Students>::iterator i=l.begin(); i!=l.end(); i++)
	{
		if ((i->get_SecondName()==SN)&&(i->get_FirstName()==FN)&&(i->get_Patronymic()==PT))
		{
			return true;
		}
	}
	return false;
}

string StudyGroup::get_Subject(const int &n)const
{
	return Subjects[n];
}

int StudyGroup::find_Sub(const string &Sub, list<StudyGroup>::iterator it)
{
	for (int i=0; i<it->NumOfSubj; i++)
	{
		if (Sub==it->Subjects[i])
		{
			return i;
		}
	}
	return -1;
}

ostream& operator <<(ostream &out, list<StudyGroup>::iterator it)
{
	cout<<"\nГруппа: "<<it->Group;
	cout<<"\nКуратор: "<<it->Curator;
	cout<<"\nКол-во студентов: "<<it->NumOfStud;
	cout<<"\nКол-во предметов: "<<it->NumOfSubj;
	cout<<"\nПредметы: ";
	for(int i=0; i<it->NumOfSubj; i++)
	{
		cout<<it->Subjects[i]<<" ";
	}
	list <Students> l=it->get_list();
	for(list<Students>::iterator j=l.begin(); j!=l.end(); j++)
	{
		cout<<"\nСтудент: "<<j->get_SecondName()<<" "
			<<j->get_FirstName()<<" "<< j->get_Patronymic();
		cout<<"\nБаллы: ";
		int *arr=j->get_StudentPoints();
		for(int i=0; i<it->get_NumOfSubj(); i++)
		{
			cout<<arr[i]<<" ";
		}
	}
	cout<<"\n";
	return out;
}

list <Students> StudyGroup::get_list()
{
	return student;
}

void StudyGroup::set_list(list<Students> lis)
{
	student=lis;
}

void StudyGroup::find_Duty(list<Students> l,const int &n)
{
	int k,k1=0,*arr;
	for(list<Students>::iterator i=l.begin(); i!=l.end();i++)
	{
		k=0;
		arr=i->get_StudentPoints();
		for (int j=0; j<n; j++)
		{
			if (arr[j]<60)
			{
				k=1;
				k1++;
			}
		}
		if (k==1)
		{
			cout<<i->get_SecondName()<<" "<<i->get_FirstName()<<" "<<i->get_Patronymic()<<"\n";
		}
	}
	if(k1==0)
	{
		cout<<"Должников нет";
	}
}

void StudyGroup::find_Excellent(list<Students> l, int n)
{
	int k, k1=0, *arr;
	for(list<Students>::iterator i=l.begin(); i!=l.end();i++)
	{
		k=0;
		arr=i->get_StudentPoints();
		for (int j=0; j<n; j++)
		{
			if (arr[j]>=85)
			{
				k++;
			}
		}
		if (k==n)
		{
			cout<<i->get_SecondName()<<" "<<i->get_FirstName()<<" "<<i->get_Patronymic()<<"\n";
			k1++;
		}
	}
	if(k1==0)
	{
		cout<<"Отличников нет";
	}
}
	
void StudyGroup::srAllSub(list<Students> l,const int &nSub,const int &nStud)
{
	if(nStud==0)
	{
		cout<<"В группе нет студентов";
	}
	else
	{
		int k=0,*arr;
		float sr=0;
		for(list<Students>::iterator i=l.begin(); i!=l.end();i++)
		{
			k=0;
			arr=i->get_StudentPoints();
			for (int j=0; j<nSub; j++)
			{
				k+=arr[j];
			}
			sr=sr+(k/nSub);
		}
		sr/=nStud;
		cout<<sr;
	}
}

void StudyGroup::srOneSub(list<Students> l,const int &nStud,const int &ind)
{
	if(nStud==0)
	{
		cout<<"В группе нет студентов";
	}
	else
	{
		float sr=0;
		int *arr;
		for(list<Students>::iterator i=l.begin(); i!=l.end();i++)
		{
			arr=i->get_StudentPoints();
			sr+=arr[ind];
		}
		sr/=nStud;
		cout<<sr;
	}
}

StudyGroup& StudyGroup::operator =(const StudyGroup& st)
{
	NumOfStud=st.NumOfStud;
	NumOfSubj=st.NumOfSubj;
	Group=st.Group;
	Curator=st.Curator;
	Subjects=new string[NumOfSubj];
	for (int i=0; i<NumOfSubj; i++)
	{
		Subjects[i]=st.Subjects[i];
	}
	list<Students> l=st.student;
	string FN,SN,PT;
	for(list<Students>::iterator it=l.begin(); it!=l.end(); it++)
	{
		FN=it->get_FirstName();
		SN=it->get_SecondName();
		PT=it->get_Patronymic();
		int *point=new int[NumOfSubj];
		for(int i=0;i<NumOfSubj;i++)
		{
			point[i]=it->get_StudentPoints()[i];
		}
		Students s(FN,SN,PT,point,NumOfSubj);
		student.push_back(s);
	}
	return *this;
}

bool StudyGroup::operator<(const StudyGroup &st)
{
	return NumOfStud<st.NumOfStud;
}

bool StudyGroup::operator>(const StudyGroup &st)
{
	return NumOfStud>st.NumOfStud;
}

bool StudyGroup::operator==(const StudyGroup &st)
{
	return NumOfStud==st.NumOfStud;
}

bool StudyGroup::operator!=(const StudyGroup &st)
{
	return !(operator==(st));
}

void StudyGroup::add(const Students &st, list<StudyGroup>::iterator it)
{
	int a;
	list<Students> l;
	l=it->get_list();
	l.push_back(st);
	it->set_list(l);
	a=it->getCount();
	a++;
	it->set_NumOfStud(a);
	l.push_back(st);
}

Students& StudyGroup::get(const int& i, list<Students> l)
{
	static Students st;
	int j=0;
	for(list<Students>::iterator it=l.begin(); it!=l.end(); it++)
	{
		j++;
		if(j==i)
		{
			st=*it;
		}
	}
	return st;
}

void StudyGroup::remove(const Students &st, list<Students> l, list<StudyGroup>::iterator itt)
{
	for (list<Students>::iterator it=l.begin(); it!=l.end();)
	{
		if (*it==st)
		{
			it=l.erase(it);
			itt->set_list(l);
			int a=itt->getCount();
			a--;
			itt->set_NumOfStud(a);
			cout<<"Студент удален";
		}
		else
		{
			it++;
		}
	}
}

void StudyGroup::remoove(const int &i, list<Students> l, list<StudyGroup>::iterator itt)
{
	int j=0;
	for(list<Students>::iterator it=l.begin(); it!=l.end();)
	{
		j++;
		if(j==i)
		{
			it=l.erase(it);
			itt->set_list(l);
			int a=itt->getCount();
			a--;
			itt->set_NumOfStud(a);
			cout<<"Студент удален";
		}
		else
		{
			it++;
		}
	}
}