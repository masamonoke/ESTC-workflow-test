#include <stdio.h>
#include <stdlib.h>
#include "../module/vector/vector.h"

int main(void) {
    Vector3* v1 = vector3_init();
    vector3_add_value(v1, 10);
    vector3_print(v1);
    Vector3* v2 = vector3_init_with_values(1, 2, 3);
    printf("%f\n", vector3_dot(v1, v2));
    vector3_print(vector3_cross(v1, v2));
    vector3_free(v1);
    return EXIT_SUCCESS;
}