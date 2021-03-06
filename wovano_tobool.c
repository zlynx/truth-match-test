#include "functions.h"
#include <string.h>

int wovano1_tobool(const char *str) {
  if ((str[0] & 0xFE) == 48) { // ch == '0' or '1'
    if (str[1] == '\0') {
      return str[0] - 48;
    }
  } else if (str[0] == 't') {
    if (str[1] == 'r' && str[2] == 'u' && str[3] == 'e' && str[4] == '\0') {
      return 1;
    }
  } else if (str[0] == 'f') {
    if (str[1] == 'a' && str[2] == 'l' && str[3] == 's' && str[4] == 'e' &&
        str[5] == '\0') {
      return 0;
    }
  }
  return -1;
}

int wovano2_tobool(const char *str) {
  if ((str[0] & 0xFE) == 48) { // ch == '0' or '1'
    if (str[1] == '\0') {
      return str[0] - 48;
    }
  } else if ((str[0] | 32) == 't') {
    if (str[1] == '\0') {
      return 1;
    }
    if (str[1] == 'r' && str[2] == 'u' && str[3] == 'e' && str[4] == '\0') {
      return 1;
    }
  } else if ((str[0] | 32) == 'f') {
    if (str[1] == '\0') {
      return 0;
    }
    if (str[1] == 'a' && str[2] == 'l' && str[3] == 's' && str[4] == 'e' &&
        str[5] == '\0') {
      return 0;
    }
  } else if ((str[0] | 32) == 'y') {
    if (str[1] == '\0') {
      return 1;
    }
    if (str[1] == 'e' && str[2] == 's' && str[3] == '\0') {
      return 1;
    }
  } else if ((str[0] | 32) == 'n') {
    if (str[1] == '\0') {
      return 0;
    }
    if (str[1] == 'o' && str[2] == '\0') {
      return 0;
    }
  }
  return -1;
}
