#pragma once

#include <vector>
#include <stdint.h>

using std::vector;

class WeightMatrix
{
public:
    WeightMatrix();
    WeightMatrix(const unsigned long iSize);

    auto size() {return weights.size();}
    auto operator[] (const long unsigned i) {return weights[i];}

private:
    vector< vector< int32_t > > weights;
};
