/*
 * Implementation of class Network
 */
#include "network.h"

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
