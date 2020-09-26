#include "quiz2_1.h"
#define PACKED_BYTE(b) (((uint64_t)(b) & (0xff)) * 0x0101010101010101u)
bool is_ascii(const char str[], size_t size)
{
    if (size == 0)
        return false;
    int i = 0;
    while ((i + 8) <= size) {
        /* Casting method */
        // uint64_t *payload = str
        // if (*payload & 0x8080808080808080)
        //    return false;
        uint64_t payload;
        memcpy(&payload, str + i, 8);
        if (payload & 0x8080808080808080)
            return false;
        i += 8;
    }
    while (i < size) {
        if (str[i] & 0x80)
            return false;
        i++;
    }
    return true;
}

bool is_alphabet(const char str[], size_t size)
{
    if (size == 0)
        return false;
    int i = 0;
    while ((i + 8) <= size) {
        uint64_t payload;
        memcpy(&payload, str + i, 8);

        uint64_t A = payload + PACKED_BYTE(128 - 'A'); 
        uint64_t Z = payload + PACKED_BYTE(128 - 'Z' - 1); 
        uint64_t a = payload + PACKED_BYTE(128 - 'a'); 
        uint64_t z = payload + PACKED_BYTE(128 - 'z' - 1); 
        uint64_t upper_mask = A ^ Z;
        uint64_t lower_mask = a ^ z;
        upper_mask &= PACKED_BYTE(0x80);
        lower_mask &= PACKED_BYTE(0x80);
        if(upper_mask | lower_mask)
            return true;
        i += 8;
    }
    while (i < size) {
        uint8_t A = str[i] + 128 - 'A'; 
        uint8_t Z = str[i] + 128 - 'Z' - 1; 
        uint8_t a = str[i] + 128 - 'a'; 
        uint8_t z = str[i] + 128 - 'z' - 1; 
        uint8_t upper_mask = A ^ Z;
        uint8_t lower_mask = a ^ z;
        upper_mask &= 0x80;
        lower_mask &= 0x80;
        if(upper_mask | lower_mask)
            return true;
        i++;
    }
    return false;
}
