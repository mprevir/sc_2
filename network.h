/*
 * Interface of class Network
 */
#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <stdint.h>
#include <memory>

//Feedforward autoassociative artificial neural network
class Network
{
using std::vector;
using neuron = vector< int32_t >;

public:
    Network();
    Network( unsigned iNeuronSize );

    auto getWeightMatrix();

    void storePattern( const neuron& t );
    //calculate weight matrix W using Hebb rule
    void calculateWeightMatrix();
    neuron recallPattern( const neuron& s );
private:
    const unsigned neuronSize;

    std::unique_ptr< vector< neuron > > y; //input/output units
    std::unique_ptr< vector< vector< int32_t > > > W; //Weight matrix
};

#endif // NETWORK_H
