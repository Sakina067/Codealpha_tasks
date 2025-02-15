#include <iostream>
#include <string>

std::string chatbot_response(const std::string &input) {
    if (input.find("hello") != std::string::npos || input.find("hi") != std::string::npos)
        return "Hello! How can I help you today?";
    if (input.find("how are you") != std::string::npos)
        return "I'm just a bot, but I'm doing great!";
    if (input.find("name") != std::string::npos)
        return "I'm a simple AI chatbot.";
    if (input.find("bye") != std::string::npos)
        return "Goodbye! Have a nice day!";
    return "I'm not sure how to respond to that.";
}

int main() {
    std::string input;
    std::cout << "Chatbot: Hello! Type 'bye' to exit.\n";

    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, input);
        
        if (input == "bye") {
            std::cout << "Chatbot: Goodbye!\n";
            break;
        }

        std::cout << "Chatbot: " << chatbot_response(input) << "\n";
    }

    return 0;
}