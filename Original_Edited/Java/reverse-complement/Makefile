JAVA_HOME := /usr/lib/jvm/java-11-openjdk-amd64

compile:
	cp revcomp.java-3.java revcomp.java
	$(JAVA_HOME)/bin/javac -d . revcomp.java

measure:
	sudo modprobe msr
	sudo ../../RAPL/main "$(JAVA_HOME)/bin/java revcomp 0 < ../../revcomp-input25000000.txt" Java reverse-complement

run:
	$(JAVA_HOME)/bin/java revcomp 0 < ../../revcomp-input25000000.txt

mem:
	/usr/bin/time -v $(JAVA_HOME)/bin/java revcomp 0 < ../../revcomp-input25000000.txt

valgrind:
	valgrind --tool=massif --stacks=yes $(JAVA_HOME)/bin/java revcomp 0 < ../../revcomp-input25000000.txt
