#ifndef SIMPLE_IMAGE_EFFECT_H
#define SIMPLE_IMAGE_EFFECT_H

#include "Point.h"
#include <vector>
using namespace std;

class SimpleImageEffect
{
public:
    virtual void processImage(vector<Point> &points) = 0;
};

#endif // SIMPLE_IMAGE_EFFECT_H
