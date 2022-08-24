#include "ImageReader.h"

    ImageReader::ImageReader (string path)
        :Reader(path)
    {
    }

    void ImageReader::readFile()
    {
        string path =  getPath();     
        string keyString;
        int key = 0;
        string pathKey = string(getPath().rbegin(), getPath().rend());            
        int position = pathKey.find("/");
        keyString = pathKey.substr (0,position).c_str();
        pathKey = string(keyString.rbegin(), keyString.rend());
        keyString = pathKey.substr(0,pathKey.find("."));
        key = stoi(keyString);

        path = getPath() +  "/left/" + "*.jpeg";     
        vector<cv::String> fn;
        glob(path, fn, false);
        size_t count = fn.size(); //number of jpeg files in images folder
    
        string timeStampString;
        string temp;
        double doubleTimeStamp;
        long long longTimeStamp;    
        
        ClockManger * clockManger = ClockManger::getInstance();
        DataStore * dataStore = DataStore::getInstance();
        bool checkManger = true;

        for (size_t i=0; i<count; i++){

            //  getting timestamp
            timeStampString = fn[i];
            temp = string(timeStampString.rbegin(), timeStampString.rend());
            position = temp.find("/");
            temp = temp.substr(0,position);
            timeStampString = string(temp.rbegin(), temp.rend());
            position = temp.find("./");
            timeStampString = timeStampString.substr(0,position);
            doubleTimeStamp = stod(timeStampString);
            longTimeStamp = doubleTimeStamp * pow(10,6);
            timestamp_.push_back(longTimeStamp);

            ReCheck:
            //  check synchronizer
            if(key != 0){
                checkManger = clockManger->checktimeStamp(longTimeStamp);
                // OR Sleep
                if(clockManger->waitForOthers(longTimeStamp)){
                    continue;
                }
                if(!checkManger){
                    goto ReCheck;
                }
            }else{
                clockManger->readFrontCameraTimeStamp(longTimeStamp);  
            }
    
            this->frame_ = imread(fn[i]);  
            dataStore->setImageData(this->frame_,key);        
        }
        if(key == Front)
        	abort();    
    }