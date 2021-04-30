//
// Created by Simona on 18.03.2021.
//

#pragma once
#include "TrenchCoat.h"
#include "AdminRepository.h"
#include "AdministratorController.h"
#include "UserRepository.h"
#include "UserController.h"
#include "AdminFileRepository.h"
#include "UserFileRepository.h"
#include "MyException.h"
#include <iostream>

//TEST_CASE("DOMAIN TESTS"){
//    TrenchCoat myObj;
//    TrenchCoat myObj2;
//    myObj.SetTrenchCoat(&myObj, "S", "Black", 500, 10, "http://...");
//    myObj2.SetTrenchCoat(&myObj2,"S", "Black", 500, 10, "http://...");
//    REQUIRE_EQ(myObj.GetPrice(), 500);
//    REQUIRE_EQ(myObj.GetColour(),  "Black");
//    REQUIRE_EQ(myObj.GetSize(), "S");
//    REQUIRE_EQ(myObj.GetPhotograph(), "http://...");
//    REQUIRE_EQ(myObj.GetQuantity(), 10);
//
//    REQUIRE_EQ(myObj.CheckIfEqual(myObj2), true);
//
//    myObj.SetPhotograph("http2");
//    myObj.SetQuantity(8);
//    myObj.SetPrice(400);
//    myObj.SetColour("Red");
//    myObj.SetSize("XXL");
//
//    REQUIRE_EQ(myObj.GetPrice(), 400);
//    REQUIRE_EQ(myObj.GetColour(), "Red");
//    REQUIRE_EQ(myObj.GetSize(), "XXL");
//    REQUIRE_EQ(myObj.GetPhotograph(), "http2");
//    REQUIRE_EQ(myObj.GetQuantity(), 8);
//}
//
//TEST_CASE("REPOSITORY TESTS"){
//    AdminRepository repo;
//    TrenchCoat myObj;
//    myObj.SetTrenchCoat(&myObj, "S", "Black", 500, 10, "http://...");
//
//    repo.AddCoat(myObj);
//    REQUIRE_EQ(repo.GetSize(), 1);
//
//    TrenchCoat myObj2;
//    myObj2.SetTrenchCoat(&myObj2,"XS", "Black", 500, 0, "http://...");
//    repo.AddCoat(myObj2);
//    REQUIRE_EQ(repo.GetSize(), 2);
//
//    repo.DeleteCoat(myObj2);
//    REQUIRE_EQ(repo.GetSize(), 1);
//
//    TrenchCoat newObj;
//    newObj.SetTrenchCoat(&newObj, "S", "Black", 600, 30, "http://...");
//
//    repo.UpdateCoat(myObj, newObj);
//
//    REQUIRE_EQ(newObj.GetQuantity(), 30);
//    REQUIRE_EQ(newObj.GetPrice(), 600);
//
//}
//
//TEST_CASE("CONTROLLER TESTS"){
//    AdministratorController controller;
//
//    REQUIRE_EQ(controller.GetLength(), 0);
//
//    controller.AddCoat("S", "Blue", 100, 10, "www.url.com");
//
//    REQUIRE_EQ(controller.GetLength(), 1);
//
//    controller.AddCoat("M", "Blue", 100, 0, "www.url2.com");
//    REQUIRE_EQ(controller.GetLength(), 2);
//
//    controller.DeleteCoat("M", "Blue");
//    REQUIRE_EQ(controller.GetLength(), 1);
//
//    controller.UpdateCoat("S", "Blue", 10, 1);
//
//    DYNAMIC_ARRAY<TrenchCoat> list;
//    controller.GetAllTrenchCoats(&list);
//
//    REQUIRE_EQ(list.get(0).GetPrice(), 10);
//    REQUIRE_EQ(list.get(0).GetQuantity(), 1);
//
//}
//

class Test{
public:
    static void TestDomain();
    static void TestController();
    static void TestRepository();
    static void TestDynamicArray();
    static void TestUserRepository();
    static void TestUserController();
};