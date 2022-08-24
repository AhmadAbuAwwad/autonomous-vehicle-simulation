#pragma once
#include "task/Reader/Reader.h"

class OneValueReader : public Reader
{
private:
    float value_;

public:
    OneValueReader (string path);
     
    void readFile();
};