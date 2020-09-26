#ifndef QUIZ2_3_H
#define QUIZ2_3_H
/* Faster Division and Module */
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint32_t quickmod(uint32_t n);
bool divisible(uint32_t n);
typedef struct div_info_s div_info_t;
struct div_info_s {
  uint32_t magic;
};
void div_init(div_info_t *div_info, size_t d);
size_t div_compute(div_info_t *div_info, size_t n);
#endif
