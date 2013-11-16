/*
 * Interface of class Network
 */
#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <stdint.h>
#include <memory>

using std::vector;

//Feedforward autoassociative artificial neural network
class Network
{
using neuron = vector< int32_t >;
using WeightMatrixPointer = std::shared_ptr< vector< vector< int32_t > > >;

public:
    Network();
    Network( unsigned iNeuronSize );
    Network( WeightMatrixPointer iW );

    auto getWeightMatrix();

    void storePattern( const neuron& t );
    //calculate weight matrix W using Hebb rule
    void calculateWeightMatrix();
    neuron recallPattern( const neuron& s );
private:
    const long unsigned neuronSize;

    std::unique_ptr< vector< neuron > > y; //input/output units
    WeightMatrixPointer W; //Weight matrix
};

#endif // NETWORK_H
