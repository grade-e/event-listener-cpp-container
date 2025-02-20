#include "my_node.hpp"

int main() {
    DataSource source;
    MyNode node(source);

    // 테스트: 데이터와 상태를 변경
    source.generateData("Hello, World!");
    source.updateState(1);

    // 1초 대기 후 추가 데이터
    std::this_thread::sleep_for(std::chrono::seconds(1));
    source.generateData("Another Message");
    source.updateState(2);

    return 0;
}