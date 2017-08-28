#ifndef REMOVE_GREEN_EFFECT_H
#define REMOVE_GREEN_EFFECT_H

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>

using namespace std;

class RemoveGreenEffect : public SimpleImageEffect
{
public:
virtual void processImage(vector<Point> &points)
{
    cout << "Processing Image..." << endl;

    for(auto &point : points)
    {
        point.setGreen(0);
    }
}
};

#endif
