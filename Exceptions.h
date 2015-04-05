#include <iostream>
#include <exception>

using namespace std;

class NoAnyGroup : public exception
{
public:
	const char* what();
};

class GroupNotFound : public exception
{
public:
	const char* what(); 
};

class StudentAlreadyExist : public exception
{
public:
	const char* what(); 
};

class GroupAlreadyExist : public exception
{
public:
	const char* what(); 
};

class StudentNotFound : public exception
{
public:
	const char* what(); 
};

class SubjectNotFound : public exception
{
public:
	const char* what(); 
};

class StudentIndexNotFound : public exception
{
public:
	const char* what(); 
};