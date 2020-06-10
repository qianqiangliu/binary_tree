all: binary_tree

CFLAGS := -Wall

binary_tree: main.o stack.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f .tags *.o binary_tree
