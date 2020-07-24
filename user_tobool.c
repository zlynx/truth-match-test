#include <stdint.h>
#include <string.h>

int user_tobool(const char *const StrIn, const unsigned Len) {
  int64_t Word = 0;
  memcpy(&Word, StrIn, Len);
  switch (Word | 32) {
  case '0':
  case 'f':
  case 0x65736c6166:
  case 'n':
  case 0x6f6e:
    return 0;
  case '1':
  case 't':
  case 0x65757274:
  case 'y':
  case 0x736579:
    return 1;
  }
  return -1;
}
