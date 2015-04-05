#include "Exceptions.h"
#include <iostream>

using namespace std;

const char* NoAnyGroup::what()
{
	return "There's no any group\n";
}

const char* GroupNotFound::what()
{
	return "������ �� �������\n";
}

const char* StudentAlreadyExist::what()
{
	return "������� ��� ����������\n";
}

const char* GroupAlreadyExist::what()
{
	return "������ ��� ����������\n";
}

const char* StudentNotFound::what()
{
	return "������� �� ������\n";
}

const char* SubjectNotFound::what()
{
	return "������� �� ������\n";
}

const char* StudentIndexNotFound::what()
{
	return "������ ���\n";
}