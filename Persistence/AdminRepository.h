//
// Created by Simona on 18.03.2021.
//

#pragma once
#include "dynamicVector.h"
#include "../Database/TrenchCoat.h"
#include "MyException.h"
#include <vector>
#include <algorithm>

using namespace std;

class AdminRepository{
protected:
    vector<TrenchCoat> RepoCoats;
public:
    // constructor;
    AdminRepository();
    // adds a coat
    virtual void AddCoat(const TrenchCoat& T);
    // deletes a coat
    virtual void DeleteCoat(TrenchCoat& T);
    // updates a coat
    // old coat becomes new coat
    virtual void UpdateCoat(const TrenchCoat& oldT, TrenchCoat newT);
    // return the coat with the given index
    virtual TrenchCoat GetCoatByIndex(int Index);
    // returns true if the given coat exists in the array
    //         false otherwise
    virtual bool CheckIfCoatExists(const TrenchCoat& T);
    // returns the index of a given coat
    virtual int GetIndex(const TrenchCoat& T);
    // returns the size of the array that stores the trench coats
    virtual int GetSize();

    virtual std::vector<TrenchCoat> GetRepositoryData();

};

