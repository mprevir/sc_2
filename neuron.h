#pragma once

#include <vector>
#include <stdint.h>

using std::vector;

class Neuron
{
public:
    Neuron();
    Neuron(const long unsigned iSize);

    int32_t& operator[](const long unsigned i) {return vals[i];}
    long unsigned size() {return vals.size();}
    long unsigned empty() {return vals.empty();}
private:
    vector< int32_t > vals;
};
