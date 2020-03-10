CXX = g++
EXE = run

CXXFLAGS = -I include/

OBJ = $(addprefix obj/,main.o spaces.o elimination.o matrix.o fraction.o)

vpath %.cpp src/

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $^ -o $@

obj/%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	-rm $(OBJ)
	-rm $(EXE)
