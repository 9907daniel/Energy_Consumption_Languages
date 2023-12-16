// // main.cc
// #include <drogon/drogon.h>
// #include <drogon/HttpFileUpload.h>

// using namespace drogon;

// int main() {
//     // Set HTTP listener address and port
//     drogon::app().addListener("0.0.0.0", 5555);

//     // Add route for file upload
//     drogon::app().registerHandler("/upload", [](const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback) {
//         if (req->method() == HttpMethod::Post) {
//             auto files = req->getUploadedFiles();
//             if (!files.empty()) {
//                 // Process the uploaded files here
//                 // For demonstration purposes, just print the file names
//                 for (const auto& file : files) {
//                     LOG_DEBUG << "Uploaded file: " << file.getFileName();
//                 }

//                 // Respond with a success message
//                 auto resp = HttpResponse::newHttpResponse();
//                 resp->setStatusCode(HttpStatusCode::k200OK);
//                 resp->setContentTypeCodeAndCustomString(CT_TEXT_HTML, "text/html");
//                 resp->setBody("File(s) uploaded successfully!");
//                 callback(resp);
//                 return;
//             }
//         }

//         // Respond with an error message if the request is not valid
//         auto resp = HttpResponse::newHttpResponse();
//         resp->setStatusCode(HttpStatusCode::k400BadRequest);
//         resp->setContentTypeCodeAndCustomString(CT_TEXT_HTML, "text/html");
//         resp->setBody("Bad request - please upload a file!");
//         callback(resp);
//     }, {Post});

//     // Run the HTTP framework; the method will block in the internal event loop
//     drogon::app().run();

//     return 0;
// }

#include <drogon/drogon.h>
#include <random>

int generateRandomNumber() {
    // Use std::random_device to seed the random number generator
    std::random_device rd;
    // Use std::mt19937 as the random number engine
    std::mt19937 gen(rd());
    // Use std::uniform_int_distribution to generate random integers in the desired range
    std::uniform_int_distribution<int> distribution(0, 99); // Adjust the range as needed

    return distribution(gen);
}

int main() {
    // Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0", 5555);

    // Generate and print 100000 random numbers
    for (int i = 0; i < 1000000; ++i) {
        int randomNumber = generateRandomNumber();
        // Use randomNumber as needed
        // std::cout << "Random Number: " << randomNumber << std::endl;
    }

    // Load config file
    // drogon::app().loadConfigFile("../config.json");
    // drogon::app().loadConfigFile("../config.yaml");

    // Run HTTP framework; the method will block in the internal event loop
    // drogon::app().run();

    std::exit(0);

    return 0;
}



// #include <drogon/drogon.h>
// int main() {
//     //Set HTTP listener address and port
//     drogon::app().addListener("0.0.0.0", 5555);
//     //Load config file
//     //drogon::app().loadConfigFile("../config.json");
//     //drogon::app().loadConfigFile("../config.yaml");
//     //Run HTTP framework,the method will block in the internal event loop
//     drogon::app().run();
//     return 0;
// }
