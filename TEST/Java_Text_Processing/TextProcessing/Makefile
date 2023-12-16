JAVA_HOME := /usr/lib/jvm/java-11-openjdk-amd64

compile:
	$(JAVA_HOME)/bin/javac -d .  TextProcessingBenchmark.java
measure:
	sudo modprobe msr
	sudo ../../RAPL/main "$(JAVA_HOME)/bin/java TextProcessingBenchmark " Java text-processing
