//
// Created by Simona on 18.04.2021.
//

#ifndef A67_915_MOTOC_SIMONA_ADMINHTMLREPOSITORY_H
#define A67_915_MOTOC_SIMONA_ADMINHTMLREPOSITORY_H

#include "AdminFileRepository.h"

class AdminHTMLRepository : public AdminFileRepository{

public:
    std::vector<TrenchCoat> LoadData() override;
    void WriteData(const std::vector<TrenchCoat>& Data) override;
    explicit AdminHTMLRepository(const string& FileName);
};


#endif //A67_915_MOTOC_SIMONA_ADMINHTMLREPOSITORY_H
