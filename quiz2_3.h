#ifndef QUIZ2_3_H
#define QUIZ2_3_H
/* Faster Division and Module */
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
uint32_t quickmod(uint32_t n);
size_t div_compute(size_t n, size_t d);
bool divisible(uint32_t n);
#endif
