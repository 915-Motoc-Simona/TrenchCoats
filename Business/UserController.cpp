//
// Created by Simona on 19.04.2021.
//

#include "UserController.h"

UserController::UserController(UserRepository &Repo, const string& option): USERRepository{Repo}, persistence{option}{}


void UserController::AddCoat(const TrenchCoat& T) {
    try {
        this->USERRepository.UserAddCoat(T);
    }
    catch (MyException &e)
    {
        throw e;
    }
}

vector<TrenchCoat> UserController::GetShoppingBasket() {
    return this->USERRepository.GetData();
}

int UserController::GetTotalSum() {
    return this->USERRepository.GetTotalSum();
}

bool UserController::GetShoppingBasketInApplication() {
    if (persistence == "1" || persistence == "2") {
        std::string filename = USERRepository.getFilename();
        std::string systemCommand = "start " + filename;
        system(systemCommand.c_str());
        return true;
    } else {
        return false;
    }
}
