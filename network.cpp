/*
 * Implementation of class Network
 */
#include "network.h"

#define GUI_BOARD_SIZE 10

Network::Network()
    : neuronSize{ GUI_BOARD_SIZE }
{
    y.reset( new vector< neuron >() );
    W.reset( new vector< vector< int32_t > >() );
}

Network::Network(unsigned iNeuronSize)
    : neuronSize{ iNeuronSize }
{
    y.reset( new vector< neuron >() );
    W.reset( new vector< vector< int32_t > >() );
}

Network::Network(WeightMatrixPointer iW)
    : neuronSize{ iW->size() }
{
    y.reset( new vector< neuron >() );
    W = iW;
}
