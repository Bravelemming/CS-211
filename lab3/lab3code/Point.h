#ifndef POINT_H
#define POINT_H

#include <string>
#include <sstream>

using namespace std;

class Point
{
private:
    int _red;
    int _green;
    int _blue;

public:
    Point(int red = 0, int green = 0, int blue = 0)
    {
        _red = red;
        _green = green;
        _blue = blue;
    }

    int getRed()
    {
        return _red;
    }

    void setRed(int value)
    {
        //restrict value to sensible values
        if(value >= 0 && value <= 255)
        {
            _red = value;
        }
    }

	int getGreen()
	{
		return _green;
	}


    void setGreen(int value)
    {
        if(value >= 0 && value <= 255)
        {
            _green = value;
        }
    }

	int getBlue()
	{
		return _blue;
	}

	void setBlue(int value)
	{
		if (value >= 0 && value <= 255)
		{
			_blue = value;
		}
	}

    string toString()
    {
        ostringstream output{};
        output << _red << " " << _green << " " << _blue;
        return output.str();
    }

};

#endif // POINT_H
