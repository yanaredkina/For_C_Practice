TARGET = matrix
OBJECTS = matrix.o main.o

.PHONY: test clean
	
test: $(TARGET)
	./$(TARGET)
	
clean:
	rm -rf $(TARGET) *.o
	
main.o: main.cc matrix.h
			clang++ main.cc -c -o main.o
			
matrix.o: matrix.cc matrix.h
			clang++ matrix.cc -c -o matrix.o
			
$(TARGET): $(OBJECTS)
			clang++ $(OBJECTS) -o $(TARGET)