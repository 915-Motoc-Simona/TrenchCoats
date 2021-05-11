//
// Created by Simona on 01.05.2021.
//

#ifndef A89_915_MOTOC_SIMONA_USERGUI_H
#define A89_915_MOTOC_SIMONA_USERGUI_H
#pragma once
#include <qwidget.h>
#include "../Business/AdministratorController.h"
#include "../Business/UserController.h"
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>

class UserGUI: public QWidget {
private:
    AdministratorController& ADMController;
    UserController& USERController;

    QVBoxLayout* userLayout;
    QListWidget* coatsListWidget,* basketListWidget, *coatsBySizeListWidget;
    QGridLayout* shoppingButtonsLayout;
    QLineEdit* sizeLineEdit, * colourLineEdit, * priceLineEdit, * quantityLineEdit;
    QPushButton* shoppingButton, * seeBasketButton,* buyButton, * nextButton, * webButton, *findButton;
    QComboBox* comboOptions;
    QString size;
    int ok = 0;
    int counter = 0;
    void initUserGUI();
    void populateList();
    void allCoats();
    void coatsBySize();
    void connectSignalsAndSlots();
    int getSelectedIndex();
    void seeBasket();
    void goShopping();
    void buyButtonPressed();
    void webButtonPressed();
    void findButtonPressed();

public:
    UserGUI(AdministratorController& admController, UserController& userController);
};


#endif //A89_915_MOTOC_SIMONA_USERGUI_H
