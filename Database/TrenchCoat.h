//
// Created by Simona on 18.03.2021.
//
#pragma once
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class TrenchCoat{
private:
    string Size;
    string Colour;
    int Price;
    int Quantity;
    string Photograph;
public:
    // sets everything to 0 or empty string
    TrenchCoat();
    // sets a coat with the given params
    TrenchCoat(const string& Size, const string& Colour, int Price, int Quantity, const string& Photograph );
    const string& GetSize() const;
    void SetSize(const string& NewSize);
    const string& GetColour() const;
    void SetColour(const string& NewColour);
    int GetPrice() const;
    void SetPrice(int NewPrice);
    int GetQuantity() const;
    void SetQuantity(int NewQuantity);
    const string& GetPhotograph() const;
    void SetPhotograph(const string& NewPhotograph);
    // checks if the current coats is equal to the one given as param
    bool operator==(const TrenchCoat& T2) const;
    bool operator<(const TrenchCoat& T2) const;
    friend ostream& operator << (ostream& outstream, TrenchCoat const& T);
    friend istream& operator >> (istream& instream, TrenchCoat& T);
};
