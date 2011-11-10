CXX = g++
CXXFLAGS = -O2 -pedantic -Wall
LIBS = -lm
SOURCE = $(wildcard *.cpp)
CLEANLS = $(shell ls | egrep -v '\.c|\.cpp|\.h|Makefile|dependency')

all : depend ex1 ex2 ex3 ex5 sine sine2 examples

ex1 : ex1.o
	$(CXX) $(LIBS) -o $@ $?

ex2 : ex2.o line.o
	$(CXX) $(LIBS) -o $@ $?

ex3 : ex3.o line2.o
	$(CXX) $(LIBS) -o $@ $?

sine : sine.o line2.o
	$(CXX) $(LIBS) -o $@ $?

sine2 : sine2.o lines.o
	$(CXX) $(LIBS) -o $@ $?

ex5: ex5.o lines.o lineList.o
	$(CXX) $(LIBS) -o $@ $?

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

examples:
	@echo "ALL DONE\n"
	@echo "Examples:"
	@echo "./ex1 ex1.ps 0 500 300 700"
	@echo "./ex2 ex2.ps 0 500 300 700"
	@echo "./ex3 ex3.ps 0 500 300 700"
	@echo "./sine sine.ps 0 500 10 10 10 10"
	@echo "./sine2 sine2.ps 0 500 10 10 10 10"
	@echo "./ex5 ex5.ps"

clean :
	rm -f $(CLEANLS)
	cat /dev/null > dependency

depend: $(SOURCE)
	$(CXX) -MM $(SOURCE) > dependency

include dependency
