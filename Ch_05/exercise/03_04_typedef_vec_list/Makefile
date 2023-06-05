#файл для сборки проекта 1_triangle
CXX = g++
CXXFLAG = -Wall 
CLEAN = rm -f
PROGRAM_NAME = main.out
######################################################
object = main.o Student_info.o grade.o median.o\
		Extract_fails.o f_sort.o

main = main.cpp
extract_fails		= Extract_fails.cpp
f_sort				= f_sort.cpp

path 		= ../../Student_info
path_data 	= ../../Student_data

Student_info 	= $(path)/Student_info.cpp  
grade			= $(path)/grade.cpp 
median			= $(path)/median.cpp 

all: $(PROGRAM_NAME) 

$(PROGRAM_NAME): $(object) 
	$(CXX) $(CXXFLAG) $(object) -o $(PROGRAM_NAME) 

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

f_sort.o: $(f_sort)
	$(CXX) -c $(f_sort)

test:
	./main.out < $(path_data)/100

clean:
	$(CLEAN) *.o
	$(CLEAN) $(PROGRAM_NAME) 