#ifndef TELETUBBY_H
#define TELETUBBY_H

#include "ff.h"

struct Teletubby {
    int writelatch;
    int tubby;

    uint8_t box[100];
    int len;

    int inversion;
};

extern Teletubby teletubby;

#endif //TELETUBBY_H
