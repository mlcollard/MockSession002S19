# Test program for Session class

.PHONY: all
all : session_t

session_t : session_t.o
	g++ -std=c++11 $< -o $@

session_t.o : session_t.cpp
	g++ -std=c++11 -c $<

.PHONY: test
test : session_t
	./session_t

.PHONY: clean
clean :
	rm -f session_t session_t.o
