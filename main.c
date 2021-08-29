#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {
    List* homes = newList();
    append(homes, "Skyview", 5, 450000);
    append(homes, "Skyview", 4, 410000);
    append(homes, "Shepard", 4, 399000);
    append(homes, "Shepard", 3, 403000);
    append(homes, "Skyview", 3, 380000);

    filter(homes);

    clear(homes);

    return 0;
}
