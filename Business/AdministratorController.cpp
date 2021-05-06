//
// Created by Simona on 18.03.2021.
//
#include<iostream>
#include "AdministratorController.h"
#include "Validator.h"

AdministratorController::AdministratorController(AdminRepository &Repository): ADMRepository{Repository}{

}

void AdministratorController::AddCoat(const string &Size, const string &Colour, int Price, int Quantity,
                                              const string &Photograph) {
    TrenchCoat Coat(Size, Colour, Price, Quantity, Photograph);
    bool validEvent = Validator::ValidateCoat(Coat);
    if(!validEvent)
        throw MyException("The coat is not valid!\n");
    else
        try {
            this->ADMRepository.AddCoat(Coat);
        }
         catch (MyException &e)
         {
             throw e;
         }
}

vector<TrenchCoat> AdministratorController::GetAllTrenchCoats() {
    return this->ADMRepository.GetRepositoryData();
}

vector<TrenchCoat> AdministratorController::GetSoldOutTrenchCoats() {
    std::vector<TrenchCoat> newArray;
    newArray.reserve(this->GetLength());
    for(auto & Coat : this->ADMRepository.GetRepositoryData())
        if(Coat.GetQuantity() == 0)
            newArray.push_back(Coat);
    return newArray;
}

void AdministratorController::DeleteCoat(const string &Size, const string &Colour){
    TrenchCoat Coat(Size, Colour, 0, 0, "");
    try {
        this->ADMRepository.DeleteCoat(Coat);
    }
    catch (MyException &e) {
        throw e;
    }
}


void AdministratorController::UpdateCoat(const string &Size, const string &Colour, int newPrice, int newQuantity) {
    TrenchCoat OldCoat(Size, Colour, 0, 0, "");


    int OldCoatIndex = this->ADMRepository.GetIndex(OldCoat);
    try {
        OldCoat = this->ADMRepository.GetCoatByIndex(OldCoatIndex);
    }
    catch (MyException &e)
    {
        throw e;
    }

    TrenchCoat NewCoat(Size, Colour, newPrice, newQuantity, OldCoat.GetPhotograph());
    bool validEvent = Validator::ValidateCoat(NewCoat);
    if(!validEvent)
        throw MyException("The coat is not valid!\n");
    this->ADMRepository.UpdateCoat(OldCoat, NewCoat);

}

int AdministratorController::GetLength(){
    return this->ADMRepository.GetSize();
}

vector<TrenchCoat> AdministratorController::GetAllTrenchCoatsBySize(const string &Size) {
    bool validEvent = Validator::ValidateSize(Size);
    if(!validEvent)
        throw MyException("This size is not valid!\n");
    std::vector<TrenchCoat> newArray;
    newArray.reserve(this->GetLength());
    for(auto & Coat : this->ADMRepository.GetRepositoryData())
        if(Coat.GetSize() == Size)
            newArray.push_back(Coat);
    return newArray;
}
