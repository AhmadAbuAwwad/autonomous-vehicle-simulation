#pragma once
#include "task/Reader/Reader.h"

class GpsReader : public Reader
{
private:
    pair <float, float> location_;

public:
    GpsReader (string path);
    void readFile();
};