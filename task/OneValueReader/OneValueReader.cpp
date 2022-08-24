#include "OneValueReader.h"

    OneValueReader::OneValueReader (string path)
        :Reader(path)
    {
    }
     
    void OneValueReader::readFile()
    {
        string path = getPath();
        string keyString;
        int key = -1;
        
        string pathKey = string(path.rbegin(), path.rend());            
        int position = pathKey.find("/");
        keyString = pathKey.substr (0,position).c_str();
        pathKey = string(keyString.rbegin(), keyString.rend());
        keyString = pathKey.substr(0,pathKey.find("."));
        //  TODO: make it ENUM instead of string
        if(keyString.compare("speed") == 0){
            key = Speed;
        }else if(keyString.compare("steering") == 0){
            key = Steering;
        }else if(keyString.compare("brake") == 0){
            key = Brake;
        }else if(keyString.compare("throttle") == 0){
             key = Throttle;       
        }

        fstream fin;
        fin.open(getPath(), ios::in);

        string line;
        int commaPosition;
        double doubleTimestamp;
        long long longTimestamp;
        getline(fin, line);

        ClockManger * clockManger = ClockManger::getInstance();
        DataStore * dataStore = DataStore::getInstance();
        bool checkManger = true;
        
        while (getline(fin, line)) {
            
            //  getting timestamp
            commaPosition = line.find(',');
            doubleTimestamp = stod(line.substr (0,commaPosition).c_str());       // read it as double
            longTimestamp = doubleTimestamp*pow(10,6);                      // then convert it to long long
            timestamp_.push_back(longTimestamp);

            // reads the value
            line = line.substr(commaPosition+1);
            this->value_ = stof(line);


            ReCheck:
            checkManger = clockManger->checktimeStamp(longTimestamp);
            if(!checkManger){
                goto ReCheck;
            }
            dataStore->setFloatData(this->value_,key);
        }
     }