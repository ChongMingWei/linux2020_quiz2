#include "quiz2_5.h"
int main(){
        /* quote from https://www.gutenberg.org/files/74/74-h/74-h.htm */
    char *str =
        "This eBook is for the use of anyone anywhere at no cost and with \
almost no restrictions whatsoever.  You may copy it, give it away or \
re-use it under the terms of the Project Gutenberg License included \
with this eBook or online at www.gutenberg.net";
    int n = strlen(str);
    strlower_vector(str, n);
    printf("%s",str);
    return 0;
}
