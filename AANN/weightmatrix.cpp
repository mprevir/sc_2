#include "weightmatrix.h"

WeightMatrix::WeightMatrix()
{
}

WeightMatrix::WeightMatrix(const unsigned long iSize)
    : weights(iSize, vector<double>(iSize))
{
}
