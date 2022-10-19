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
    Vector3* expected = vector3_init();
    vector3_set_x(expected, 11);
    vector3_set_y(expected, 11);
    vector3_set_z(expected, 11);
    vector3_set_values_xyz(v1, 10, 10, 10);
    vector3_add_value(v1, 1);
    TEST_ASSERT_EQUAL(vector3_get_x(v1), vector3_get_x(expected));
    TEST_ASSERT_EQUAL(vector3_get_y(v1), vector3_get_y(expected));
    TEST_ASSERT_EQUAL(vector3_get_z(v1), vector3_get_z(expected));
    vector3_free(expected);
}

TEST(vector, SubValueFromVector) {
    Vector3* expected = vector3_init();
    vector3_set_x(expected, 9);
    vector3_set_y(expected, 9);
    vector3_set_z(expected, 9);
    vector3_set_values_xyz(v1, 10, 10, 10);
    vector3_sub_value(v1, 1);
    TEST_ASSERT_EQUAL(vector3_get_x(v1), vector3_get_x(expected));
    TEST_ASSERT_EQUAL(vector3_get_y(v1), vector3_get_y(expected));
    TEST_ASSERT_EQUAL(vector3_get_z(v1), vector3_get_z(expected));
    vector3_free(expected);
}

TEST(vector, AddVector) {
    Vector3* expected = vector3_init();
    vector3_set_x(expected, 11.01f);
    vector3_set_y(expected, 124);
    vector3_set_z(expected, 6.77f);
    vector3_set_values_xyz(v1, 10, 10, 10);
    vector3_set_values_xyz(v2, 1.01f, 114, -3.23f);
    vector3_add_vector(v1, v2);
    TEST_ASSERT_EQUAL(vector3_get_x(v1), vector3_get_x(expected));
    TEST_ASSERT_EQUAL(vector3_get_y(v1), vector3_get_y(expected));
    TEST_ASSERT_EQUAL(vector3_get_z(v1), vector3_get_z(expected));
    vector3_free(expected);
}

TEST(vector, SubVector) {
    Vector3* expected = vector3_init();
    vector3_set_x(expected, 8.99f);
    vector3_set_y(expected, -104);
    vector3_set_z(expected, 13.23f);
    vector3_set_values_xyz(v1, 10, 10, 10);
    vector3_set_values_xyz(v2, 1.01f, 114, -3.23f);
    vector3_sub_vector(v1, v2);
    TEST_ASSERT_EQUAL(vector3_get_x(v1), vector3_get_x(expected));
    TEST_ASSERT_EQUAL(vector3_get_y(v1), vector3_get_y(expected));
    TEST_ASSERT_EQUAL(vector3_get_z(v1), vector3_get_z(expected));
    vector3_free(expected);
}

TEST(vector, DotProduct) {
    float expected = 32.f;
    vector3_set_values_xyz(v1, 1, 2, 3);
    vector3_set_values_xyz(v2, 4, 5, 6);
    float given = vector3_dot(v1, v2);
    TEST_ASSERT_EQUAL_FLOAT(expected, given);
}

TEST(vector, CrossProduct) {
    Vector3* expected = vector3_init();
    vector3_set_x(expected, -3);
    vector3_set_y(expected, 6);
    vector3_set_z(expected, -3);
    vector3_set_values_xyz(v1, 1, 2, 3);
    vector3_set_values_xyz(v2, 4, 5, 6);
    Vector3* given = vector3_cross(v1, v2);
    TEST_ASSERT_EQUAL(vector3_get_x(given), vector3_get_x(expected));
    TEST_ASSERT_EQUAL(vector3_get_y(given), vector3_get_y(expected));
    TEST_ASSERT_EQUAL(vector3_get_z(given), vector3_get_z(expected));
    vector3_free(expected);
}