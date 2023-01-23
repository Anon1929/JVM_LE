DIROBJ = $(shell find . -name '*.c')
#OBJS specifies which files to compile as part of the project
#CC specifies which compiler we're using
CC = gcc

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -m32

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = 

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = exec
#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(DIROBJ) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)