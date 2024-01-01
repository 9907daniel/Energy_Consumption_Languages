CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

SOURCE := text_processing.c++
EXECUTABLE := text_processing

.PHONY: compile measure

compile: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $@ $<

measure: $(EXECUTABLE)
	sudo modprobe msr
	sudo ../../RAPL/main "./$(EXECUTABLE)" C++ text-processing

clean:
	rm -f $(EXECUTABLE)
