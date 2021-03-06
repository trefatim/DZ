// Copyright 2015 <Anton Sidorov>
#pragma once
#include <iostream>
#include <exception>
#include <string>

using std::cout;
using std::cin;
using std::exception;
using std::string;

class NoAnyGroup : public exception {
 public:
    const char* what() const;
};

class GroupNotFound : public exception {
    string group;
 public:
     explicit GroupNotFound(const string& gr);
     const char* what() const;
};

class StudentAlreadyExist : public exception {
    string name;
 public:
     StudentAlreadyExist(const string& SN, const string& FN, const string& PT);
    const char* what() const;
};

class GroupAlreadyExist : public exception {
    string group;
 public:
    explicit GroupAlreadyExist(const string& gr);
    const char* what() const;
};

class WrongSubjectIndex : public exception {
 public:
    const char* what() const;
};

class StudentNotFound : public exception {
    string name;
 public:
     StudentNotFound(const string& SN, const string& FN, const string& PT);
    const char* what() const;
};

class SubjectNotFound : public exception {
    string subject;
 public:
    explicit SubjectNotFound(const string& sub);
    const char* what() const;
};

class StudentIndexNotFound : public exception {
    string str;
 public:
    explicit StudentIndexNotFound(int ind);
    const char* what() const;
};

class NoAnyStudents : public exception {
    string Str;
 public:
    explicit NoAnyStudents(const string& Gr);
    const char* what() const;
};
