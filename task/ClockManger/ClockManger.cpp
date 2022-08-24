#include "ClockManger.h"

  ClockManger::ClockManger ()
  {
  }

  ClockManger * ClockManger::getInstance ()
  {
    if (ClockManger::clockManger_ == nullptr)
    {
      ClockManger::clockManger_ = new ClockManger();
    }
    return ClockManger::clockManger_;
  }

  // Front Image Timestamp setter
  void ClockManger::readFrontCameraTimeStamp(long long timestamp){
    this->frontTimestamp_ = timestamp;
  } 

  // Timestamp synchronization
  bool ClockManger::checktimeStamp(long long timestamp){
    if(timestamp > this->frontTimestamp_)       //  return 1 when time exceeded front timestamp
      return false;
    return true; //  when equals
  }

  //  Front waits for late readers
  bool ClockManger::waitForOthers(long long timestamp){
    if(this->frontTimestamp_ - timestamp >= 100000)
      return true;
    return false; //  when equals
  }