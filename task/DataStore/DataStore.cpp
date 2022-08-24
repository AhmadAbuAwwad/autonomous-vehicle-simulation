#include "DataStore.h"

  DataStore::DataStore ()
  {
  }

  DataStore * DataStore::getInstance ()
  {
    if (DataStore::dataStore_ == nullptr)
    {
      DataStore::dataStore_ = new DataStore();
    }
    return DataStore::dataStore_;
  }
  Types DataStore::getAllData(){
    this->mtx.lock();
    Types temp = this->data_;
    this->mtx.unlock();
    return temp;
  }

  void DataStore::setImageData(Mat frame,int key){
    this->mtx.lock();
    switch (key)
    {
    case Front:
      this->data_.setFrontImage(frame);
      break;
    case Back:
      this->data_.setLeftImage(frame);
      break;
    case Rigth:
      this->data_.setRightImage(frame);
      break;
    case Left:
      this->data_.setBackImage(frame);
      break;
    default:
      break;
    }    
    this->mtx.unlock();
  }
  
  void DataStore::setLocation(pair<float,float> value){
    this->mtx.lock(); 
    this->data_.setLocation(value);
    this->mtx.unlock();
  }

  void DataStore::setFloatData(float value,int key){
    this->mtx.lock();
    switch (key)
    {
    case Speed:
      this->data_.setSpeed(value);
      break;
    case Steering:
      this->data_.setSteering(value);
      break;
    case Brake:
      this->data_.setBrake(value);
      break;
    case Throttle:
      this->data_.setThrottle(value);
      break;
    default:
      break;
    }    
    this->mtx.unlock();    
  }
