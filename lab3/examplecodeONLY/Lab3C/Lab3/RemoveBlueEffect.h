#ifndef REMOVEBLUEEFFECT_H_INCLUDED
#define REMOVEBLUEEFFECT_H_INCLUDED

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>

using namespace std;

class RemoveBlueEffect : public SimpleImageEffect
{
public:
virtual void processImage(vector<Point> &points)
{
    cout << "Processing Image..." << endl;
    for(auto &point : points)
    {
        point.setBlue(0);
    }
}
};


#endif // REMOVEBLUEEFFECT_H_INCLUDED
