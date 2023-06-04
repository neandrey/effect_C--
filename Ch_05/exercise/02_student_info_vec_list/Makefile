#файл для сборки проекта 1_triangle
CXX = g++
CXXFLAG = -Wall 
CLEAN = rm -f
PROGRAM_NAME_VEC  = main_vec.out
PROGRAM_NAME_LIST = main_list.out 
######################################################
obj_vec = main_vec.o Student_info.o grade.o median.o Extract_fails_vec.o 
obj_list= main_list.o Student_info.o grade.o median.o Extract_fails_list.o 

main_vec 	= main_vec.cpp
main_list 	= main_list.cpp

extract_fails_vec		= Extract_fails_vec.cpp
extract_fails_list		= Extract_fails_list.cpp
# direct_files
path = ../../Student_info
Student_info 	= $(path)/Student_info.cpp  
grade			= $(path)/grade.cpp 
median			= $(path)/median.cpp 

all: $(PROGRAM_NAME_LIST) 
all: $(PROGRAM_NAME_VEC)

$(PROGRAM_NAME_LIST): $(obj_list) 
	$(CXX) $(CXXFLAG) $(obj_list) -o $(PROGRAM_NAME_LIST) 

$(PROGRAM_NAME_VEC): $(obj_vec) 
	$(CXX) $(CXXFLAG) $(obj_vec) -o $(PROGRAM_NAME_VEC) 

main_vec.o: $(main_vec) 
	$(CXX) -c $(main_vec) 

main_list.o: $(main_list) 
	$(CXX) -c $(main_list) 

Student_info.o: $(Student_info) 
	$(CXX) -c $(Student_info) 

grade.o: $(graph) 
	$(CXX) -c $(grade) 

median.o: $(median) 
	$(CXX) -c $(median) 

Extract_fails_vec.o: $(extract_fails_vec)
	$(CXX) -c $(extract_fails_vec)

Extract_fails_list.o: $(extract_fails_list)
	$(CXX) -c $(extract_fails_list)


test:
	./main_list.out < data/100
	./main_list.out < data/1000
	./main_list.out < data/10000
	./main_vec.out < data/100
	./main_vec.out < data/1000
	./main_vec.out < data/10000

clean:
	$(CLEAN) *.o
	$(CLEAN) $(PROGRAM_NAME) 