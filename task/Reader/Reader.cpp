#include "Reader.h"

    Reader::Reader (string path)
        :path_(path)
    {
    }
    Reader::Reader ()
    {
    }

    string Reader::getPath(){
        return path_;
    }

    Types* Reader::getAllData(){
        return allData_;
    }

    //  Getter for Timestamp
    vector<long long > Reader::getTimestamp ()
    {
        return timestamp_;
    }

