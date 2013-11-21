#include <iostream>
#include <memory>

#include "network.h"

int main()
{
    std::unique_ptr< Network > assMemory; //lolname
    assMemory.reset( new Network(6) );

    Neuron inputNeuron1(std::vector<int32_t>{1, 1, -1, 1, 1, -1});
    Neuron inputNeuron2(std::vector<int32_t>{-1, 1, 1, 1, 1, 1});
    Neuron inputNeuron3(std::vector<int32_t>{1, -1, 1, 1, 1, -1});
    Neuron inputNeuron4(std::vector<int32_t>{-1, 1, 1, -1, -1, -1});
    assMemory->storePattern(inputNeuron1);
    assMemory->storePattern(inputNeuron2);
    assMemory->storePattern(inputNeuron3);
    assMemory->storePattern(inputNeuron4);
    assMemory->calculateWeightMatrix();

    Neuron testNeuron(std::vector<int32_t>{1, 1, 1, 1, 1, 1});
    Neuron resNeuron = assMemory->recallPattern(testNeuron);

    for (unsigned long i=0; i<resNeuron.size(); ++i)
    {
        std::cout<<" "<<resNeuron[i]<<" ";
    }
    return 0;
}
