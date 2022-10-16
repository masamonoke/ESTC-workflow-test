#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    float x;
    float y;
    float z;
} Vector3;

Vector3* vector3_init();

Vector3* vector3_init_with_values(float x, float y, float z);

void vector3_free(Vector3* this);

void vector3_add_value(Vector3* this, float val);

void vector3_add_vector(Vector3* this, Vector3* other);

void vector3_sub_value(Vector3* this, float val);

void vector3_sub_vector(Vector3* this, Vector3* other);

float vector3_dot(Vector3* this, Vector3* other);

Vector3* vector3_cross(Vector3* this, Vector3* other);

void vector3_set_values_xyz(Vector3* this, float x, float y, float z);

void vector3_print(Vector3* this);

#endif