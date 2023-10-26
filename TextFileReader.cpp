#include "TextFileReader.h"
#include <fstream>

string TextFileLineReader::read()
{
    ifstream inf(_fileName);
    string buffer;
    getline(inf,buffer);    
    return buffer;
}