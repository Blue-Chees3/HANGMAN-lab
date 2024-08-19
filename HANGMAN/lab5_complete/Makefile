CC = gcc
CFLAGS = -Wall -std=c99
TARGET = string_driver
TEST_TARGET = unit_test
OBJS = main.o my_string.o
TEST_OBJS = unit_test.o test_def.o
HEADER = my_string.h

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(TEST_TARGET): $(TEST_OBJS) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)


