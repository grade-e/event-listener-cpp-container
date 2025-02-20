#include <iostream>

#include "data_source.hpp"

class MyNode {
   private:
    DataSource& data_source_;

   public:
    MyNode(DataSource& ds) : data_source_(ds) {
        // 콜백 등록
        data_source_.registerDataCallback(
            [this](const std::string& data) { onDataReceived(data); });

        data_source_.registerStateCallback(
            [this](int state) { onStateChanged(state); });
    }

    // 데이터가 들어왔을 때 실행될 콜백
    void onDataReceived(const std::string& data) {
        std::cout << "[MyNode] Received Data: " << data << std::endl;
    }

    // 상태 변경 시 실행될 콜백
    void onStateChanged(int state) {
        std::cout << "[MyNode] State Changed: " << state << std::endl;
    }
};