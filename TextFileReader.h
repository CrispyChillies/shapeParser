#pragma once

#include <string>

using namespace std;

class TextFileReader
{
protected:
    string _fileName;

public:
    virtual string read() = 0;
    inline void setFileName(string fileName)
    {
        _fileName = fileName;
    }
};

class TextFileLineReader : public TextFileReader
{
public:
    string read();
};
