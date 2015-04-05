#include "Exceptions.h"
#include <iostream>

using namespace std;

const char* NoAnyGroup::what()
{
	return "There's no any group\n";
}

const char* GroupNotFound::what()
{
	return "Группа не найдена\n";
}

const char* StudentAlreadyExist::what()
{
	return "Студент уже существует\n";
}

const char* GroupAlreadyExist::what()
{
	return "Группа уже существует\n";
}

const char* StudentNotFound::what()
{
	return "Студент не найден\n";
}

const char* SubjectNotFound::what()
{
	return "Предмет не найден\n";
}

const char* StudentIndexNotFound::what()
{
	return "Такого нет\n";
}