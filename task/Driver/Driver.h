#pragma once
#include "task/GpsReader/GpsReader.h"
#include "task/ImageReader/ImageReader.h"
#include "task/OneValueReader/OneValueReader.h"
#include "task/main/local.h"

class Driver
{
public:
    Driver();
    void Start(string path);
    void startReading(Reader * reader);
};