TEST = build/test
RELEASE = build/src
CC = gcc
RM = rm -rf

BUILD_DIR = build
PREF_OBJ = $(BUILD_DIR)/obj/

PREF_DEP = dependency
PREF_DEP_OBJ = $(PREF_OBJ)$(PREF_DEP)
DEPS = $(shell find $(PREF_DEP) -name '*.c')
DEPS_OBJ = $(patsubst $(PREF_DEP)%.c, $(PREF_DEP_OBJ)%.o, $(DEPS))

PREF_SRC = src
PREF_SRC_OBJ = $(PREF_OBJ)$(PREF_SRC)
SRC = $(shell find $(PREF_SRC) -name '*.c')
SRC_OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_SRC_OBJ)%.o, $(SRC))

PREF_MODULE = module
PREF_MODULE_OBJ = $(PREF_OBJ)$(PREF_MODULE)
MODULE_SRC = $(shell find $(PREF_MODULE) -name '*.c')
MODULE_OBJ = $(patsubst $(PREF_MODULE)%.c, $(PREF_MODULE_OBJ)%.o, $(MODULE_SRC))

PREF_TEST_SRC = test/test_main.c
PREF_TEST_OBJ = $(PREF_OBJ)$(PREF_TEST_SRC:.c=.o)

CFLAGS ?= -g -Wall -Werror

debug:
	echo $(PREF_TEST_OBJ)

run_release: src
	./$(RELEASE)

run_test: test
	./$(TEST)

.PHONY: rebuild
rebuild:
	$(MAKE) clean
	$(MAKE) all
	$(MAKE) run


run: all
	./$(TEST); ./$(RELEASE)

all: test src

test: $(PREF_TEST_OBJ) $(MODULE_OBJ) $(DEPS_OBJ)
	$(CC) $(CFLAGS) -o $(TEST) build/obj/test/test_main.o $(DEPS_OBJ) $(MODULE_OBJ)

src: $(MODULE_OBJ) $(SRC_OBJ)
	$(CC) $(CFLAGS) -o $(RELEASE) $(MODULE_OBJ) $(SRC_OBJ)

$(PREF_SRC_OBJ)%.o: $(PREF_SRC)%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(PREF_TEST_OBJ): $(PREF_TEST_SRC)
	@mkdir -p $(dir $@)
	$(CC) -c $(PREF_TEST_SRC) -o $(PREF_TEST_OBJ)

$(PREF_MODULE_OBJ)%.o: $(PREF_MODULE)%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(PREF_DEP_OBJ)%.o: $(PREF_DEP)%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR)