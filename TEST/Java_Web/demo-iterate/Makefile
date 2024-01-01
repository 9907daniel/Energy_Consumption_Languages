JAVA_HOME := /usr/lib/jvm/java-17-openjdk-amd64

MAIN_CLASS := com.example.demo.DemoApplication

run-spring-boot:
	$(CURDIR)/mvnw spring-boot:run

measure-spring-boot:
	sudo modprobe msr
	sudo ../../RAPL/main "$(CURDIR)/mvnw spring-boot:run" Java spring-boot-iterate
