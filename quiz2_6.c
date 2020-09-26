#include "quiz2_6.h"

int singleNumber_repeat3(int *nums, int numsSize) {
  int lower = 0, higher = 0;
  for (int i = 0; i < numsSize; i++) {
    lower ^= nums[i];
    lower &= ~higher; // KKK
    higher ^= nums[i];
    higher &= ~lower; // JJJ
  }
  return lower;
}

int singleNumber_repeat4(int *nums, int numsSize) {
  int lower = 0, higher = 0;
  for (int i = 0; i < numsSize; i++) {
    int last_lower = lower;
    lower = lower ^ nums[i];
    higher = (nums[i] & (higher & last_lower)) | (~nums[i] & higher);
  }
  return lower;
}

int singleNumber_repeat5(int *nums, int numsSize) {
  int one = 0, two = 0,
      three = 0; // which means repeat 1, 2, 3 times respectively
  for (int i = 0; i < numsSize; i++) {
    int lastone = one;
    int lasttwo = two;
    one = ~three & (one ^ nums[i]);
    two = (~nums[i] & ~three & two) | (~three & two & ~lastone) |
          (nums[i] & ~three & ~two & lastone);
    three = (~nums[i] & three & ~lasttwo & ~lastone) |
            (nums[i] & ~three & lasttwo & lastone);
  }
  return one;
}
