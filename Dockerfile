FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

COPY data/sample_input.txt /app/

RUN rm -rf build && mkdir build && cd build && cmake .. && cmake --build .

CMD ["./build/solver"]
