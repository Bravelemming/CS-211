#ifndef ADDRANDOMNOISE_H_INCLUDED
#define ADDRANDOMNOISE_H_INCLUDED

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>

using namespace std;

class AddRandomNoise : public SimpleImageEffect
{
public:
virtual void processImage(vector<Point> &points)
{
    cout << "Processing Image..." << endl;
    for(auto &point : points)
    {
        point.setBlue(point.getBlue() - (rand() % 20 - 10));
        point.setRed(point.getRed() - (rand() % 20 - 10));
        point.setGreen(point.getGreen() - (rand() % 20 - 10));
    }
}
};

#endif // ADDRANDOMNOISE_H_INCLUDED
