//
// Created by Simona on 18.03.2021.
//

#include "TrenchCoat.h"
#include <sstream>
#include <cstring>

TrenchCoat::TrenchCoat(){
    this->Price = 0;
    this->Quantity = 0;
    this->Size = "";
    this->Colour = "";
    this->Photograph = "";
}

TrenchCoat::TrenchCoat(const string& newSize, const string& newColour, int newPrice, int newQuantity, const string& newPhotograph ){
    this->Price = newPrice;
    this->Quantity = newQuantity;
    this->Size = newSize;
    this->Colour = newColour;
    this->Photograph = newPhotograph;

}

const string& TrenchCoat::GetSize() const{
    return this->Size;
}

void TrenchCoat::SetSize(const string& NewSize) {
    this->Size = NewSize;
}

const string& TrenchCoat::GetColour() const{
    return this->Colour;
}

void TrenchCoat::SetColour(const string& NewColour) {
    this->Colour = NewColour;
}

int TrenchCoat::GetPrice() const {
    return this->Price;
}

void TrenchCoat::SetPrice(int NewPrice) {
    this->Price = NewPrice;
}

int TrenchCoat::GetQuantity() const {
    return this->Quantity;
}

void TrenchCoat::SetQuantity(int NewQuantity) {
    this->Quantity = NewQuantity;
}

const string& TrenchCoat::GetPhotograph() const{
    return this->Photograph;
}

void TrenchCoat::SetPhotograph(const string &NewPhotograph) {
    this->Photograph = NewPhotograph;
}

bool TrenchCoat::operator==(const TrenchCoat& T2) const {
    if(this->GetSize() == T2.GetSize() && this->GetColour() == T2.GetColour())
        return true;
    else
        return false;
}

ostream& operator<<(std::ostream& outstream, TrenchCoat const& T)
{
    outstream << T.Size << "," << T.Colour << "," << T.Price << "," << T.Quantity << "," << T.Photograph<<endl;
    return outstream;
}

istream& operator>>(istream& instream, TrenchCoat& T)
{
//    instream>>T.Size>>T.Colour>>T.Price>>T.Quantity>>T.Photograph;
//    return instream;

    char separator;
    std::string line;

    std::getline(instream, line, '\n');
    if (line.find(';') != std::string::npos)
        separator = ';';
    else if (line.find(',') != std::string::npos)
        separator = ',';
    else separator = ' ';

    std::stringstream input(line);


    std::string stringPrice, stringQuantity;

    std::getline(input, T.Size, separator);
    std::getline(input, T.Colour, separator);
    std::getline(input, stringPrice, separator);
    std::getline(input, stringQuantity, separator);
    std::getline(input, T.Photograph, separator);

//    cout<<T.Size<<" "<<T.Colour<<" "<<stringPrice<<" "<<stringQuantity<<" "<<T.Photograph<<endl;
    try {
//        cout<<stringPrice<<'+'<<stringQuantity<<endl;
        int price = stoi(stringPrice);
        int quantity = stoi(stringQuantity);


        T.Price = price;
        T.Quantity = quantity;
    }
    catch(...){
    }
    return instream;
}

bool TrenchCoat::operator<(const TrenchCoat &T2) const {
    return this->GetPrice()<T2.GetPrice();
}
