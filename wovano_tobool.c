#include "functions.h"
#include <string.h>

int wovano_tobool(const char *Str) {
  if (!memcmp(Str, "true", 4) || !memcmp(Str, "1", 1)) {
    return 1;
  } else if (!memcmp(Str, "false", 5) || !memcmp(Str, "0", 1)) {
    return 0;
  }
  return -1;
}
