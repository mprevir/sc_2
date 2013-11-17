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
    , W(GUI_BOARD_SIZE)
{
}

Network::Network( WeightMatrix& iW)
    : neuronSize{ iW.size() }
{
    W = iW;
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

void
Network::calculateWeightMatrix()
{
    if (y.empty())
    {
        throw noPatternsStored();
    }
    for (unsigned i=0; i<neuronSize; ++i)
    {

    }
}
