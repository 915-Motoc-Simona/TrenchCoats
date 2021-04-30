//
// Created by Simona on 19.04.2021.
//

#include "UserRepository.h"

#include <utility>

UserRepository::UserRepository() {
    this->Total_Sum = 0;
}

void UserRepository::UserAddCoat(const TrenchCoat& T) {
    if(T.GetQuantity() == 0)
        throw(MyException("\nThis trench coat is sold out :(\n"));
    else{
        this->UserCoats.push_back(T);
        auto itr = find(UserCoats.begin(), UserCoats.end(), T);
        if (itr != UserCoats.cend())
        {
            int Index = distance(UserCoats.begin(), itr);
            this->Total_Sum += this->UserCoats.at(Index).GetPrice();
        }
    }
}

int UserRepository::GetIndex(const TrenchCoat& T){
    auto itr = find(UserCoats.begin(), UserCoats.end(), T);
    if (itr != UserCoats.cend())
        return distance(UserCoats.begin(), itr);
    else
        return -1;
}

int UserRepository::GetSize(){
    return this->UserCoats.size();
}

int UserRepository::GetTotalSum(){
    int sum=0;
    for(auto & RepoCoat : this->UserCoats)
        sum+=RepoCoat.GetPrice();
    return sum;
}

TrenchCoat UserRepository::GetCoatByIndex(int Index){
    return this->UserCoats.at(Index);
}

std::vector<TrenchCoat> UserRepository::GetData() {
    std::vector<TrenchCoat> newArray;
    newArray.reserve(this->GetSize());
    for(auto & RepoCoat : this->UserCoats)
        newArray.push_back(RepoCoat);
    return newArray;
}

string UserRepository::getFilename() {
    return "";
}