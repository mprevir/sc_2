#include "neuron.h"

Neuron::Neuron()
{
}

Neuron::Neuron(const unsigned long iSize)
    : vals(iSize)
{
}

Neuron::Neuron(const vector<int32_t> iVals)
    : vals( iVals )
{
}

bool
Neuron::isClear()
{
    for (unsigned i=0; i<vals.size(); ++i)
    {
        if (vals[i] != 0)
        {
            return false;
        }
    }
    return true;
}

unsigned long
Neuron::scalarMult(Neuron &iNeuron)
{
    unsigned long sum{ 0 };
    for (unsigned i=0; i<vals.size(); ++i)
    {
        sum += vals[i]*iNeuron[i];
    }
}
