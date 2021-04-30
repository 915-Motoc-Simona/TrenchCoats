//
// Created by Simona on 18.03.2021.
//

#pragma once
#include "../Persistence/AdminRepository.h"
#include "../Persistence/AdminFileRepository.h"

class AdministratorController{
private:
    AdminRepository& ADMRepository;
public:
    explicit AdministratorController(AdminRepository& Repository);
    // add a coat to the list
    void AddCoat(const string& Size, const string& Colour, int Price, int Quantity, const string& Photograph);
    // gets a list of all coats
    vector<TrenchCoat> GetAllTrenchCoats();
    // deletes a coat
    void DeleteCoat(const string &Size, const string &Colour);
    // update the price and quantity of a coat
    void UpdateCoat(const string &Size, const string &Colour, int newPrice, int newQuantity);
    // gets a list of all sold out trenches
    vector<TrenchCoat> GetSoldOutTrenchCoats();
    // returns the length of the array containing the trench coats
    int GetLength();
    vector<TrenchCoat> GetAllTrenchCoatsBySize(const string &Size);
};

