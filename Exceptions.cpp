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
    return "There's no any group\n";
}

const char* GroupNotFound::what() const {
    return group.c_str();
}

GroupNotFound::GroupNotFound(const string& gr) {
    group = gr+" group not found\n";
}

const char* StudentAlreadyExist::what() const {
    return name.c_str();
}

StudentAlreadyExist::StudentAlreadyExist(const string& SN,
    const string& FN, const string& PT) {
    name = "Student "+SN+" "+FN+" "+PT+" already exist\n";
}

const char* GroupAlreadyExist::what() const {
    return group.c_str();
}

GroupAlreadyExist::GroupAlreadyExist(const string& gr) {
    group = gr+" already exist\n";
}

const char* StudentNotFound::what() const {
    return name.c_str();
}

StudentNotFound::StudentNotFound(const string& SN, const string& FN,
    const string& PT) {
    name = "Student "+SN+" "+FN+" "+PT+" not found\n";
}

const char* SubjectNotFound::what() const {
    return subject.c_str();
}

SubjectNotFound::SubjectNotFound(const string& sub) {
    subject = "Subject "+sub+" not found\n";
}

const char* StudentIndexNotFound::what() const {
    return str.c_str();
}

StudentIndexNotFound::StudentIndexNotFound(const int ind) {
    stringstream a;
    a << ind;
    a >> str;
    str+=" index not found";
}

const char* NoAnyDebtors::what() const {
    return "There's no any debtors\n";
}

const char* NoAnyExcellentStudent::what() const {
    return "There's no any excellent students\n";
}

const char* AssignmentError::what() const {
    return "Assigment error";
}
