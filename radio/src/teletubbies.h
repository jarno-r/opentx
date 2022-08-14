#ifndef TELETUBBIES_H
#define TELETUBBIES_H

#include "ff.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int flags1,flags2,flags3,flags4;
    int flags5,flags6;
    char whatever[21];
} Teletubbies;

extern Teletubbies teletubbies;

#ifdef __cplusplus
}
#endif


#endif //TELETUBBIES_H
