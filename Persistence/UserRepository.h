//
// Created by Simona on 19.04.2021.
//

#ifndef A67_915_MOTOC_SIMONA_USERREPOSITORY_H
#define A67_915_MOTOC_SIMONA_USERREPOSITORY_H

#pragma once
#include "dynamicVector.h"
#include "../Database/TrenchCoat.h"
#include "MyException.h"
#include <vector>
#include <algorithm>

class UserRepository{
protected:
    vector<TrenchCoat> UserCoats;
    int Total_Sum;
public:
    UserRepository();
    virtual void UserAddCoat(const TrenchCoat& T);
    virtual int GetTotalSum();
    virtual int GetIndex(const TrenchCoat& T);
    virtual int GetSize();
    virtual TrenchCoat GetCoatByIndex(int Index);
    virtual std::vector<TrenchCoat> GetData();
    virtual string getFilename();
};


#endif //A67_915_MOTOC_SIMONA_USERREPOSITORY_H
