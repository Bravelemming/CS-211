#ifndef REMOVEREDEFFECT_H_INCLUDED
#define REMOVEREDEFFECT_H_INCLUDED

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>

using namespace std;

class RemoveRedEffect : public SimpleImageEffect
{
public:
virtual void processImage(vector<Point> &points)
{
    for(auto &point : points)
    {
        point.setRed(0);
    }
}
};

#endif // REMOVEREDEFFECT_H_INCLUDED
