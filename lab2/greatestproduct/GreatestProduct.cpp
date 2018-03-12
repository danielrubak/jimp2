#include "GreatestProduct.h"

int GreatestProduct(const std::vector<int> &numbers, int k) {
    std::vector<int> positiveIntNumbers;
    std::vector<int> negativeIntNumbers;
    for ( int v : numbers ) {
        if ( v >= 0 ) {
            positiveIntNumbers.push_back(v);
        } else {
            negativeIntNumbers.push_back(v);
        }
    }
    sort( positiveIntNumbers.begin(), positiveIntNumbers.end() );
    sort( negativeIntNumbers.begin(), negativeIntNumbers.end() );

    int result;
    if ( positiveIntNumbers.size() > 0 && negativeIntNumbers.size() == 0 ) {
        if (positiveIntNumbers.size() == 1 )
            result = positiveIntNumbers[0];
        else
            result = std::accumulate(end(positiveIntNumbers)-k, end(positiveIntNumbers), 1, std::multiplies<int>());
    } else if ( positiveIntNumbers.size() == 0 && negativeIntNumbers.size() > 0 ) {
        if ( negativeIntNumbers.size() == 1 ) {
            result = negativeIntNumbers[0];
        } else if ( negativeIntNumbers.size() != 1 && k%2 == 0 ) {
            result = std::accumulate(begin(negativeIntNumbers), begin(negativeIntNumbers) + k, 1, std::multiplies<int>());
        } else if ( negativeIntNumbers.size() != 1 && k%2 != 0 )
            result = std::accumulate(end(negativeIntNumbers)-k, end(negativeIntNumbers), 1, std::multiplies<int>());
    } else {
        int resultPositive = std::accumulate(end(positiveIntNumbers)-k, end(positiveIntNumbers), 1, std::multiplies<int>());
        int resultNegative = 0;
        if ( k%2 == 0 )
            resultNegative = std::accumulate(begin(negativeIntNumbers), begin(negativeIntNumbers)+k, 1, std::multiplies<int>());
        else
            resultNegative = std::accumulate(begin(negativeIntNumbers), begin(negativeIntNumbers)+k-1, 1, std::multiplies<int>()) * positiveIntNumbers.back();
        result = (resultNegative>resultPositive) ? resultNegative : resultPositive;
    }
    return result;
}
