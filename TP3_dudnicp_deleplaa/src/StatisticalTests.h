#ifndef STATISTICALTESTS_H
#define STATISTICALTESTS_H

#include <vector>



void uniformFrequencyKSTest(const double* data, const size_t n);
void uniformFrequencyChiSquaredTest(const double* data, const size_t n);
void normalFrequencyChiSquaredTest(const double* data, const size_t n);
void chiSquaredTest(const double* obtained, const double *expected, const size_t n);
void autocorrelationTest(const double* data, const size_t n);
void runsTest(const double* data, const size_t n);

struct Run
{
    bool rising;
    size_t length;
};


std::vector<Run> computeRuns(const double* data, size_t n);
void aboveAndBelowMean(const double* data, size_t n, int &above, int &below);

#endif
