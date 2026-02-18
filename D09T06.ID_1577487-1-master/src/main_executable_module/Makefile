CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDFLAGS = -lm

BUILD_DIR = ../../build
TARGET_3 = $(BUILD_DIR)/Quest_3
TARGET_4 = $(BUILD_DIR)/Quest_4
TARGET_5 = $(BUILD_DIR)/Quest_5

DATA_IO = ../data_libs/data_io.c
DATA_STAT = ../data_libs/data_stat.c
DATA_PROCESS = ../data_module/data_process.c
DECISION = ../yet_another_decision_module/decision.c
MAIN = main_executable_module.c

STATIC_LIB = $(BUILD_DIR)/data_stat.a
DYNAMIC_LIB = $(BUILD_DIR)/data_process.so

all: $(TARGET_3)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET_3): $(BUILD_DIR)
	$(CC) $(CFLAGS) $(MAIN) $(DATA_IO) $(DATA_STAT) $(DATA_PROCESS) $(DECISION) $(LDFLAGS) -o $@

data_stat.a: $(STATIC_LIB)

$(STATIC_LIB): $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(DATA_STAT) -o $(BUILD_DIR)/data_stat.o
	ar rcs $@ $(BUILD_DIR)/data_stat.o

build_with_static: $(TARGET_4)

$(TARGET_4): $(BUILD_DIR) $(STATIC_LIB)
	$(CC) $(CFLAGS) $(MAIN) $(DATA_IO) $(DATA_PROCESS) $(DECISION) -L$(BUILD_DIR) -l:data_stat.a $(LDFLAGS) -o $@

data_process.so: $(DYNAMIC_LIB)

$(DYNAMIC_LIB): $(BUILD_DIR)
	$(CC) $(CFLAGS) -fPIC -shared $(DATA_PROCESS) $(DATA_STAT) $(LDFLAGS) -o $@

build_with_dynamic: $(TARGET_5)

$(TARGET_5): $(BUILD_DIR) $(DYNAMIC_LIB)
	$(CC) $(CFLAGS) -DUSE_DYNAMIC $(MAIN) $(DATA_IO) $(DATA_STAT) $(DECISION) -L$(BUILD_DIR) -l:data_process.so $(LDFLAGS) -Wl,-rpath,'$$ORIGIN' -o $@

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all
