#ifndef HIGHCONTRAST_H_INCLUDED
#define HIGHCONTRAST_H_INCLUDED

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>

using namespace std;

class HighContrast : public SimpleImageEffect
{
public:
virtual void processImage(vector<Point> &points)
{
    cout << "Processing Image..." << endl;
    for(auto &point : points)
    {
        if(point.getRed() > (255/2))
            point.setRed(255);
        else
            point.setRed(0);
        if(point.getBlue() > (255/2))
            point.setBlue(255);
        else
            point.setBlue(0);
        if(point.getGreen() > (255/2))
            point.setGreen(255);
        else
            point.setGreen(0);
    }
}
};

#endif // HIGHCONTRAST_H_INCLUDED
