#include "GpsReader.h"

    GpsReader::GpsReader (string path)
        :Reader(path)
    {
    }
     void GpsReader::readFile()
    {
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
            commaPosition = line.find(',');
            this->location_.first = stof(line.substr (0,commaPosition).c_str());    
            line = line.substr(commaPosition+1);
            commaPosition = line.find(',');                
            this->location_.second = stof(line.substr (0,commaPosition).c_str());     
            
        //  synchronize then send data
            ReCheck:
            checkManger = clockManger->checktimeStamp(longTimestamp);
            if(!checkManger){
                goto ReCheck;
            }
            dataStore->setLocation(location_);           
        }		
    }