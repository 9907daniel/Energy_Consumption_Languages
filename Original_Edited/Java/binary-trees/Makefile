JAVA_HOME := /usr/lib/jvm/java-11-openjdk-amd64

compile:
	cp binarytrees.java-7.java binarytrees.java
	$(JAVA_HOME)/bin/javac -d . binarytrees.java

measure:
	sudo modprobe msr
	sudo ../../RAPL/main "$(JAVA_HOME)/bin/java binarytrees 21" Java binary-trees

run:
	$(JAVA_HOME)/bin/java binarytrees 21

mem:
	/usr/bin/time -v $(JAVA_HOME)/bin/java binarytrees 21

valgrind:
	valgrind --tool=massif --stacks=yes $(JAVA_HOME)/bin/java binarytrees 21
