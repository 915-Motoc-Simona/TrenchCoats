//
// Created by Simona on 06.04.2021.
//

#include "AdminFileRepository.h"
#include<iostream>

AdminFileRepository::AdminFileRepository(const string& File){
    this->FileName = File;

}

void AdminFileRepository::ChangeFileLocation(const string& File){
    this->FileName = File;

}

vector<TrenchCoat> AdminFileRepository::LoadData(){
    ifstream inFile(this->FileName);

    TrenchCoat currentEntry;
    vector<TrenchCoat> entries;

    while (inFile >> currentEntry){
        entries.push_back(currentEntry);
    }
    return entries;
}

void AdminFileRepository::WriteData(const vector<TrenchCoat>& Data){
    ofstream outFile(this->FileName);

    for (const auto& currentEntry : Data){
        outFile << currentEntry;
    }
}

void AdminFileRepository::AddCoat(const TrenchCoat &T) {
    vector<TrenchCoat> entries = LoadData();
    this->RepoCoats = entries;
    AdminRepository::AddCoat(T);
    entries = this->RepoCoats;
    WriteData(entries);
}

void AdminFileRepository::DeleteCoat(TrenchCoat &T) {
    vector<TrenchCoat> entries = LoadData();
    RepoCoats = entries;
    AdminRepository::DeleteCoat(T);
    entries = RepoCoats;
    WriteData(entries);
}

void AdminFileRepository::UpdateCoat(const TrenchCoat &oldT, TrenchCoat newT) {
    vector<TrenchCoat> entries = LoadData();
    RepoCoats = entries;
    AdminRepository::UpdateCoat(oldT, newT);
    entries = RepoCoats;
    WriteData(entries);
}

TrenchCoat AdminFileRepository::GetCoatByIndex(int Index) {
    vector<TrenchCoat> entries = LoadData();
    RepoCoats = entries;
    return AdminRepository::GetCoatByIndex(Index);
}

bool AdminFileRepository::CheckIfCoatExists(const TrenchCoat &T) {
    vector<TrenchCoat> entries = LoadData();
    RepoCoats = entries;
    return AdminRepository::CheckIfCoatExists(T);
}

int AdminFileRepository::GetIndex(const TrenchCoat &T) {
    vector<TrenchCoat> entries = LoadData();
    RepoCoats = entries;
    return AdminRepository::GetIndex(T);
}

int AdminFileRepository::GetSize() {
    vector<TrenchCoat> entries = LoadData();
    RepoCoats = entries;
    return AdminRepository::GetSize();
}

std::vector<TrenchCoat> AdminFileRepository::GetRepositoryData() {
    std::vector<TrenchCoat> newArray;
    for (int index = 0; index < this->GetSize(); index++)
    {
        newArray.push_back(this->GetCoatByIndex(index));
    }
    return newArray;
}