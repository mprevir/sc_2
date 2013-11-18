#include "neuron.h"

Neuron::Neuron()
{
}

Neuron::Neuron(const unsigned long iSize)
    : vals(iSize)
{
}

Neuron::Neuron(const vector<int32_t>&& iVals)
    : vals( iVals )
{
}
