package com.example.demo;

import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.multipart.support.StandardMultipartHttpServletRequest;

import jakarta.servlet.http.HttpServletRequest;
import java.util.Random;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;

@SpringBootApplication
@Controller
public class DemoApplication implements CommandLineRunner {

    @RequestMapping("/")
    public String home() {
        return "upload";
    }

    @PostMapping("/upload")
    @ResponseBody
    public String handleFileUpload(@RequestParam("file") MultipartFile file) {
        if (!file.isEmpty()) {
            try {
                // Change the destination directory accordingly
                File uploadDir = new File("uploads");
                uploadDir.mkdirs();

                File dest = new File(uploadDir, file.getOriginalFilename());
                file.transferTo(dest);

                // Trigger RAPL benchmark here
                triggerRAPLBenchmark(file.getOriginalFilename());

                return "File uploaded successfully!";
            } catch (IOException | RuntimeException e) {
                e.printStackTrace();
                return "Error uploading file";
            }
        } else {
            return "File is empty!";
        }
    }

    private void triggerRAPLBenchmark(String filename) {
        // Execute RAPL benchmark command using the uploaded file
        String command = "sudo ../../RAPL/main " + "$(JAVA_HOME)/bin/java -cp . " + filename;
        try {
            Process process = Runtime.getRuntime().exec(command);
            process.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        SpringApplication.run(DemoApplication.class, args);
    }

    @Override
    public void run(String... args) throws Exception {
        // Automatically upload a file on application startup
        String filePath = "src/main/resources/static/test.txt";
        File fileToUpload = new File(filePath);

        for (int i = 0; i < 100000; i++) {
            int randomNumber = generateRandomNumber();
            // System.out.println("Random Number: " + randomNumber);
        }

		System.exit(SpringApplication.exit(SpringApplication.run(DemoApplication.class)));
	    }

    private int generateRandomNumber() {
        Random random = new Random();
        return random.nextInt(100); // Adjust the range as needed
    }
}

