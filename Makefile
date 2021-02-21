CXX = g++
CFLAGS = -Wall -pedantic
LIST = list
STACK = stack
QUEUE = queue

.PHONY: all clean

all: $(LIST) $(STACK) $(QUEUE)

$(LIST): test_$(LIST).cpp List.hpp
	$(CXX) $< -o $@

$(STACK): test_$(STACK).cpp Stack.hpp List.hpp
	$(CXX) $< -o $@

$(QUEUE): test_$(QUEUE).cpp Queue.hpp List.hpp
	$(CXX) $< -o $@

clean:
	rm -f $(LIST) $(STACK) $(QUEUE)
