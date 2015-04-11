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
    explicit StudentIndexNotFound(const int ind);
    const char* what() const;
};

class NoAnyDebtors : public exception {
 public:
    const char* what() const;
};

class NoAnyExcellentStudent : public exception {
 public:
    const char* what() const;
};

class AssignmentError : public exception {
 public:
    const char* what() const;
};
