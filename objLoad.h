#ifndef BMPWRITE_H
#define BMPWRITE_H

#include <iostream>
#include <vector>

struct MeshFace
{
    int v1;
    int v2;
    int v3;
};

struct MeshVertex
{
    double x;
    double y;
    double z;
};

class RawMesh
{
public:
    RawMesh(const std::string &path);
    void Parse(const std::string &path);
    
    std::vector<MeshFace> faces;
    std::vector<MeshVertex> vertices;
};

#endif
