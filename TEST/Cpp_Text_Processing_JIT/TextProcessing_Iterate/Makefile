# # CXX := g++
# # CXXFLAGS := -std=c++11 -Wall -Wextra

# # SOURCE := text_processing.c++
# # EXECUTABLE := text_processing

# # .PHONY: compile measure

# # compile: $(EXECUTABLE)

# # $(EXECUTABLE): $(SOURCE)
# # 	$(CXX) $(CXXFLAGS) -o $@ $<

# # measure: $(EXECUTABLE)
# # 	sudo modprobe msr
# # 	sudo ../../RAPL/main "./$(EXECUTABLE)" C++ text-processing-iterate-JIT

# # clean:
# # 	rm -f $(EXECUTABLE)


# CXX := g++
# CXXFLAGS := -std=c++11 -Wall -Wextra $(shell llvm-config --cxxflags)
# LDFLAGS := $(shell llvm-config --ldflags)

# SOURCE := text_processing.c++
# EXECUTABLE := text_processing

# .PHONY: compile measure

# compile: $(EXECUTABLE)

# $(EXECUTABLE): $(SOURCE)
# 	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

# measure: $(EXECUTABLE)
# 	sudo modprobe msr
# 	sudo ../../RAPL/main "./$(EXECUTABLE)" C++ text-processing-iterate-JIT

# clean:
# 	rm -f $(EXECUTABLE)
CXX := g++

LLVM_PREFIX := /usr/lib/llvm-14
LLVM_CONFIG := $(LLVM_PREFIX)/bin/llvm-config

CXXFLAGS := -std=c++14 $(shell $(LLVM_CONFIG) --cxxflags)
LDFLAGS := $(shell $(LLVM_CONFIG) --ldflags --system-libs --libs core orcjit native)

SOURCE := text_processing.c++
EXECUTABLE := text_processing

.PHONY: compile measure

compile: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

measure: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
