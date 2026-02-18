#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main(void) {
  int n = 0;
  double *data = NULL;
  int status = scanf("%d", &n);

  if (status == 1 && n > 0) {
    data = (double *)malloc(n * sizeof(double));
    if (data != NULL) {
      input(data, n);
      if (make_decision(data, n)) {
        printf("YES");
      } else {
        printf("NO");
      }
      free(data);
    } else {
      printf("NO");
    }
  } else {
    printf("NO");
  }

  return 0;
}
