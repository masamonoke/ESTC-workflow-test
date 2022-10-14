#include "vector_test.c"

TEST_GROUP_RUNNER(vector) {
    RUN_TEST_CASE(vector, AddValueToVector);
    RUN_TEST_CASE(vector, SubValueFromVector);
    RUN_TEST_CASE(vector, AddVector);
    RUN_TEST_CASE(vector, SubVector);
    RUN_TEST_CASE(vector, DotProduct);
    RUN_TEST_CASE(vector, CrossProduct);
}