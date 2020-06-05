#include "objLoad.h"
#include "bmpWrite.h"
#include "Vector.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using std::byte;
using std::pair;

std::vector<std::byte> data;

void Color_pixel(int X, int Y, int w, byte R, byte G, byte B)
{
    data[3*Y*w+3*X] = B;
    data[3*Y*w+3*X+1] = G;
    data[3*Y*w+3*X+2] = R;
}

bool Is_inside(Vector AB, Vector BC, Vector CA, Vector AX, Vector BX, Vector CX)
{
    if (((AX^AB).z() > 0) && ((BX^BC).z() > 0) && ((CX^CA).z() > 0))
        return true;
    if (((AX^AB).z() < 0) && ((BX^BC).z() < 0) && ((CX^CA).z() < 0))
        return true;
    return false;
}

struct triangle
{
    triangle(Vector A, Vector B, Vector C) : A(A), B(B), C(C) 
    {
        AB = B-A;
        BC = C-B;
        CA = A-C;
        BA = A-B;
        CB = B-C;
        AC = C-A;
    };
    
    Vector A,B,C;
    Vector AB, BA, AC, CA, BC, CB;
    
};

struct circle
{
    circle(Vector S, int r) : S(S), r(r) {};
    Vector S;
    int r;
};

int main()
{
    int W = 1024;
    int H = 1024;
    
    data.resize(3*W*H);
    
    circle C({500,400},150);
    
    for(int i=0; i<W; ++i)
        for(int j=0; j<H; ++j)
        {
            Color_pixel(i, j, W, (byte)100,(byte)100,(byte)100);
            Vector X(i,j);
            if((X-C.S).size()<=C.r)
            {
                Color_pixel(i, j, W, (byte)255, (byte)0, (byte)0);
            }
        }
    
    bmp::bmpWrite("testOut.bmp", W, H, data);
    
    RawMesh zajac("data/bunny.obj");
    
    return 0;
}
