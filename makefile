CC=g++

SDIR=./Src/include
CFLAGS=-I$(SDIR)

LDIR=-L ./Src/lib/OpenGL
# LIBS= -lm -lglut -lfreeglut -lopengl32  -lfreeglut -lopengl32 -Wl
LIBS= -lm -lfreeglut -lopengl32  -lglu32 -lglew32 -lglfw3dll

HDIR = ./Src/include
# _HEADER= ./GL/glut.h 
_HEADER= ./GL/*.h 
_HEADER2= ./GLFW/*.h 
_HEADER3= ./GLAD/*.h 
# _HEADER= *.h
HEADER=$(patsubst %,$(HDIR)/%,$(_HEADER)) $(patsubst %,$(HDIR)/%,$(_HEADER2)) $(patsubst %,$(HDIR)/%,$(_HEADER3))

SrcDIR = ./Src/
# _SRC=main.cpp
_SRC=*.cpp
SRC=$(patsubst %,$(SrcDIR)/%,$(_SRC)) $(patsubst %,$(HDIR)/%,GLAD/$(_SRC))

all:
# $(CC) $(CFLAGS) $(LDIR) -o ./exe/game.exe ./Src/main.cpp $(LIBS)
# $(CC) $(CFLAGS) $(LDIR) -o ./exe/game.exe $(SRC) $(HEADER) $(LIBS)
	$(CC) $(CFLAGS) $(LDIR) -o ./exe/program.exe $(SRC) $(LIBS)

.PHONY: clean
clean:
	@echo "clean project"
	del -f *.o 
	@echo "clean completed"
cleanall:
	@echo "clean exe"
	del -f *.o *exe 
	@echo "clean completed"*.exe