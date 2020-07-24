#include "functions.h"
#include <stdint.h>
#include <string.h>

#define Ttrue                                                                  \
  (((uint_least64_t)'t') << 32 | ((uint_least64_t)'r') << 24 |                 \
   ((uint_least64_t)'u') << 16 | ((uint_least64_t)'e') << 8 | 0)
#define T1 (((uint_least64_t)'1') << 8 | 0)
#define Tfalse                                                                 \
  (((uint_least64_t)'f') << 40 | ((uint_least64_t)'a') << 32 |                 \
   ((uint_least64_t)'l') << 24 | ((uint_least64_t)'s') << 16 |                 \
   ((uint_least64_t)'e') << 8 | 0)
#define T0 (((uint_least64_t)'0') << 8 | 0)

int chux1_tobool(const char *Str) {
  uint_least64_t sum = 0;
  do {
    sum <<= 8;
    sum |= *(unsigned char *)Str;
  } while (*Str++ && (sum & 0xFF0000000000) == 0); // loop to \0 or 6 characters

  if (sum == T1 || sum == Ttrue)
    return 1;
  if (sum == T0 || sum == Tfalse)
    return 0;
  return -1;
}

int chux2_tobool(const char *s) {
  const char *tf[4] = {"0", "1", "false", "true"};
  unsigned hash = *s;
  hash = (hash & 4) ? ((hash >> 4) & 3) : hash & 1;
  if (strcmp(tf[hash], s) == 0)
    return hash & 1;
  return 0;
}
