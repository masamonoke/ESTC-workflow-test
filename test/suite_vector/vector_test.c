#include "../../dependency/unity/unity_fixture.h"
#include "../../module/vector/vector.h"

TEST_GROUP(vector);

static Vector3* v1;
static Vector3* v2;

TEST_SETUP(vector) {
    v1 = vector3_init();
    v2 = vector3_init();
}

TEST_TEAR_DOWN(vector) {}

TEST(vector, AddValueToVector) {
    Vector3 expected;
    expected.x = 11;
    expected.y = 11;
    expected.z = 11;
    vector3_set_values_xyz(v1, 10, 10, 10);
    vector3_add_value(v1, 1);
    TEST_ASSERT_EQUAL(v1->x, expected.x);
    TEST_ASSERT_EQUAL(v1->y, expected.y);
    TEST_ASSERT_EQUAL(v1->z, expected.z);
}

TEST(vector, SubValueFromVector) {
    Vector3 expected;
    expected.x = 9;
    expected.y = 9;
    expected.z = 9;
    vector3_set_values_xyz(v1, 10, 10, 10);
    vector3_sub_value(v1, 1);
    TEST_ASSERT_EQUAL_FLOAT(v1->x, expected.x);
    TEST_ASSERT_EQUAL_FLOAT(v1->y, expected.y);
    TEST_ASSERT_EQUAL_FLOAT(v1->z, expected.z);
}

TEST(vector, AddVector) {
    Vector3 expected;
    expected.x = 11.01f;
    expected.y = 124;
    expected.z = 6.77f;
    vector3_set_values_xyz(v1, 10, 10, 10);
    vector3_set_values_xyz(v2, 1.01f, 114, -3.23f);
    vector3_add_vector(v1, v2);
    TEST_ASSERT_EQUAL_FLOAT(v1->x, expected.x);
    TEST_ASSERT_EQUAL_FLOAT(v1->y, expected.y);
    TEST_ASSERT_EQUAL_FLOAT(v1->z, expected.z);
}

TEST(vector, SubVector) {
    Vector3 expected;
    expected.x = 8.99f;
    expected.y = -104;
    expected.z = 13.23f;
    vector3_set_values_xyz(v1, 10, 10, 10);
    vector3_set_values_xyz(v2, 1.01f, 114, -3.23f);
    vector3_sub_vector(v1, v2);
    TEST_ASSERT_EQUAL_FLOAT(expected.x, v1->x);
    TEST_ASSERT_EQUAL_FLOAT(expected.y, v1->y);
    TEST_ASSERT_EQUAL_FLOAT(expected.z, v1->z);
}

TEST(vector, DotProduct) {
    float expected = 32.f;
    vector3_set_values_xyz(v1, 1, 2, 3);
    vector3_set_values_xyz(v2, 4, 5, 6);
    float given = vector3_dot(v1, v2);
    TEST_ASSERT_EQUAL_FLOAT(expected, given);
}

TEST(vector, CrossProduct) {
    Vector3 expected;
    expected.x = -3;
    expected.y = 6;
    expected.z = -3;
    vector3_set_values_xyz(v1, 1, 2, 3);
    vector3_set_values_xyz(v2, 4, 5, 6);
    Vector3* given = vector3_cross(v1, v2);
    TEST_ASSERT_EQUAL_FLOAT(expected.x, given->x);
    TEST_ASSERT_EQUAL_FLOAT(expected.y, given->y);
    TEST_ASSERT_EQUAL_FLOAT(expected.z, given->z);
}