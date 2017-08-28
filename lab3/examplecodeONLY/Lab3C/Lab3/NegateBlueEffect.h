#ifndef NEGATEBLUEEFFECT_H_INCLUDED
#define NEGATEBLUEEFFECT_H_INCLUDED

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>

using namespace std;

class NegateBlueEffect : public SimpleImageEffect
{
public:
virtual void processImage(vector<Point> &points)
{
    for(auto &point : points)
    {
        point.setBlue(255 - point.getBlue());
    }
}
};


#endif // NEGATEBLUEEFFECT_H_INCLUDED
