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


int main() {
    uint8_t package[4] = {37, 53, 20, 0};
    
    uint8_t my_checksum = create_checksum(package, 3); 
    
    package[3] = my_checksum; 

    bool is_valid = verify_checksum(package, 4); 
    
}
