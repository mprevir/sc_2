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
    vector< double >& operator[] (const long unsigned i) {return weights[i];}
    const vector< double >& operator[] (const long unsigned i) const {return weights[i];}

    vector< vector< double > > getWeights() const {return weights;}

private:
    vector< vector< double > > weights;
};
