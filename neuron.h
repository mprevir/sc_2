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
    auto size() {return vals.size();}
    bool empty() {return vals.empty();}
private:
    vector< int32_t > vals;
};
