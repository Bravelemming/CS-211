#ifndef GRAYSCALEEFFECT_H_INCLUDED
#define GRAYSCALEEFFECT_H_INCLUDED

#include "Point.h"
#include "SimpleImageEffect.h"
#include <vector>
#include <iostream>

using namespace std;

class GrayscaleEffect : public SimpleImageEffect
{
public:
	virtual void processImage(vector<Point> &points)
	{

		for (auto &point : points)
		{
			int average = (point.getBlue() + point.getRed() + point.getGreen()) / 3;
			//set all
			point.setRed(average);
			point.setBlue(average);
			point.setGreen(average);
		}
	}
};

#endif // GRAYSCALEEFFECT_H_INCLUDED
