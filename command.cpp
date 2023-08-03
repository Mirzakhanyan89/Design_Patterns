/*	command.cpp		*/

#include <iostream>
#include <string>

// Command Interface
class Command {
public:
    virtual void execute() = 0;
};

// Receiver (TV)
class TV {
public:
    void turnOn() {
        std::cout << "TV is ON" << std::endl;
    }

    void turnOff() {
        std::cout << "TV is OFF" << std::endl;
    }

    void changeChannel(const std::string& channel) {
        std::cout << "Changed channel to " << channel << std::endl;
    }
};

// Concrete Command classes
class TurnOnCommand : public Command {
public:
    TurnOnCommand(TV* tv) : tv(tv) {}

    void execute() override {
        tv->turnOn();
    }
private:
    TV* tv;
};

class TurnOffCommand : public Command {
public:
    TurnOffCommand(TV* tv) : tv(tv) {}

    void execute() override {
        tv->turnOff();
    }
private:
    TV* tv;
};

class ChangeChannelCommand : public Command {
public:
    ChangeChannelCommand(TV* tv, const std::string& channel) : tv(tv), channel(channel) {}

    void execute() override {
        tv->changeChannel(channel);
    }
private:
    TV* tv;
    std::string channel;
};

// Invoker (Remote Control)
class RemoteControl {
public:
    void setCommand(Command* command) {
        this->command = command;
    }

    void pressButton() {
        if (command) {
            command->execute();
        }
    }
private:
    Command* command;
};

// Client Code
int main() {
    TV tv;

    TurnOnCommand turnOnCommand(&tv);
    TurnOffCommand turnOffCommand(&tv);
    ChangeChannelCommand changeChannelCommand(&tv, "Discovery Channel");

    RemoteControl remote;

    // Assign different commands to the remote's buttons
    remote.setCommand(&turnOnCommand);
    remote.pressButton();

    remote.setCommand(&changeChannelCommand);
    remote.pressButton();

    remote.setCommand(&turnOffCommand);
    remote.pressButton();

    return 0;
}

