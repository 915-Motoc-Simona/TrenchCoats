//
// Created by Simona on 13.04.2021.
//

#ifndef A67_915_MOTOC_SIMONA_USERFILEREPOSITORY_H
#define A67_915_MOTOC_SIMONA_USERFILEREPOSITORY_H
#include "UserRepository.h"

#include <fstream>

class UserFileRepository: public UserRepository{
private:
    virtual std::vector<TrenchCoat> LoadData();
    virtual void WriteData(const std::vector<TrenchCoat>& Data);
public:
    std::string FileName;

    UserFileRepository(const string& File);
    virtual void UserAddCoat(const TrenchCoat& T) override;
    //Returns the current total price of the coats
    virtual int GetTotalSum() override;
    //Returns the index of a specific coat
    virtual int GetIndex(const TrenchCoat& T) override;
    //Returns how many coats does the user have in the basket
    virtual int GetSize() override;
    //Returns the Trench Coat object that has the Index given as parameter
    virtual TrenchCoat GetCoatByIndex(int Index) override;
    virtual std::vector<TrenchCoat> GetData() override;
    virtual string getFilename() override;
};


#endif //A67_915_MOTOC_SIMONA_USERFILEREPOSITORY_H
