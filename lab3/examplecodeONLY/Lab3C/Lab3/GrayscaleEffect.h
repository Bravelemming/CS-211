#ifndef GRAYSCALEEFFECT_H_INCLUDED
#define GRAYSCALEEFFECT_H_INCLUDED

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>

using namespace std;

class GrayscaleEffect : public SimpleImageEffect
{
public:
virtual void processImage(vector<Point> &points)
{
    cout << "Processing Image..." << endl;
    for(auto &point : points)
    {
        int avg = (point.getBlue() + point.getRed() + point.getGreen())/3;
        point.setRed(avg);
        point.setBlue(avg);
        point.setGreen(avg);
    }
}
};

#endif // GRAYSCALEEFFECT_H_INCLUDED
