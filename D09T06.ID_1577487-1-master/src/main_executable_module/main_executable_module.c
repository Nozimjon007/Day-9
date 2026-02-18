#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main(void) {
  int n = 0;
  double *data = NULL;
  int status = scanf("%d", &n);

  if (status == 1 && n > 0) {
    data = (double *)malloc(n * sizeof(double));
  }

  if (data == NULL) {
    printf("n/a");
  } else {
    int normalized = 0;

    printf("LOAD DATA...\n");
    input(data, n);

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalized = normalization(data, n);
    if (normalized) {
      output(data, n);
    } else {
      printf("ERROR");
    }

    if (normalized) {
      printf("\nSORTED NORMALIZED DATA:\n\t");
      sort(data, n);
      output(data, n);

      printf("\nFINAL DECISION:\n\t");
      if (make_decision(data, n)) {
        printf("YES");
      } else {
        printf("NO");
      }
    }

    free(data);
  }

  return 0;
}
