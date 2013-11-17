#ifndef N_EXEPTIONS_H
#define N_EXEPTIONS_H

#include <exception>

class wrongNeuronSize : public std::exception
{
    const char*
    what() {return "Input neuron's size doesn't match network's neuron size";}
};

class noPatternsStored : public std::exception
{
    const char*
    what() {return "Vector of stored patterns is empty";}
};

#endif // N_EXEPTIONS_H
