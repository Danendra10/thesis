#ifndef FIELD_HPP_
#define FIELD_HPP_

#include <vector>
// include opencv2 scalar only
#include "opencv2/opencv.hpp"

using namespace cv;

struct Field
{
    /* data */
    Scalar base_color = Scalar(0, 255, 0);
    // it's actually 800x1200 m, but in here, we change it to 900x1300 for offset on opencv
    int length_x;
    int length_y;
};

#endif