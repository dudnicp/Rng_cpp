#ifndef STATISTICALTESTS_H
#define STATISTICALTESTS_H

#define ALPHA 0.05

#include <vector>



void chiSquaredTest(const double* obtained, const double *expected, const int n, const double alpha);
void stdNormalTest(const double z, const double alpha);

void uniformFrequencyKSTest(const double* data, const int n);
void uniformFrequencyChiSquaredTest(const double* data, const int n);
void normalFrequencyChiSquaredTest(const double* data, const int n);

void autocorrelationTest(const double* data, const int n);

void runsNumberTest(const double* data, const int n);
void aboveAndBelowMeanTest(const double* data, const int n);
void runsLengthTest(const double* data, const int n);
void runsAboveAndBelowMeanTest(const double* data, const int n);

#endif
