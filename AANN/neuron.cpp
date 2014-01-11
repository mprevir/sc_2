#include "neuron.h"

Neuron::Neuron()
{
}

Neuron::Neuron(const unsigned long iSize)
    : vals(iSize)
{
}

Neuron::Neuron(const vector<double> iVals)
    : vals( iVals )
{
}

bool
Neuron::isClear() const
{
    for (unsigned i=0; i<vals.size(); ++i)
    {
        if (vals[i] < 1e-10)
        {
            return false;
        }
    }
    return true;
}

double Neuron::scalarMult(const Neuron &iNeuron) const
{
    double sum{ 0.0 };

    for (unsigned i=0; i<vals.size(); ++i)
    {
        sum += vals[i]*iNeuron[i];
    }
    return sum;
}
