#include <stdio.h>

#include "functions.h"

int zlynx_tobool(const char *s) {
  char lower[16] = {(s[0] | 0x20), (s[1] | 0x20), (s[2] | 0x20), (s[3] | 0x20),
                    (s[4] | 0x20)};
  int match_1 = ((lower[0] == ('1' | 0x20)) & (lower[1] == ('\0' | 0x20)));
  int match_true = ((lower[0] == 't') & (lower[1] == 'r') & (lower[2] == 'u') &
                    (lower[3] == 'e') & (lower[4] == ('\0' | 0x20)));
  return match_1 | match_true;
}
