#pragma once
#include <opencv2/opencv.hpp>
#include "task/main/local.h"

class Types
{
private:
  Mat frontImage_;
  Mat backImage_;
  Mat leftImage_;
  Mat rightImage_;

  pair<float,float> location_;

  float speed_;
  float brake_;
  float throttle_;
  float steering_;
  
public:
    Types();

    float getSpeed();
    float getSteering();
    float getThrottle();
    float getBrake();

    pair<float,float> getLocation();

    Mat getFrontImage();
    Mat getBackImage();
    Mat getLeftImage();
    Mat getRightImage();
     
    void setSpeed(float speedValue);
    void setSteering(float steeringValue);
    void setThrottle(float throttleValue);
    void setBrake(float brakeValue);
    void setLocation(pair<float,float> location);

    void setFrontImage(Mat frontImage);
    void setBackImage(Mat backImage);
    void setLeftImage(Mat leftImage);
    void setRightImage(Mat rightImage);
};  