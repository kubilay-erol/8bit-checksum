# 8-Bit Two's Complement Checksum

A lightweight, high-performance error-detection mechanism written in C++. This algorithm is widely used in embedded systems, microcontrollers, and low-level network protocols (like IPv4 headers) to detect accidental data corruption.

## How It Works

The algorithm relies on modular arithmetic ($2^8 = 256$). 

1. **Sender (`create_checksum`)**: Sums up all data bytes. It returns the negative counterpart (`-sum`), which is the exact "puzzle piece" needed to force the grand total to roll over to `0`.
2. **Receiver (`verify_checksum`)**: Sums all data bytes *plus* the checksum byte. If the data is uncorrupted, the 8-bit accumulator naturally overflows and hits exactly `0`.

## Code Implementation

```cpp
#include <cstdint>
#include <cstddef>

uint8_t create_checksum(const uint8_t* data, size_t length) {
    uint8_t sum = 0;
    for (size_t i = 0; i < length; ++i) {
        sum += data[i];
    }
    return -sum;
}

bool verify_checksum(const uint8_t* buffer, size_t length) {
    uint8_t accumulator = 0;
    for (size_t i = 0; i < length; ++i) {
        accumulator += buffer[i];
    }
    return (accumulator == 0);
}
