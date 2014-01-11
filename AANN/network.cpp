/*
 * Implementation of class Network
 */
#include "network.h"
#include "n_exeptions.h"

#define GUI_BOARD_SIZE 10

Network::Network()
    : neuronSize{ GUI_BOARD_SIZE }
    , W(GUI_BOARD_SIZE)
{
}

Network::Network(unsigned iNeuronSize)
    : neuronSize{ iNeuronSize }
    , W(iNeuronSize)
{
}

Network::Network( WeightMatrix& iW)
    : neuronSize{ iW.size() }
{
    W = iW;
}

vector<vector<int32_t> > Network::getWeightMatrix()
{
    return W.getWeights();
}

void
Network::storePattern( Neuron &t)
{
    if (t.size() != neuronSize)
    {
        throw wrongNeuronSize();
    }
    y.push_back( t );
}

Neuron
Network::recallPattern(Neuron &s)
{
    Neuron resNeuron;
    for (unsigned i=0; i<y.size(); ++i)
    {
        if ( y[i].scalarMult( s ) == 0 )
        {
            return y[i];
        }
    }
    resNeuron = W * s;
    return activateFunction(resNeuron);
}

void
Network::calculateWeightMatrix()
{
    W = WeightMatrix(neuronSize);
    if (y.empty())
    {
        throw noPatternsStored();
    }
    for (unsigned i=0; i<y.size(); ++i)
    {
        W = W + y[i]*y[i];
    }
}

Neuron
Network::activateFunction( Neuron &iNeuron)
{
    Neuron resN(neuronSize);
    for (unsigned long i=0; i<neuronSize; ++i)
    {
        if (iNeuron[i]>0)
        {
            resN[i] = 1;
        } else if (iNeuron[i]<0)
        {
            resN[i] = -1;
        } else
        {
            resN[i] = 0;
        }
    }
    return resN;
}

WeightMatrix
operator*( Neuron& a, Neuron& b)
{
    if (a.size() != b.size())
    {
        throw wrongNeuronSize();
    }
    const long unsigned nSize = a.size();
    WeightMatrix resW( nSize );
    for( long unsigned i=0; i<nSize; ++i)
    {
        for( long unsigned j=0; j<nSize; ++j)
        {
            resW[i][j] = a[i]*b[j];
        }
    }
    return resW;
}

WeightMatrix
operator+( WeightMatrix& a, WeightMatrix&& b )
{
    const long unsigned nSize = a.size();
    WeightMatrix resW( nSize );
    for( long unsigned i=0; i<nSize; ++i )
    {
        for( long unsigned j=0; j<nSize; ++j )
        {
            resW[i][j] = a[i][j] + b[i][j];
        }
    }
    return resW;
}

Neuron
operator*( WeightMatrix& a, Neuron& b )
{
    const long unsigned nSize = b.size();
    Neuron resN(nSize);
    for( long unsigned i=0; i<nSize; ++i)
    {
        for( long unsigned j=0; j<nSize; ++j)
        {
            resN[i] += a[i][j] * b[j];
        }
    }
    return resN;
}