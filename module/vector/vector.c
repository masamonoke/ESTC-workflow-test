#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Vector3* vector3_init() {
    return vector3_init_with_values(0, 0, 0);
}

Vector3* vector3_init_with_values(float x, float y, float z) {
    Vector3* v = malloc(sizeof(Vector3));
    if (v) {
        v->x = x;
        v->y = y;
        v->z = z;
        return v;
    } else {
        free(v);
        return NULL;
    }
}

void vector3_free(Vector3* this) {
    free(this);
}

void vector3_add_value(Vector3* this, float val) {
    this->x += val;
    this->y += val;
    this->z += val;
}

void vector3_add_vector(Vector3* this, Vector3* other) {
    this->x += other->x;
    this->y += other->y;
    this->z += other->z;
}

void vector3_sub_value(Vector3* this, float val) {
    vector3_add_value(this, -val);
}

void vector3_sub_vector(Vector3* this, Vector3* other) {
    this->x -= other->x;
    this->y -= other->y;
    this->z -= other->z;
}

float vector3_dot(Vector3* this, Vector3* other) {
    return this->x * other->x + this->y * other->y + this->z * other->z;
}

Vector3* vector3_cross(Vector3* this, Vector3* other) {
    Vector3* cross = vector3_init();
    cross->x = (this->y * other->z) - (this->z * other->y);
    cross->y = (this->z * other->x) - (this->x * other->z);
    cross->z = (this->x * other->y) - (this->y * other->x);
    return cross;
}

void vector3_set_values_xyz(Vector3* this, float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void vector3_print(Vector3* this) {
    printf("Vector3: (x=%f, y=%f, z=%f)\n", this->x, this->y, this->z);
}