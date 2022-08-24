#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  
#include <opencv2/opencv.hpp>
#include <thread>       

using namespace std;
using namespace cv;

enum keys{
    Front = 0,
    Back,
    Rigth,
    Left,
    Brake,
    Steering,
    GPS,
    Throttle,
    Speed,
};