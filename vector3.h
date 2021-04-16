//
// Created by bauti on 4/16/2021.
//

#ifndef INC_193R_GUIA1_VECTOR3_H
#define INC_193R_GUIA1_VECTOR3_H

typedef struct {
    float x;
    float y;
    float z;
} Vector3;

Vector3 sum(Vector3 vec1, Vector3 vec2);
double norm(Vector3 vec);
float dot(Vector3 vec1, Vector3 vec2);


#endif //INC_193R_GUIA1_VECTOR3_H
