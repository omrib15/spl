# All Targets
all: cyber


# Executable "cyber" depends on the files cyberpc.o cyberworm.o cyberdns.o cyberexpert.o main.o computers.o simulation.o
cyber: bin/cyberpc.o bin/cyberworm.o bin/cyberdns.o bin/cyberexpert.o bin/main.o bin/computers.o bin/simulation.o 
		g++ -g -Wall -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/simulation.o src/simulation.cpp
		g++ -g -Wall -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/computers.o src/computers.cpp
		g++ -o bin/cyber bin/cyberpc.o bin/cyberworm.o bin/cyberdns.o bin/cyberexpert.o bin/main.o  bin/computers.o bin/simulation.o

# Depends on the source and header files
bin/cyberpc.o: src/cyberpc.cpp
		g++ -g -Wall -c -Linclude -o bin/cyberpc.o src/cyberpc.cpp
bin/cyberworm.o: src/cyberworm.cpp
		g++ -g -Wall -c -Linclude -o bin/cyberworm.o src/cyberworm.cpp
bin/cyberexpert.o: src/cyberexpert.cpp
		g++ -g -Wall -c -Linclude -o bin/cyberexpert.o src/cyberexpert.cpp
bin/cyberdns.o: src/cyberdns.cpp
		g++ -g -Wall -c -Linclude -o bin/cyberdns.o src/cyberdns.cpp
bin/main.o: src/main.cpp
		g++ -g -Wall -c -Linclude -o bin/main.o src/main.cpp
bin/computers.o: src/computers.cpp
		g++ -g -Wall -c -Linclude -o bin/computers.o src/computers.cpp
bin/simulation.o: src/simulation.cpp
		g++ -g -Wall -c -Linclude -o bin/simulation.o src/simulation.cpp
#Clean the build directory
clean: 
		rm -f bin/*