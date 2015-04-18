// Copyright 2015 <Anton Sidorov>
#include <iostream>
#include <string>
#include <sstream>
#include "Exceptions.h"

using std::cout;
using std::cin;
using std::string;
using std::stringstream;


const char* NoAnyGroup::what() const {
    return "There's no any group";
}

const char* GroupNotFound::what() const {
    return group.c_str();
}

GroupNotFound::GroupNotFound(const string& gr) {
    group = gr+" group not found";
}

const char* StudentAlreadyExist::what() const {
    return name.c_str();
}

StudentAlreadyExist::StudentAlreadyExist(const string& SN,
    const string& FN, const string& PT) {
    name = "Student "+SN+" "+FN+" "+PT+" already exist";
}

const char* WrongSubjectIndex::what() const {
    return "Wrong subject index";
}

const char* GroupAlreadyExist::what() const {
    return group.c_str();
}

GroupAlreadyExist::GroupAlreadyExist(const string& gr) {
    group = gr+" already exist";
}

const char* StudentNotFound::what() const {
    return name.c_str();
}

StudentNotFound::StudentNotFound(const string& SN, const string& FN,
    const string& PT) {
    name = "Student "+SN+" "+FN+" "+PT+" not found";
}

const char* SubjectNotFound::what() const {
    return subject.c_str();
}

SubjectNotFound::SubjectNotFound(const string& sub) {
    subject = "Subject "+sub+" not found";
}

const char* StudentIndexNotFound::what() const {
    return str.c_str();
}

StudentIndexNotFound::StudentIndexNotFound(int ind) {
    stringstream a;
    a << ind;
    a >> str;
    str+=" index not found";
}

const char* NoAnyDebtors::what() const {
    return "There's no any debtors";
}

const char* NoAnyExcellentStudent::what() const {
    return "There's no any excellent students";
}

NoAnyStudents::NoAnyStudents(const string& Gr) {
    Str = "There's no any students in " + Gr + " group";
}

const char* NoAnyStudents::what() const {
    return Str.c_str();
}
