#pragma once

#include <vector>
#include <stdint.h>

using std::vector;

class Neuron
{
public:
    Neuron();
    Neuron(const long unsigned iSize);
    Neuron(const vector<int32_t> iVals);

    int32_t& operator[](const long unsigned i) {return vals[i];}
    long unsigned size() {return vals.size();}
    bool empty() {return vals.empty();}
    bool isClear();
    unsigned long scalarMult( Neuron& iNeuron );
    vector< int32_t > getVals(){ return vals; }
private:
    vector< int32_t > vals;
};
