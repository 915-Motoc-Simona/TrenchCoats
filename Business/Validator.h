//
// Created by Simona on 07.04.2021.
//

#ifndef A67_915_MOTOC_SIMONA_VALIDATOR_H
#define A67_915_MOTOC_SIMONA_VALIDATOR_H

#include "../Database/TrenchCoat.h"

class Validator {
public:

    static bool ValidateSize(const string& size){
        if(size=="S" || size=="XS" || size=="M" || size=="L" || size=="XL")
            return true;
        return false;
    }

    static bool ValidateCoat(const TrenchCoat& T)
    {
        if(T.GetPrice() < 0)
            return false;
        if(T.GetQuantity() < 0)
            return false;
        if(T.GetColour().empty())
            return false;
        if(!ValidateSize(T.GetSize()))
            return false;

        return true;
    }
};


#endif //A67_915_MOTOC_SIMONA_VALIDATOR_H
