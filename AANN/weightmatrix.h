#pragma once

#include <vector>
#include <stdint.h>

using std::vector;

class WeightMatrix
{
public:
    WeightMatrix();
    WeightMatrix(const unsigned long iSize);

    long unsigned size() {return weights.size();}
    vector< int32_t >& operator[] (const long unsigned i) {return weights[i];}

private:
    vector< vector< int32_t > > weights;
};
