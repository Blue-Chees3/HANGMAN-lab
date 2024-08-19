CC = gcc
CFLAGS = -Wall -std=c99
MAIN_TARGET = string_driver
TEST_TARGET = unit_test
OBJS = main.o my_string.o
TEST_OBJS = unit_test.o test_def.o
HEADER = my_string.h

.PHONY: all clean test

all: $(MAIN_TARGET)

$(MAIN_TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN_TARGET) $(OBJS)

$(TEST_TARGET): $(TEST_OBJS) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(MAIN_TARGET) $(TEST_OBJS) $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

