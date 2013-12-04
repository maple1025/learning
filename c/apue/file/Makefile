
all:
	@echo "Building all ...\n"
	gcc dir_traversal.c error.c path_alloc.c apue.h -o dir_traversal

	@echo "Test all ...\n"
	@echo "======================================="
	@echo "\tTesting dir_traversal\n"
	@echo "======================================="
	@echo "test-1 --> "
	./dir_traversal ..
	@echo "test-2 --> "
	./dir_traversal ~/workspace/learning/c/apue

clean:
	rm -fr dir_traversal
