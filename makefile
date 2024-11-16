# Specify the compiler
CC = clang

# Compiler flags
CFLAGS = -fopenmp=libomp

# Source directory
SRC_DIR = src

# Binary (output) directory
BIN_DIR = bin

# List of programs (just the names, without .c extension)
PROGRAMS = parallel atomic_update learning_openmp barier get_num_threads critical mytry

# Targets to build all programs
all: $(PROGRAMS)

# Build each program and place the output in the bin directory
$(PROGRAMS):
	$(CC) $(CFLAGS) $(SRC_DIR)/$@.c -o $(BIN_DIR)/$@

# Run each program after building it
run_parallel: parallel
	./$(BIN_DIR)/parallel

run_atomic_update: atomic_update
	./$(BIN_DIR)/atomic_update

run_learning_openmp: learning_openmp
	./$(BIN_DIR)/learning_openmp

run_barier: barier
	./$(BIN_DIR)/barier

run_get_num_threads: get_num_threads
	./$(BIN_DIR)/get_num_threads

run_critical: critical
	./$(BIN_DIR)/critical

run_mytry: mytry
	./$(BIN_DIR)/mytry



# Clean rule to delete all executables in bin directory
clean:
	rm -f $(BIN_DIR)/*
