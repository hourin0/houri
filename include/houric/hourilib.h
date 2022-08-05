#ifndef STDLIB_H
#define STDLIB_H

U0 memcpy(U0* dest,const U0* src,UI32 len);
U0 memset(U0* dest,I32 val,UI32 len);

UI32 rand(U0);
UI0 srand(UI32 seed);

#endif
