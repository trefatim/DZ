#include "Student.h"
#include <iostream>
using namespace std;

Students::Students()
{
	points=NULL;
	NumOfSub=0;
	FirstName="";
	SecondName="";
	Patronymic="";
}

Students::Students(const string &FirstName,const string &SecondName,const string &Patronymic, int* points,const int &N)
{
	NumOfSub=N;
	this->FirstName=FirstName;
	this->SecondName=SecondName;
	this->Patronymic=Patronymic;
	this->points = new int[N];
	for(int i=0; i<N; i++)
	{
		this->points[i]=points[i];
	}
}

Students::Students(const Students &st)
{
	NumOfSub=st.NumOfSub;
	FirstName=st.FirstName;
	SecondName=st.SecondName;
	Patronymic=st.Patronymic;
	points=new int[NumOfSub];
	for(int i=0; i<NumOfSub; i++)
	{
		points[i]=st.points[i];
	}
}

Students::~Students()
{
	delete []points;
}

string Students::get_FirstName() const
{
	return FirstName;
}
string Students::get_SecondName() const
{
	return SecondName;
}
string Students::get_Patronymic() const
{
	return Patronymic;
}

int* Students::get_StudentPoints() const
{
	return points;
}

Students& Students::operator=(const Students &st)
{
	FirstName=st.FirstName;
	SecondName=st.SecondName;
	Patronymic=st.Patronymic;
	NumOfSub=st.NumOfSub;
	points=new int[NumOfSub];
	for(int i=0; i<NumOfSub; i++)
	{
		points[i]=st.points[i];
	}
	return *this;
}

bool Students::operator<(const Students &st)
{
	float sr1=0,sr2=0;
	for (int i=0; i<NumOfSub; i++)
	{
		sr1+=points[i];
	}
	for (int i=0; i<st.NumOfSub; i++)
	{
		sr2+=points[i];
	}
	sr1/=NumOfSub;
	sr2/=st.NumOfSub;
	return sr1<sr2;
}

bool Students::operator>(const Students &st)
{
	float sr1=0,sr2=0;
	for (int i=0; i<NumOfSub; i++)
	{
		sr1+=points[i];
	}
	for (int i=0; i<st.NumOfSub; i++)
	{
		sr2+=points[i];
	}
	sr1/=NumOfSub;
	sr2/=st.NumOfSub;
	return sr1>sr2;
}

bool Students::operator==(const Students &st)
{
	int k=0;
	for (int i=0; i<NumOfSub; i++)
	{
		if(st.points[i]!=points[i])
		{
			k=1;
		}
	}
	if ((st.FirstName==FirstName)&&(st.SecondName==SecondName)&&
		(st.Patronymic==Patronymic)&&(st.NumOfSub==NumOfSub)&&(k==0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Students::operator!=(const Students &st)
{
	return !(operator==(st));
}