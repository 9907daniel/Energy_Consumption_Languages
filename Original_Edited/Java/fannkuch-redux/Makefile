JAVA_HOME := /usr/lib/jvm/java-11-openjdk-amd64

compile:
	cp fannkuchredux.java fannkuchredux.java.orig
	$(JAVA_HOME)/bin/javac -d . fannkuchredux.java

measure:
	sudo modprobe msr
	sudo ../../RAPL/main "$(JAVA_HOME)/bin/java fannkuchredux 12" Java fannkuch-redux

run:
	$(JAVA_HOME)/bin/java fannkuchredux 12

mem:
	/usr/bin/time -v $(JAVA_HOME)/bin/java fannkuchredux 12

valgrind:
	valgrind --tool=massif --stacks=yes $(JAVA_HOME)/bin/java fannkuchredux 12