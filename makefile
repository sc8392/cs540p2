
#specify the compiler
GXX=g++ -O3

# Specifiy the target
all: driver.exe

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
driver.exe: BinarySearchTree.o InputArray.o LinkedList.o Node.o Timing.o TreeNode.o
	$(GXX) BinarySearchTree.o InputArray.o LinkedList.o Node.o Timing.o TreeNode.o -o driver.exe

# Specify how the object files should be created from source files

BinarySearchTree.o: BinarySearchTree.cpp
	$(GXX)  -c  BinarySearchTree.cpp

InputArray.o: InputArray.cpp
	$(GXX)  -c  InputArray.cpp

LinkedList.o: LinkedList.cpp
	$(GXX)  -c  LinkedList.cpp

Node.o: Node.cpp Node.h
	$(GXX)  -c  Node.cpp

Timing.o: Timing.cpp
	$(GXX)  -c  Timing.cpp

TreeNode.o: TreeNode.cpp 
	$(GXX)  -c  TreeNode.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o *~ core driver.exe