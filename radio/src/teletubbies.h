#ifndef TELETUBBIES_H
#define TELETUBBIES_H

#include "ff.h"

#ifdef __cplusplus
extern "C" {
#endif

// Debugging aids. These live in view_about.cpp

typedef struct {
    int flags1,flags2,flags3,flags4;
    char whatever[21];
} Teletubbies;

typedef struct {
    int flags1,flags2;
    const char * filename;
    int linenum;
    int trace_active;
} PersistentTubbies;

extern Teletubbies teletubbies;
extern volatile PersistentTubbies persistentTubbies;
extern PersistentTubbies insistentTubbies;

#define TUBBY_TAGFILE static const char teletubby_filename[] = __FILE__;
#define TUBBY_TRACE do { if (persistentTubbies.trace_active) { persistentTubbies.filename = teletubby_filename; persistentTubbies.linenum = __LINE__; } } while(0)
//#define TUBBY_TRACE
//#define TUBBY_TRACE do { if (insistentTubbies.trace_active) { persistentTubbies.filename = 0; insistentTubbies.linenum = __LINE__; } } while(0)

void tubbyInit();

void tubbyFileBuf(char *outs);

#ifdef __cplusplus
}
#endif

#endif //TELETUBBIES_H
