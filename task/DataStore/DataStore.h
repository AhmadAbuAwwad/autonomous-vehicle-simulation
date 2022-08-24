#pragma once
#include <opencv2/opencv.hpp>
#include "task/Types/Types.h"

class DataStore
{
private:
  mutex mtx;
  static DataStore * dataStore_;
  Types data_;

  DataStore ();
public:
  static DataStore * getInstance ();
  Types getAllData();

  void setImageData(Mat frame,int key);
  void setLocation(pair<float,float> value);
  void setFloatData(float value,int key);
  };
