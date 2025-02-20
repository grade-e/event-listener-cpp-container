#include <atomic>
#include <functional>
#include <iostream>
#include <random>
#include <thread>

class DataSource {
   private:
    std::function<void(const std::string&)> data_callback_;  // 데이터 콜백
    std::function<void(int)> state_callback_;                // 상태 콜백

   public:
    // 데이터 수신 콜백 등록
    void registerDataCallback(std::function<void(const std::string&)> cb) {
        data_callback_ = cb;
    }

    // 상태 변경 콜백 등록
    void registerStateCallback(std::function<void(int)> cb) {
        state_callback_ = cb;
    }

    // 데이터 발생 (예제에서는 1초마다 호출)
    void generateData(const std::string& data) {
        if (data_callback_) {
            data_callback_(data);
        }
    }

    // 상태 변경 (예제에서는 상태 변경 후 호출)
    void updateState(int state) {
        if (state_callback_) {
            state_callback_(state);
        }
    }
};