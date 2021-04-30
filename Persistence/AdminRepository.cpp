//
// Created by Simona on 18.03.2021.
//

#include "AdminRepository.h"

#include <utility>


AdminRepository::AdminRepository() = default;

void AdminRepository::AddCoat(const TrenchCoat& T) {
    if(this->CheckIfCoatExists(T))
        throw(MyException("\nTrench coat already exists\n"));
    else
    {
        this->RepoCoats.push_back(T);
    }

}

void AdminRepository::DeleteCoat(TrenchCoat& T){
    int index = this->GetIndex(T);
    if(index == -1)
        throw MyException("\nTrench coat doesnt exist\n");
    else if(this->RepoCoats.at(index).GetQuantity()!=0)
        throw MyException("\nThis is not sold out!\n");
    else
        this->RepoCoats.erase(this->RepoCoats.begin() + index);
}

void AdminRepository::UpdateCoat(const TrenchCoat& oldT, TrenchCoat newT) {
    int index = this->GetIndex(oldT);
    if(index == -1)
        throw MyException("\nTrench coat doesnt exist\n");
    else
        this->RepoCoats.at(index)=std::move(newT);
}


bool AdminRepository::CheckIfCoatExists(const TrenchCoat& T){
    for(auto & RepoCoat : this->RepoCoats)
        if(RepoCoat==T)
            return true;
    return false;
}

TrenchCoat AdminRepository::GetCoatByIndex(int Index){
    if(Index > this->RepoCoats.size() || Index < 0)
        throw MyException("\nTrench Coat doesnt exist\n");

    return this->RepoCoats.at(Index);
}

int AdminRepository::GetIndex(const TrenchCoat& T){
    auto itr = find(RepoCoats.begin(), RepoCoats.end(), T);
    if (itr != RepoCoats.cend())
        return distance(RepoCoats.begin(), itr);
    else
        return -1;
}

int AdminRepository::GetSize(){
    return this->RepoCoats.size();
}

std::vector<TrenchCoat> AdminRepository::GetRepositoryData() {
    std::vector<TrenchCoat> newArray;
    newArray.reserve(this->GetSize());
    for(auto & RepoCoat : this->RepoCoats)
        newArray.push_back(RepoCoat);
    return newArray;
}
