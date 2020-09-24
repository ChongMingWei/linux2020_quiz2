#include "quiz2_5.h"
#define PACKED_BYTE(b) (((uint64_t) b & 0xff) * 0x0101010101010101u)
void strlower(char *s, size_t n)
{
    for (size_t j = 0; j < n; j++) {
        if (s[j] >= 'A' && s[j] <= 'Z')
            s[j] ^= 1 << 5;
        else if ((unsigned) s[j] >= '\x7f') /* extended ASCII */
            s[j] = tolower(s[j]);
    }
}
/* To avoid the address unaligned problem, use memcpy
 * to load the content. However, after we change the 
 * content of chunk. We have to write it back to s.
 */
void strlower_vector(char *s, size_t n)
{
    size_t k = n / 8;
    for (size_t i = 0; i < k; ++i, s+=8){
        //uint64_t *chunk = (uint64_t *)s;
        uint64_t chunk;
        memcpy(&chunk, s, 8);
        if ((chunk & PACKED_BYTE(0x80)) == 0) {
            uint64_t A = chunk + PACKED_BYTE(128 - 'A');
            uint64_t Z = chunk + PACKED_BYTE(128 - 'Z' - 1);
            uint64_t mask = ((A ^ Z) & PACKED_BYTE(0X80)) >> 2;
            chunk ^= mask;
            memcpy(s,&chunk, 8);
        } else {
            strlower(s, 8);
        }
    }
    
    k = n % 8;
    if (k)
        strlower(s, k);
}
