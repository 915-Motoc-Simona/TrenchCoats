//
// Created by Simona on 13.04.2021.
//

#include "UserFileRepository.h"
UserFileRepository::UserFileRepository(const string& File){
    this->FileName = File;

}

vector<TrenchCoat> UserFileRepository::LoadData(){
    ifstream inFile(this->FileName);

    TrenchCoat currentEntry;
    vector<TrenchCoat> entries;

    while (inFile >> currentEntry){
        entries.push_back(currentEntry);
    }
    return entries;
}

void UserFileRepository::WriteData(const vector<TrenchCoat>& Data){
    ofstream outFile(this->FileName);

    for (const auto& currentEntry : Data){
        outFile << currentEntry;
    }
}

void UserFileRepository::UserAddCoat(const TrenchCoat &T) {
    vector<TrenchCoat> entries = LoadData();
    this->UserCoats = entries;
    UserRepository::UserAddCoat(T);
    entries = this->UserCoats;
    WriteData(entries);
}

TrenchCoat UserFileRepository::GetCoatByIndex(int Index) {
    vector<TrenchCoat> entries = LoadData();
    this->UserCoats = entries;
    return UserRepository::GetCoatByIndex(Index);
}

int UserFileRepository::GetIndex(const TrenchCoat &T) {
    vector<TrenchCoat> entries = LoadData();
    this->UserCoats = entries;
    return UserRepository::GetIndex(T);
}

int UserFileRepository::GetSize() {
    vector<TrenchCoat> entries = LoadData();
    this->UserCoats = entries;
    return UserRepository::GetSize();
}

int UserFileRepository::GetTotalSum() {
    vector<TrenchCoat> entries = LoadData();
    this->UserCoats = entries;
    return UserRepository::GetTotalSum();
}

std::vector<TrenchCoat> UserFileRepository::GetData() {
    std::vector<TrenchCoat> newArray;
    for (int index = 0; index < this->GetSize(); index++)
    {
        newArray.push_back(this->GetCoatByIndex(index));
    }
    return newArray;
}

string UserFileRepository::getFilename() {
    return this->FileName;
}