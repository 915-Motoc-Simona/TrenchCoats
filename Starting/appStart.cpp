//
// Created by Simona on 18.03.2021.
//

#include "../Persistence/AdminRepository.h"
#include "../Persistence/AdminFileRepository.h"
#include "../Persistence/AdminHTMLRepository.h"
#include "../Persistence/UserFileRepository.h"
#include "../Persistence/UserHTMLRepository.h"
#include "../Persistence/UserRepository.h"
#include "../Presentation/GUI.h"
#include "../Testing/tests.h"
#include "../Business/AdministratorController.h"
#include "../Business/UserController.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

int main(int argc, char* argv[]){

//    Test::TestDomain();
//    Test::TestDynamicArray();
//    Test::TestController();
//    Test::TestRepository();
//    Test::TestUserRepository();
//    Test::TestUserController();

    QApplication a(argc, argv);

    AdminFileRepository admFileRepo("D:\\info\\a89-915-Motoc-Simona\\administrator.csv");
    UserFileRepository userRepo("D:\\info\\a89-915-Motoc-Simona\\user.csv");
    UserController userController(userRepo, "1");
    AdministratorController administratorController(admFileRepo);

    GUI gui{};
    gui.show();
    return a.exec();
}