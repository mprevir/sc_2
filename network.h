/*
 * Interface of class Network
 */
#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <stdint.h>

using std::vector;

//Feedforward autoassociative artificial neural network
class Network
{
using neuron = vector< int32_t >;
using WeightMatrix = vector< vector< int32_t > >;

public:
    Network();
    Network( unsigned iNeuronSize );
    Network( const WeightMatrix& iW );

    auto getWeightMatrix();

    void storePattern( const neuron& t );
    //calculate weight matrix W using Hebb rule
    void calculateWeightMatrix();
    neuron recallPattern( const neuron& s );
private:
    const long unsigned neuronSize;

    vector< neuron > y; //input/output units
    WeightMatrix W; //Weight matrix

    int32_t activateFunction( const neuron& iNeuron); //signum (for Hebb rule)
};

#endif // NETWORK_H
