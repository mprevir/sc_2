#pragma once

#include <vector>
#include <stdint.h>

using std::vector;

class Neuron
{
public:
    Neuron();
    Neuron(long unsigned iSize);
    Neuron(vector<int32_t> iVals);

    int32_t& operator[](const long unsigned i) {return vals[i];}
    const int32_t& operator[](const long unsigned i) const {return vals[i];}

    long unsigned size() const {return vals.size();}
    bool empty() const {return vals.empty();}
    bool isClear() const;
    unsigned long scalarMult( const Neuron& iNeuron ) const;
    vector< int32_t > getVals() const { return vals; }
private:
    vector< int32_t > vals;
};
