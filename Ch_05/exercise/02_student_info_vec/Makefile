#файл для сборки проекта 1_triangle
CXX = g++
#CXXFLAG = `fltk-config --ldflags --use-images`
CLEAN = rm -f
PROGRAM_NAME = main.out
######################################################
objects = main.o Student_info.o grade.o median.o Extract_fails.o 
main = main.cpp
extract_fails	= Extract_fails.cpp
path = ../../Student_info
Student_info 	= $(path)/Student_info.cpp  
grade			= $(path)/grade.cpp 
median			= $(path)/median.cpp 

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(objects) 
	$(CXX) $(CXXFLAG) $(objects) -o $(PROGRAM_NAME) 

main.o: $(main) 
	$(CXX) -c $(main) 

Student_info.o: $(Student_info) 
	$(CXX) -c $(Student_info) 

grade.o: $(graph) 
	$(CXX) -c $(grade) 

median.o: $(median) 
	$(CXX) -c $(median) 

Extract_fails.o: $(extract_fails)
	$(CXX) -c $(extract_fails)

test:
	./main.out < data/grades 

clean:
	$(CLEAN) *.o
	$(CLEAN) $(PROGRAM_NAME) 