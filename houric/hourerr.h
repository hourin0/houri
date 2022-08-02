#ifndef ERRNO_H
#define ERRNO_H

#ifndef ERRNO_DEC_H
#include "hourerrdec.h"
#endif

UI32 errno;

U0 UpdateErrno(UI32 value);

U0 UpdateErrno(UI32 value) {
	errno=value;
}

#endif
