#include "objLoad.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::string;
using std::cout;
using std::endl;

RawMesh::RawMesh(const string &path)
{
    Parse(path);
}

void RawMesh::Parse(const string &path)
{
    std::vector<MeshVertex> v;
    std::vector<MeshFace> f;
    
    std::ifstream inFile(path);
    
    for (std::string line; std::getline(inFile, line, '\n'); )
    {
        if (line.empty() || line[0] == '#')
            continue;

        line.push_back(' ');
        
        std::vector<std::string> splited = {""};
        for(char x : line)
        {
            if(x == ' ') splited.push_back("");
            else splited.back().push_back(x);
        }
        splited.pop_back();
        
        if(splited[0] == "v")
        {
            v.push_back({std::stod(splited[1]), std::stod(splited[2]), std::stod(splited[3])});
        }
        else if(splited[0] == "f")
        {
            f.push_back({std::stoi(splited[1]), std::stoi(splited[2]), std::stoi(splited[3])});
        }
    }
    inFile.close();
    
    cout << "Loaded " << v.size() << " vertices and " << f.size() << " faces" << endl;
    
    this->vertices = v;
    this->faces = f;
    
    return;
}
