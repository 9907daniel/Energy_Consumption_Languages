JAVA_HOME := /usr/lib/jvm/java-11-openjdk-amd64

compile:
	cp pidigits.java-2.java pidigits.java
	$(JAVA_HOME)/bin/javac -d . pidigits.java

measure:
	sudo modprobe msr
	sudo ../../RAPL/main "$(JAVA_HOME)/bin/java -Djava.library.path=Include/java pidigits 10000" Java pidigits

run:
	$(JAVA_HOME)/bin/java -Djava.library.path=Include/java pidigits 10000

mem:
	/usr/bin/time -v $(JAVA_HOME)/bin/java -Djava.library.path=Include/java pidigits 10000

valgrind:
	valgrind --tool=massif --stacks=yes $(JAVA_HOME)/bin/java -Djava.library.path=Include/java pidigits 10000
