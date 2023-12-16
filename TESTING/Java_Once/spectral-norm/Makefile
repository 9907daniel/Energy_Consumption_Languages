JAVA_HOME := /usr/lib/jvm/java-11-openjdk-amd64

compile:
	cp spectralnorm.java-2.java spectralnorm.java
	$(JAVA_HOME)/bin/javac -d .  spectralnorm.java
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "$(JAVA_HOME)/bin/java spectralnorm 5500" Java spectral-norm

run:
	$(JAVA_HOME)/bin/java spectralnorm 5500

mem:
	/usr/bin/time -v $(JAVA_HOME)/bin/java   spectralnorm 5500

valgrind:
	valgrind --tool=massif --stacks=yes $(JAVA_HOME)/bin/java   spectralnorm 5500
