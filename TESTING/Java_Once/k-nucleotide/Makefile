JAVA_HOME := /usr/lib/jvm/java-11-openjdk-amd64

compile:
	$(JAVA_HOME)/bin/javac -d . -cp .:/usr/bin//fastutil-7.0.12.jar knucleotide.java

measure:
	sudo modprobe msr
	sudo ../../RAPL/main "$(JAVA_HOME)/bin/java knucleotide 0 < ../../knucleotide-input5000000.txt"

run:
	$(JAVA_HOME)/bin/java knucleotide 0 < ../../knucleotide-input5000000.txt

mem:
	/usr/bin/time -v $(JAVA_HOME)/bin/java knucleotide 0 < ../../knucleotide-input5000000.txt

valgrind:
	valgrind --tool=massif --stacks=yes $(JAVA_HOME)/bin/java knucleotide 0 < ../../knucleotide-input5000000.txt
