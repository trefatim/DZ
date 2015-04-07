// Copyright 2015 <Anton Sidorov>
#include <iostream>
#include "Exceptions.h"

using std::cout;
using std::cin;

const char* NoAnyGroup::what() {
    return "There's no any group\n";
}

const char* GroupNotFound::what() {
    return "Group not found\n";
}

const char* StudentAlreadyExist::what() {
    return "Student already exists\n";
}

const char* GroupAlreadyExist::what() {
    return "Group already exists\n";
}

const char* StudentNotFound::what() {
    return "Student not found\n";
}

const char* SubjectNotFound::what() {
    return "Subject not found\n";
}

const char* StudentIndexNotFound::what() {
    return "Index not found\n";
}
