/*
 * Implementation of class Network
 */
#include "network.h"
#include "n_exeptions.h"

#define GUI_BOARD_SIZE 10
WeightMatrix operator/( WeightMatrix a, double factor);
//transposed a * b
WeightMatrix operator*(const Neuron& a, const Neuron& b);
WeightMatrix operator+(const WeightMatrix& a, const WeightMatrix& b);
Neuron operator*(const WeightMatrix& a, const Neuron& b);

Network::Network()
    : neuronSize{ GUI_BOARD_SIZE }
    , W(GUI_BOARD_SIZE)
{
}

Network::Network(unsigned iNeuronSize)
    : neuronSize{ iNeuronSize }
    , W(iNeuronSize)
{
}

Network::Network( WeightMatrix& iW)
    : neuronSize{ iW.size() }
{
    W = iW;
}

vector<vector<double> > Network::getWeightMatrix()
{
    return W.getWeights();
}

void
Network::storePattern( Neuron &t)
{
    if (t.size() != neuronSize)
    {
        throw wrongNeuronSize();
    }
#if 0
    for (unsigned i=0; i<t.size(); ++i)
    {
        if (t[i] == -1)
            t[i] = 0;
    }
#endif
    y.push_back( t );
}

Neuron
Network::recallPattern(Neuron &s)
{
    Neuron resNeuron;
    for (unsigned i=0; i<y.size(); ++i)
    {
        if ( y[i].scalarMult( s ) == 0 )
        {
            return y[i];
        }
    }
    for (unsigned i=0; i<s.size(); ++i)
    {
        if (s[i] == -1)
            s[i] = 0;
    }
    resNeuron = W * s;
    return activateFunction(resNeuron);
}

void
Network::calculateWeightMatrix()
{
    W = WeightMatrix(neuronSize);
    if (y.empty())
    {
        throw noPatternsStored();
    }

    for (unsigned i=0; i<y.size(); ++i)
    {
        WeightMatrix normalizedProduct = y[i]*y[i]/10;
        W = W + normalizedProduct;
    }
}

Neuron
Network::activateFunction( Neuron &iNeuron)
{
    Neuron resN(neuronSize);
    int magic = y.size()+1;// < 3 ? y.size() : 10;
    for (unsigned long i=0; i<neuronSize; ++i)
    {
        if ( iNeuron[i]>(magic/10) )
            resN[i] = 1;
        else
            resN[i] = -1;
        /*
        if (iNeuron[i]>0)
        {
            resN[i] = 1;
        } else if (iNeuron[i]<0)
        {
            resN[i] = -1;
        } else
        {
            resN[i] = 0;
        }*/
    }
    return resN;
}

WeightMatrix
operator*( const Neuron& a, const Neuron& b)
{
    if (a.size() != b.size())
    {
        throw wrongNeuronSize();
    }
    const long unsigned nSize = a.size();
    WeightMatrix resW( nSize );
    for( long unsigned i=0; i<nSize; ++i)
    {
        for( long unsigned j=0; j<nSize; ++j)
        {
            resW[i][j] = a[i]*b[j];
        }
    }
    return resW;
}

WeightMatrix
operator+( const WeightMatrix& a, const WeightMatrix& b )
{
    const long unsigned nSize = a.size();
    WeightMatrix resW( nSize );
    for( long unsigned i=0; i<nSize; ++i )
    {
        for( long unsigned j=0; j<nSize; ++j )
        {
            resW[i][j] = a[i][j] + b[i][j];
        }
    }
    return resW;
}

Neuron
operator*( const WeightMatrix& a, const Neuron& b )
{
    const long unsigned nSize = b.size();
    Neuron resN(nSize);
    for( long unsigned i=0; i<nSize; ++i)
    {
        for( long unsigned j=0; j<nSize; ++j)
        {
            resN[i] += a[i][j] * b[j];
        }
    }
    return resN;
}

WeightMatrix
operator/( WeightMatrix a, double factor)
{
    for (int i = 0; i< a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            a[i][j] /= factor;
        }
    }

    return a;
}
