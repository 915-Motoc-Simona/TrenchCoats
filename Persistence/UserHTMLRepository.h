//
// Created by Simona on 18.04.2021.
//

#ifndef A67_915_MOTOC_SIMONA_USERHTMLREPOSITORY_H
#define A67_915_MOTOC_SIMONA_USERHTMLREPOSITORY_H

#include "UserFileRepository.h"

class UserHTMLRepository : public UserFileRepository {
public:
    std::vector<TrenchCoat> LoadData() override;
    void WriteData(const std::vector<TrenchCoat>& Data) override;
    explicit UserHTMLRepository(const string& FileName);
};


#endif //A67_915_MOTOC_SIMONA_USERHTMLREPOSITORY_H
