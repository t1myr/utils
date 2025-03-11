#pragma once

#include <exception>
#include <string>
#include "source_location.hpp"

class MyException : public std::exception
{
public:
    MyException(int _a, const source_location& _localtion = source_location::current()) noexcept : a(_a), location(_localtion)
    {
        comment = std::to_string(a) + " Line: " + std::to_string(location.line) + ", Func: " + location.func + ", File: " + location.file;
    }

    virtual const char* what() const noexcept override
    {
        return comment.c_str();
    }

private:
    int a;
    source_location location;
    std::string comment;
};