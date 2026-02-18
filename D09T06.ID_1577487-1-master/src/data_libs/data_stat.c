#include "data_stat.h"

double max(double *data, int n) {
  double result = data[0];
  for (int i = 1; i < n; i++) {
    if (data[i] > result) {
      result = data[i];
    }
  }
  return result;
}

double min(double *data, int n) {
  double result = data[0];
  for (int i = 1; i < n; i++) {
    if (data[i] < result) {
      result = data[i];
    }
  }
  return result;
}

double mean(double *data, int n) {
  double result = 0.0;
  for (int i = 0; i < n; i++) {
    result += data[i];
  }
  result /= n;
  return result;
}

double variance(double *data, int n) {
  double m = mean(data, n);
  double result = 0.0;
  for (int i = 0; i < n; i++) {
    double diff = data[i] - m;
    result += diff * diff;
  }
  result /= n;
  return result;
}
