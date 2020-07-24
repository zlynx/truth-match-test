#include <stdint.h>
#include <string.h>

int user1_tobool(const char *Str) {
  if (!memcmp(Str, "true", 4) || !memcmp(Str, "1", 1)) {
    return 1;
  } else if (!memcmp(Str, "false", 5) || !memcmp(Str, "0", 1)) {
    return 0;
  }
  return -1;
}

int user2_tobool(const char *const StrIn, unsigned Len) {
  int64_t Word = 0;
  // There was a bug here if Len was bigger than Word
  Len = (Len > sizeof Word) ? sizeof Word : Len;
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
