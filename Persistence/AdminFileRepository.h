//
// Created by Simona on 06.04.2021.
//
#pragma once
#include "AdminRepository.h"
#include <vector>
#include <fstream>

class AdminFileRepository : public AdminRepository{
public:
    explicit AdminFileRepository(const string& File);
    virtual void ChangeFileLocation(const string& File);

    virtual void AddCoat(const TrenchCoat& T) override;
    virtual void DeleteCoat(TrenchCoat& T) override;
    virtual void UpdateCoat(const TrenchCoat& oldT, TrenchCoat newT) override;
    virtual TrenchCoat GetCoatByIndex(int Index) override;
    virtual bool CheckIfCoatExists(const TrenchCoat& T) override;
    virtual int GetIndex(const TrenchCoat& T) override;
    virtual int GetSize() override;
    virtual std::vector<TrenchCoat> GetRepositoryData() override;

    std::string FileName;
private:

    virtual std::vector<TrenchCoat> LoadData();
    virtual void WriteData(const std::vector<TrenchCoat>& Data);
};



