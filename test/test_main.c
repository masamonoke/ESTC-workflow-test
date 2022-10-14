#include "suite_vector/vector_test_runner.c"

static void run_all_test(void) {
    RUN_TEST_GROUP(vector);
}

int main(int argc, const char* argv[]) {
    return UnityMain(argc, argv, run_all_test);
}