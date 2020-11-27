#include "beep.h"

#include <stdlib.h>

int main(int argc, char *argv[]) {
  for (int i = 0; i < (argc - 1) / 2; i++) {
    beep(atoi(argv[i * 2 + 1]), atoi(argv[i * 2 + 2]));
  }
  return 0;
}
