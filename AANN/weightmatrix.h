#pragma once

#include <vector>
#include <stdint.h>

using std::vector;

class WeightMatrix
{
public:
    WeightMatrix();
    WeightMatrix(const unsigned long iSize);

    long unsigned size() const {return weights.size();}
    vector< int32_t >& operator[] (const long unsigned i) {return weights[i];}
    const vector< int32_t >& operator[] (const long unsigned i) const {return weights[i];}

    vector< vector< int32_t > > getWeights() const {return weights;}

private:
    vector< vector< int32_t > > weights;
};
