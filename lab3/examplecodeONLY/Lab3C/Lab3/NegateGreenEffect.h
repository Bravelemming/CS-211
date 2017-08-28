#ifndef NEGATEGREENEFFECT_H_INCLUDED
#define NEGATEGREENEFFECT_H_INCLUDED

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>

using namespace std;

class NegateGreenEffect : public SimpleImageEffect
{
public:
virtual void processImage(vector<Point> &points)
{
    for(auto &point : points)
    {
        point.setGreen(255 - point.getGreen());
    }
}
};

#endif // NEGATEGREENEFFECT_H_INCLUDED
