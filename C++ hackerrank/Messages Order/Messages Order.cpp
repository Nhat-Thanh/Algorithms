#include <algorithm>
#include <iostream>
#include <vector>

class Message {
    std::string text;
    int id;

  public:
    int static index;
    Message() { id = index++; }
    Message(const std::string& text) {
        this->text = text;
        id = index++;
    }
    const std::string& get_text() {
        return text;
    }

    bool operator<(const Message& msg) {
        return this->id < msg.id;
    }
};

int Message::index = 0;

class MessageFactory {
  public:
    MessageFactory() {}
    Message create_message(const std::string& text) {
        Message msg(text);
        return msg;
    }
};

class Recipient {
  public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            std::cout << msg.get_text() << '\n';
        }
        messages_.clear();
    }

  private:
    void fix_order() {
        std::sort(messages_.begin(), messages_.end());
    }
    std::vector<Message> messages_;
};

class Network {
  public:
    static void send_messages(std::vector<Message> messages, Recipient& recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};

int main() {
    MessageFactory message_factory;
    Recipient recipient;
    std::vector<Message> messages;
    std::string text;
    while (getline(std::cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
