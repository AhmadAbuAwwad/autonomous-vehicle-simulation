#include "Types.h"

    Types::Types(){
    }

    float Types::getSpeed(){ 
        return this->speed_;
    }
    float Types::getSteering(){  
        return this->steering_;
    }
    float Types::getThrottle(){
        return this->throttle_;
    }
    float Types::getBrake(){
        return this->brake_;
    }
    pair<float,float> Types::getLocation(){ 
        return this->location_;
    }
    Mat Types::getFrontImage(){
        return this->frontImage_;
    }
    Mat Types::getBackImage(){ 
        return this->backImage_;
    }
    Mat Types::getLeftImage(){ 
        return this->leftImage_;
    }
    Mat Types::getRightImage(){
        return this->rightImage_;
    } 
     
    void Types::setSpeed(float speedValue){ 
      this->speed_ = speedValue;
    }
    void Types::setSteering(float steeringValue){  
      this->steering_ = steeringValue;
    }
    void Types::setThrottle(float throttleValue){
      this->throttle_ = throttleValue;
    }
    void Types::setBrake(float brakeValue){
      this->brake_ = brakeValue;      
    }
    void Types::setLocation(pair<float,float> location){ 
      this->location_ = location;
    }
    void Types::setFrontImage(Mat frontImage){
        this->frontImage_ = frontImage;
    }
    void Types::setBackImage(Mat backImage){ 
        this->backImage_ = backImage;
    }
    void Types::setLeftImage(Mat leftImage){ 
        this->leftImage_ = leftImage;
    }
    void Types::setRightImage(Mat rightImage){
        this->rightImage_ = rightImage;
    } 
