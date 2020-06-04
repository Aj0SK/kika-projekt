#include "objLoad.h"
#include "bmpWrite.h"

#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    std::vector<std::byte> data;
    
    int W = 128;
    int H = 128;
    
    for(int i=0; i<H; ++i)
        for(int j=0; j<W; ++j)
        {
            if(i<H/4 && j<W/4)
            {
                data.push_back(static_cast<std::byte>(0));
                data.push_back(static_cast<std::byte>(0));
                data.push_back(static_cast<std::byte>(255));
                continue;
            }
            data.push_back(static_cast<std::byte>(255));
            data.push_back(static_cast<std::byte>(0));
            data.push_back(static_cast<std::byte>(0));
        }
    
    bmp::bmpWrite("testOut.bmp", W, H, data);
    
    RawMesh zajac("data/bunny.obj");
    
    return 0;
}
