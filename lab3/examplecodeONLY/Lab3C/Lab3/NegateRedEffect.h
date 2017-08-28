#ifndef NEGATEREDEFFECT_H_INCLUDED
#define NEGATEREDEFFECT_H_INCLUDED

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>

using namespace std;

class NegateRedEffect : public SimpleImageEffect
{
public:
virtual void processImage(vector<Point> &points)
{
    for(auto &point : points)
    {
        point.setRed(255 - point.getRed());
    }
}
};

#endif // NEGATEREDEFFECT_H_INCLUDED
