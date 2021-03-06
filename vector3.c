//
// Created by bauti on 4/16/2021.
//

#include "vector3.h"
#include <math.h>


Vector3 sum(Vector3 vec1, Vector3 vec2)
{
    Vector3 result;
    result.x = vec1.x + vec2.x;
    result.y = vec1.y + vec2.y;
    result.z = vec1.z + vec2.z;
    return result;
}

double norm(Vector3 vec)
{
    return sqrt(dot(vec, vec));
}

float dot(Vector3 vec1, Vector3 vec2)
{
    return (vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z);
}