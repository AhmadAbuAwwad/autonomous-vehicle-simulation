#pragma once
#include <opencv2/opencv.hpp>


class ClockManger
{
private:
  long long frontTimestamp_;
  static ClockManger * clockManger_;
  ClockManger ();

public:
  static ClockManger * getInstance ();

  void readFrontCameraTimeStamp(long long timestamp);
  bool checktimeStamp(long long timestamp);
  bool waitForOthers(long long timestamp);
};