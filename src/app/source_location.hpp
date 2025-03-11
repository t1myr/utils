#pragma once

struct source_location
{
    source_location(int _line, const char* _func, const char* _file) noexcept : line(_line), func(_func), file(_file)
    {

    }

    static source_location current(int _line = __builtin_LINE(), const char* _func = __builtin_FUNCTION(), const char* _file =  __builtin_FILE()) noexcept
    {
        return source_location(_line, _func, _file);
    }

    int line;
    std::string func;
    std::string file;
};