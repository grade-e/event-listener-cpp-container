#include <atomic>
#include <functional>
#include <iostream>
#include <random>
#include <thread>

class DataSource {
   public:
    using DataCallback = std::function<void(const std::string&)>;

    void setCallback(DataCallback cb) { callback_ = cb; }

    void start() {
        running_ = true;
        worker_ = std::thread([this]() { generateData(); });
    }

    void stop() {
        running_ = false;
        if (worker_.joinable()) {
            worker_.join();
        }
    }

   private:
    void generateData() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, 5);  // 1~5초 랜덤 딜레이

        int count = 0;
        while (running_) {
            std::this_thread::sleep_for(
                std::chrono::seconds(dist(gen)));  // 랜덤 간격으로 데이터 생성
            std::string data = "Generated Data " + std::to_string(++count);
            if (callback_) {
                callback_(data);
            }
        }
    }
    DataCallback callback_;
    std::atomic<bool> running_{false};
    std::thread worker_;
};