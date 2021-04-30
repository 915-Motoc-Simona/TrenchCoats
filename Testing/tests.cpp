#include "tests.h"
#include <cassert>
#include <cstring>

void Test::TestDomain(){
    TrenchCoat myObj("S", "Black", 500, 10, "http://...");
    TrenchCoat myObj2("S", "Black", 500, 10, "http://...");
    assert(myObj.GetPrice() == 500);
    assert(myObj.GetColour() == "Black");
    assert(myObj.GetSize() == "S");
    assert(myObj.GetPhotograph() == "http://...");
    assert(myObj.GetQuantity() == 10);

    assert(myObj==myObj2);

    myObj.SetPhotograph("http2");
    myObj.SetQuantity(8);
    myObj.SetPrice(400);
    myObj.SetColour("Red");
    myObj.SetSize("XXL");

    assert(myObj.GetPrice() == 400);
    assert(myObj.GetColour() == "Red");
    assert(myObj.GetSize() == "XXL");
    assert(myObj.GetPhotograph() == "http2");
    assert(myObj.GetQuantity() == 8);
}

void Test::TestRepository(){
    AdminRepository repo;
    TrenchCoat myObj("S", "Black", 500, 10, "http://...");;
    TrenchCoat myObjerror("S", "Black", 500, 0, "http://...");

    repo.AddCoat(myObj);
    assert(repo.GetSize() == 1);
    assert(repo.GetIndex(myObj) == 0);

    try{
        repo.AddCoat(myObjerror);
    }
    catch(MyException &e){
        assert(strcmp(e.what(), "\nTrench coat already exists\n") == 0);
    }

    TrenchCoat myObj2("XS", "Black", 500, 0, "http://...");
    repo.AddCoat(myObj2);
    assert(repo.GetSize() == 2);

    repo.DeleteCoat(myObj2);
    assert(repo.GetSize() == 1);

    try{
        repo.DeleteCoat(myObjerror);
    }catch(MyException &e){
        assert(true);
    }

    try{
        repo.DeleteCoat(myObj);
    }catch(MyException &e){
        assert(true);
    }

    TrenchCoat newObj("S", "Black", 600, 30, "http://...");

    repo.UpdateCoat(myObj, newObj);

    assert(newObj.GetQuantity() == 30);
    assert(newObj.GetPrice() == 600);

//    try{
//        repo.UpdateCoat(myObj, myObjerror);
//    }
//    catch(MyException &e){
//        assert(true);
//    }


}


void Test::TestController(){
    ofstream fout("testing.txt");
    fout << "";
    AdminFileRepository repo("testing.txt");
    AdministratorController controller(repo);

    assert(controller.GetLength() == 0);

    controller.AddCoat("S", "Blue", 100, 10, "www.url.com");

    assert(controller.GetLength() == 1);

    controller.AddCoat("M", "Blue", 100, 0, "www.url2.com");
    assert(controller.GetLength() == 2);

    try{
        controller.AddCoat("M", "Blue", 100, 0, "www.url2.com");
    }
    catch(MyException &e){
        assert(true);
    }

    controller.DeleteCoat("M", "Blue");
    assert(controller.GetLength() == 1);

    try{
        controller.DeleteCoat("S", "Blue");
    }
    catch(MyException &e){
        assert(true);
    }

    controller.UpdateCoat("S", "Blue", 10, 1);

    try{
        controller.UpdateCoat("M", "Blue", 20, 30);
    }
    catch(MyException &e){
        assert(true);
    }

    vector<TrenchCoat> list;
    list = controller.GetAllTrenchCoats();

    controller.AddCoat("M", "Blue", 100, 0, "www.url2.com");
    vector<TrenchCoat> list2;
    int nr = 0;
    list2 = controller.GetSoldOutTrenchCoats();
    nr = list2.size();
    assert(nr == 1);

    assert(list.at(0).GetPrice() == 10);
    assert(list.at(0).GetQuantity() == 1);

    vector<TrenchCoat> list3;
    list3 = controller.GetAllTrenchCoatsBySize( "S");
    nr = list3.size();
    assert(nr == 1);

    //cout<<"Test admin controller done...\n";
}

void Test::TestDynamicArray() {
    DYNAMIC_ARRAY<int> list;
    list.add(5);
    assert(list.length() == 1);
    assert(list.get(0) == 5);

    list.add(6);
    list.add(7);

    list.deleteAt(1);
    assert(list.length() == 2);
    assert(list.get(1) == 7);

    list.set(1, 10);
    assert(list.get(1) == 10);

    for(int i=0;i<=100;i++)
        list.add(i);

}

void Test::TestUserRepository(){
    TrenchCoat myObj1("S", "Black", 500, 10, "http://...");
    TrenchCoat myObj2("M", "Black", 500, 10, "http://...");
    TrenchCoat myObj3("XS", "Black", 500, 0, "http://...");


    UserRepository repo;
    repo.UserAddCoat(myObj1);
    repo.UserAddCoat(myObj2);
    try{
        repo.UserAddCoat(myObj3);
    }catch(MyException &e){
        assert(true);
    }

    assert(repo.GetSize() == 2);
    assert(repo.GetTotalSum() == 1000);
    assert(repo.GetIndex(myObj1) == 0);

}

void Test::TestUserController() {
//    TrenchCoat myObj1("S", "Black", 500, 10, "http://...");
//    TrenchCoat myObj2("M", "Black", 500, 10, "http://...");
//    TrenchCoat myObj3("XS", "Black", 500, 0, "http://...");
//
//    vector<TrenchCoat> list;
//
//    UserFileRepository repo("testingUser.txt");
//    UserController controller(repo);
//    controller.AddCoat(myObj1);
//    controller.AddCoat(myObj2);
//    try{
//        controller.AddCoat(myObj3);
//    }
//    catch(MyException &e){
//        assert(true);
//    }
//
//    assert(controller.GetTotalSum() == 1000);
//    assert(controller.GetLength() == 2);
//
//    list = controller.GetShoppingBasket();
}