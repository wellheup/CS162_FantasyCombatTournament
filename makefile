CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += O3
LDFLAGS = -lboost_date_time

#you can use either {} or () to contain sets of instructions

OBJS = main.o isValidInput.o menuShell.o die.o character.o barbarian.o blueMen.o harryPotter.o medusa.o vampire.o TeamNode.o TeamQueue.o game.o

SRCS = isValidInput.cpp menuShell.cpp main.cpp die.cpp character.cpp barbarian.cpp blueMen.cpp harryPotter.cpp medusa.cpp vampire.cpp TeamNode.cpp TeamQueue.cpp game.cpp

HEADERS = isValidInput.hpp menuShell.hpp die.hpp enums.hpp character.hpp barbarian.hpp blueMen.hpp harryPotter.hpp medusa.hpp vampire.hpp TeamNode.hpp TeamQueue.hpp game.hpp

DOCUMENTS = 

#target: dependencies
#	rules to build

main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: ${OBJS}
	rm -f *.o main 

#zip: ${SRCS} ${HEADERS} ${DOCUMENTS}
#	lab5_Wellheuser_Phillip.zip ${HEADERS}${SRCS}${DOCUMENTS}

#all: clean 



