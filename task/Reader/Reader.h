#pragma once
#include "task/main/local.h"
#include "task/Types/Types.h"
#include "task/ClockManger/ClockManger.h"
#include "task/DataStore/DataStore.h"
#include <opencv2/opencv.hpp>

class Reader
{
protected:
    vector<long long >  timestamp_;
    string path_;
    Types * allData_;

public:
    Reader (string path);
    Reader ();

    string getPath();
    Types* getAllData();
    vector<long long > getTimestamp ();
    virtual void readFile() = 0;
};