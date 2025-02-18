#include "data_source.hpp"

class MyNode {
   public:
    MyNode() {
        data_source_.setCallback(
            [this](const std::string& data) { onDataReceived(data); });
        data_source_.start();
    }

    ~MyNode() { data_source_.stop(); }

   private:
    void onDataReceived(const std::string& data) {
        std::cout << "[MyNode] Received: " << data << std::endl;
    }

    DataSource data_source_;
};