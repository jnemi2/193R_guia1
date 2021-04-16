#include <stdio.h>
#include "vector3.h"

int main() {
    printf("Hello, World!\n");
    Vector3 vec = {1, 2, 4};
    printf("The norm of (%.2f, %.2f, %.2f) is %lf", vec.x, vec.y, vec.z, norm(vec));

    return 0;
}
