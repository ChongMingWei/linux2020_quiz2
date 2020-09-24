#include "quiz2_2.h"

uint8_t hexchar2val(uint8_t in)
{
    const uint8_t letter = in & 0x40;//MASK
    const uint8_t shift = (letter >> 3) | (letter >> 6);//AAA, BBB
    return (in + shift) & 0xf;
}

uint32_t hexchar2val_modified(const char str[])
{
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
        str += 2;//一開始先將`str`的位址+2以略過`0`以及`x`
    uint32_t sum = 0;//用來累加每一個16進位符號所代表的真實數值
    for (int i = 0;str[i]!='\0';++i){
        sum = sum << 4;//針對上一次的結果先左移4個bits
        uint8_t letter = str[i] & 0x40;//下三行的部分為舊版進行數值轉換的方式
        uint8_t shift = letter >> 3 | letter >> 6;
        uint32_t transform = (str[i] + shift)&0xf;
        sum +=transform;
    }
    return sum;
}
