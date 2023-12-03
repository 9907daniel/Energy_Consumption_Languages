JAVA_HOME := /usr/lib/jvm/java-11-openjdk-amd64

compile:
	cp regexredux.java-3.java regexredux.java
	$(JAVA_HOME)/bin/javac -d . regexredux.java

measure:
	sudo modprobe msr
	sudo ../../RAPL/main "$(JAVA_HOME)/bin/java regexredux 0 < ../../regexredux-input5000000.txt"

run:
	$(JAVA_HOME)/bin/java regexredux 0 < ../../regexredux-input5000000.txt

mem:
	/usr/bin/time -v $(JAVA_HOME)/bin/java regexredux 0 < ../../regexredux-input5000000.txt

valgrind:
	valgrind --tool=massif --stacks=yes $(JAVA_HOME)/bin/java regexredux 0 < ../../regexredux-input5000000.txt
