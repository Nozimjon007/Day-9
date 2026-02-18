#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main(void) {
  int n = 0;
  double *data = NULL;
  int status = scanf("%d", &n);

  if (status == 1 && n > 0) {
    data = (double *)malloc(n * sizeof(double));
    if (data != NULL) {
      input(data, n);
      if (normalization(data, n)) {
        output(data, n);
      } else {
        printf("ERROR");
      }
      free(data);
    } else {
      printf("ERROR");
    }
  } else {
    printf("ERROR");
  }

  return 0;
}
