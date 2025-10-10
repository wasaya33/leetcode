#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int count = 32;

        while (count > 0) {
            uint32_t lastBit = n & 1;
            
            res = res << 1;
            
            res = res | lastBit;
            
            n = n >> 1;
            
            count--;
        }
        
        return res;
    }
};