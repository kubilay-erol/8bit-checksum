# 8-Bit Two's Complement Checksum

A lightweight, high-performance error-detection mechanism written in C++. This algorithm is widely used in microcontrollers.

## How It Works

The algorithm relies on modular arithmetic ($2^8 = 256$). 

1. **Sender (`create_checksum`)**: Sums up all data bytes. It returns the negative counterpart (`-sum`), which is the exact piece needed to force the grand total to roll over to `0`.
2. **Receiver (`verify_checksum`)**: Sums all data bytes *plus* the checksum byte. If the data is uncorrupted, the 8-bit accumulator naturally overflows and hits exactly `0`.
