// Copyright 2015 <Anton Sidorov>
#pragma once
#include <iostream>
#include <exception>

using std::cout;
using std::cin;
using std::exception;

class NoAnyGroup : public exception {
 public:
    const char* what();
};

class GroupNotFound : public exception {
 public:
    const char* what();
};

class StudentAlreadyExist : public exception {
 public:
    const char* what();
};

class GroupAlreadyExist : public exception {
 public:
    const char* what();
};

class StudentNotFound : public exception {
 public:
    const char* what();
};

class SubjectNotFound : public exception {
 public:
    const char* what();
};

class StudentIndexNotFound : public exception {
 public:
    const char* what();
};
