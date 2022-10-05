#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){

    ifstream image;
    ofstream newimage;

    image.open("image2.ppm");
    newimage.open("newimage2.ppm");


    string type = "", width = "", height = "", RGB = "";
    image >> type;
    image >> width;
    image >> height;
    image >> RGB;

    newimage << type;
    newimage << width << " " << height << endl;
    newimage << RGB << endl;

    //cout << type << width << height << RGB << endl;
    string red = "", green = "", blue = "";
    int r = 0, g = 0, b = 0;

    while(!image.eof()){
        image >> red;
        image >> green;
        image >> blue;

        stringstream redstream(red);
        stringstream greenstream(green);
        stringstream bluestream(blue);

        redstream >> r;
        greenstream >> g;
        bluestream >> b;

        if(b + 50 >= 255){
            b = 255;
        } else {
            b += 50;
        }

        newimage << r << " " << g << " " << b << endl;
    }
    image.close();
    newimage.close();
    return 0;
}