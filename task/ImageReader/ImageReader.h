#pragma once
#include "task/Reader/Reader.h"
#include <opencv2/opencv.hpp>

class ImageReader : public Reader
{
private:
    Mat frame_;

public:
    ImageReader (string path);
    void readFile();
};