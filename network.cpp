/*
 * Implementation of class Network
 */
#include "network.h"
#include "n_exeptions.h"

#define GUI_BOARD_SIZE 10

Network::Network()
    : neuronSize{ GUI_BOARD_SIZE }
{
}

Network::Network(unsigned iNeuronSize)
    : neuronSize{ iNeuronSize }
{
}

Network::Network(const WeightMatrix& iW)
    : neuronSize{ iW.size() }
{
    W = iW;
}

void
Network::storePattern(const neuron &t)
{
    if (t.size() != neuronSize)
    {
        throw wrongNeuronSize();
    }
    y.push_back( t );
}
