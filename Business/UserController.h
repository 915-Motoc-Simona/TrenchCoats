//
// Created by Simona on 19.04.2021.
//

#ifndef A67_915_MOTOC_SIMONA_USERCONTROLLER_H
#define A67_915_MOTOC_SIMONA_USERCONTROLLER_H

#pragma once
#include "../Persistence/UserRepository.h"
#include "../Persistence/UserFileRepository.h"

class UserController{
private:
    UserRepository& USERRepository;
    string persistence;

public:
    explicit UserController(UserRepository& Repo, const string& option);
    void AddCoat(const TrenchCoat& T);
    vector<TrenchCoat> GetShoppingBasket();
    int GetTotalSum();
    bool GetShoppingBasketInApplication();
};


#endif //A67_915_MOTOC_SIMONA_USERCONTROLLER_H
