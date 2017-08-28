#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "Point.h"
#include "SimpleImageEffect.h"
#include "RemoveGreenEffect.h"
#include "RemoveBlueEffect.h"
#include "RemoveRedEffect.h"
#include "NegateRedEffect.h"
#include "NegateGreenEffect.h"
#include "NegateBlueEffect.h"
#include "AddRandomNoise.h"
#include "HighContrast.h"
#include "GrayscaleEffect.h"



using namespace std;

/*
 1. Obtain input PPM file
 2. Read each triplet of RGB values into a Point
 3. For each Point, zero out the green value
 4. Write result to output file
*/

int main()
{


    //Prompt user for input file and output file names
    string input_file_name;
    string output_file_name;
    cout << "Enter a PPM file to parse: ";
    getline(cin, input_file_name);
    cout << "Enter destination file: ";
    getline(cin, output_file_name);
    int controller = 0;
    int userChoice = 0;

    vector<Point> points{};
    ifstream input_file{input_file_name};
            //Open the output file
    ofstream output_file{output_file_name};

    vector<string> lines{};
        if(input_file.is_open() == true)
        {
            while(input_file.good() == true)
            {
                string line;
                getline(input_file, line);
                lines.push_back(line);
            }
        }
        //Parse the input file

        cout << "Reading Image..." << endl;

        vector<string> vals{};
        for(int i=0; i != lines.size(); i++)
        {
            string sentence = lines[i];
            istringstream iss(sentence);

            do
            {
                string sub;
                iss >> sub;
                vals.push_back(sub);
            } while (iss);
        }



    while(controller != -1)
    {

       cout << "*** Effects ***" << endl;
       cout << "        1. Remove Red" << endl;
       cout << "        2. Remove Green" << endl;
       cout << "        3. Remove Blue" << endl;
       cout << "        4. Negate Red" << endl;
       cout << "        5. Negate Green" << endl;
       cout << "        6. Negate Blue" << endl;
       cout << "        7. Add Noise" << endl;
       cout << "        8. High Contrast" << endl;
       cout << "        9. Convert to Grayscale" << endl;
       cout << "        -1. Exit Program" << endl;
       cout << "Selection: ";
       cin >> userChoice;

        //Read all lines from the input file into a vector

        //Caveat / challenge: we need to remember the first 3 lines
        //of our file, but we don't want them in our vector

        for( int i=7; i < vals.size();)
        {
            if(vals[i] == "")
            {
                i++;
                //points.push_back(Point(0,0,0));

            }
            else
            {
                int red=0,green=0,blue =0;
                istringstream (vals[i]) >> red;
                istringstream (vals[i+1]) >> green;
                istringstream (vals[i+2]) >> blue;
                points.push_back(Point(red,green,blue));
                i+=3;
                //output_file << Point(red,green,blue).toString();
                //cout << "i= " << i << " / " << vals.size() << " | " << vals[i]<< endl;
            }
            //cout  << i<< vals[i] << endl;

        }

        //Process points in the input file
        RemoveRedEffect rmr;
        RemoveGreenEffect rmg;
        NegateRedEffect nre;
        NegateGreenEffect nge;
        NegateBlueEffect nbe;
        AddRandomNoise arn;
        HighContrast hce;
        GrayscaleEffect gse;
        RemoveBlueEffect rmb;

        switch(userChoice){
            case 1:
                    rmr.processImage(points);
                    break;
            case 2:
                    rmg.processImage(points);
                    break;
            case 3:
                    rmb.processImage(points);
                    break;
            case 4:
                    nre.processImage(points);
                    break;
            case 5:
                    nge.processImage(points);
                    break;
            case 6:
                    nbe.processImage(points);
                    break;
            case 7:
                    arn.processImage(points);
                    break;
            case 8:
                    hce.processImage(points);
                    break;
            case 9:
                    gse.processImage(points);
                    break;
            case -1: controller = -1;
                     break;
            }


    }

    output_file << vals[0] << endl << vals[2]  << " "<< vals[3] << endl << vals[5] << endl;

    for(int i =0; i < points.size();i++)
        {
            output_file << points[i].toString();
        }

        output_file.close();
        cout << "Processing COMPLETE" << endl;

    return 0;

}
