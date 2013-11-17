/*
 * Interface of class Network
 */
#pragma once

#include <vector>
#include <stdint.h>
#include "weightmatrix.h"
#include "neuron.h"

using std::vector;

//Feedforward autoassociative artificial neural network
class Network
{
public:
    Network();
    Network( unsigned iNeuronSize );
    Network( WeightMatrix& iW );

    auto getWeightMatrix();

    void storePattern(Neuron &t );
    //calculate weight matrix W using Hebb rule
    void calculateWeightMatrix();
    Neuron recallPattern( const Neuron& s );
private:
    const long unsigned neuronSize;

    vector< Neuron > y; //input/output units
    WeightMatrix W; //Weight matrix

    int32_t activateFunction( const Neuron& iNeuron); //signum (for Hebb rule)
};
//transposed a * b
WeightMatrix operator*(Neuron& a, Neuron& b);
WeightMatrix operator+(const WeightMatrix& a, const WeightMatrix& b);
Neuron operator*(const WeightMatrix& a, const Neuron& b);
