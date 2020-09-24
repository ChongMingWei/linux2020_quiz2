#include "quiz2_3.h"
const uint32_t D = 3;
#define M ((uint64_t)(UINT64_C(0xFFFFFFFFFFFFFFFF) / (D) + 1))

uint32_t quickmod(uint32_t n)
{   uint64_t quotient = ((__uint128_t) M * n) >> 64;
    return n - quotient * D;
}

size_t div_compute(size_t n, size_t d) 
{
    /* Nonsensical. */
    assert(d != 0);
    /*
     * This would make the value of magic too high to fit into a uint32_t
     * (we would want magic = 2^32 exactly). This would mess with code gen
     * on 32-bit machines.
     */
    assert(d != 1);
    assert(n <= (uint32_t)-1);
    /* Prepare 2^32/d */
    uint64_t two_to_k = ((uint64_t)1 << 32);
    uint32_t magic = (uint32_t)(two_to_k / d);
    if (two_to_k % d != 0) {
        magic++;
    }
    /* Compute quotient: n*(2^32/d)>>32 */
    size_t i = ((uint64_t)n * (uint64_t)magic) >> 32;
    return i;
}

bool divisible(uint32_t n)
{
    return n * M <= M - 1;//YYY
}
