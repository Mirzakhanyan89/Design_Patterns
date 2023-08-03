/*	facade.cpp	*/

#include <iostream>
#include <string>

// Subsystems: Individual components of the smartphone
class CallSystem {
public:
    void makeCall(const std::string& number) {
        std::cout << "Calling " << number << "...\n";
    }
};

class MessageSystem {
public:
    void sendMessage(const std::string& recipient, const std::string& message) {
        std::cout << "Sending message to " << recipient << ": " << message << "\n";
    }
};

class InternetSystem {
public:
    void browse(const std::string& url) {
        std::cout << "Accessing " << url << "...\n";
    }
};

// Facade class to simplify interactions with the smartphone
class SmartphoneFacade {
public:
    SmartphoneFacade() {
        callSystem = new CallSystem();
        messageSystem = new MessageSystem();
        internetSystem = new InternetSystem();
    }

    ~SmartphoneFacade() {
        delete callSystem;
        delete messageSystem;
        delete internetSystem;
    }

    // Facade methods for user interactions
    void makeCall(const std::string& number) {
        callSystem->makeCall(number);
    }

    void sendMessage(const std::string& recipient, const std::string& message) {
        messageSystem->sendMessage(recipient, message);
    }

    void browseInternet(const std::string& url) {
        internetSystem->browse(url);
    }
private:
    CallSystem* callSystem;
    MessageSystem* messageSystem;
    InternetSystem* internetSystem;
};

// Client code
int main() {
    // Using the Facade to interact with the smartphone functionalities
    SmartphoneFacade smartphone;

    smartphone.makeCall("123456789");
    smartphone.sendMessage("John", "Hello, how are you?");
    smartphone.browseInternet("www.example.com");

    return 0;
}

