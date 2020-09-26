#include "quiz2_3.h"
const uint32_t D = 3;
#define M ((uint64_t)(UINT64_C(0xFFFFFFFFFFFFFFFF) / (D) + 1))
#include <time.h>
uint32_t quickmod(uint32_t n)
{   uint64_t quotient = ((__uint128_t) M * n) >> 64;
    return n - quotient * D;
}

bool divisible(uint32_t n)
{
    return n * M <= M - 1;//YYY
}

void div_init(div_info_t *div_info, size_t d)
{
    /* Nonsensical. */
	assert(d != 0);
	/*
	 * This would make the value of magic too high to fit into a uint32_t
	 * (we would want magic = 2^32 exactly). This would mess with code gen
	 * on 32-bit machines.
	 */
	assert(d != 1);

	uint64_t two_to_k = ((uint64_t)1 << 32);
	uint32_t magic = (uint32_t)(two_to_k / d);

	/*
	 * We want magic = ceil(2^k / d), but C gives us floor. We have to
	 * increment it unless the result was exact (i.e. unless d is a power of
	 * two).
	 */
	if (two_to_k % d != 0) {
		magic++;
	}
	div_info->magic = magic;
}
size_t div_compute(div_info_t *div_info, size_t n)
{
    assert(n <= (uint32_t)-1);
	/*
	 * This generates, e.g. mov; imul; shr on x86-64. On a 32-bit machine,
	 * the compilers I tried were all smart enough to turn this into the
	 * appropriate "get the high 32 bits of the result of a multiply" (e.g.
	 * mul; mov edx eax; on x86, umull on arm, etc.).
	 */
	size_t i = ((uint64_t)n * (uint64_t)div_info->magic) >> 32;
	return i;
}
