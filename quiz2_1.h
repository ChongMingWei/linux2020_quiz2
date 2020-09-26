#ifndef QUIZ2_1_H
#define QUIZ2_1_H
/* This if for checking if there contains any ASCII code in a word (64bit).
 * And check if threr contains any alphabet (upper or lower case).
 */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
bool is_ascii(const char str[], size_t size);
bool is_alphabet(const char str[], size_t size);
#endif
