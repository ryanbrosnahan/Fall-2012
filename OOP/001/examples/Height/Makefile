##
# Build height

.PHONY : all
all : height trajectory_t

height : height.o trajectory.o
	g++ height.o trajectory.o -o height

height.o : height.cpp
	g++ -c height.cpp

trajectory.o : trajectory.cpp
	g++ -c trajectory.cpp

trajectory_t : trajectory_t.o trajectory.o
	g++ trajectory_t.o trajectory.o -o trajectory_t

trajectory_t.o : trajectory_t.cpp
	g++ -c trajectory_t.cpp

.PHONY : run
run :
	./height

.PHONY : test
test :
	./trajectory_t

.PHONY : clean
clean :
	rm -f trajectory.o height.o height trajectory_t.o trajectory_t

