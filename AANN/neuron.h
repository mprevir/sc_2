#pragma once

#include <vector>
#include <stdint.h>

using std::vector;

class Neuron
{
public:
    Neuron();
    Neuron(long unsigned iSize);
    Neuron(vector<double> iVals);

    double& operator[](const long unsigned i) {return vals[i];}
    const double& operator[](const long unsigned i) const {return vals[i];}

    long unsigned size() const {return vals.size();}
    bool empty() const {return vals.empty();}
    bool isClear() const;
    double scalarMult( const Neuron& iNeuron ) const;
    vector< double > getVals() const { return vals; }
private:
    vector< double > vals;
};
