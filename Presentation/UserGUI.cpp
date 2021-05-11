//
// Created by Simona on 01.05.2021.
//

#include "UserGUI.h"
#include <Qlayout.h>
#include <QFormLayout>
#include "GUI.h"
#include <QGridLayout>
#include <QObject>
#include <QMessageBox>
#include <QTextStream>
#include <Qpainter>

UserGUI::UserGUI(AdministratorController &admController, UserController &userController):
        ADMController{admController}, USERController{userController}
{
    initUserGUI();
    allCoats();
    populateList();
    connectSignalsAndSlots();
}

void UserGUI::initUserGUI() {
    this->setStyleSheet("background-color: #F0FFF0;");

    this->coatsListWidget = new QListWidget{};
    this->basketListWidget = new QListWidget{};
    this->coatsBySizeListWidget = new QListWidget{};

    this->sizeLineEdit = new QLineEdit{};
    this->colourLineEdit = new QLineEdit{};
    this->priceLineEdit = new QLineEdit{};
    this->quantityLineEdit = new QLineEdit{};

    this->shoppingButton = new QPushButton{"Go shopping"};
    this->seeBasketButton = new QPushButton{"See shopping basket"};
    this->buyButton = new QPushButton{"I want to buy it!"};
    this->webButton = new QPushButton{"See website"};
//  this->nextButton = new QPushButton{"Next..."};
    this->findButton = new QPushButton{"Find coats"};

    this->shoppingButton->setFixedSize(QSize(200,80));
    this->seeBasketButton->setFixedSize(QSize(200,80));

    this->shoppingButton->setFont(QFont("Times", 12));
    this->seeBasketButton->setFont(QFont("Times", 12));

    this->userLayout = new QVBoxLayout{ this};


    QGridLayout* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->shoppingButton);
    buttonsLayout->addWidget(this->seeBasketButton);
    userLayout->addLayout(buttonsLayout);

    this->comboOptions = new QComboBox{};
    this->comboOptions->addItem("All sizes");
    this->comboOptions->addItem("XS");
    this->comboOptions->addItem("S");
    this->comboOptions->addItem("M");
    this->comboOptions->addItem("L");
    this->comboOptions->addItem("XL");

    userLayout->addWidget(comboOptions);

    this->shoppingButtonsLayout = new QGridLayout{};
    userLayout->addWidget(this->findButton);
    shoppingButtonsLayout->addWidget(this->buyButton);
    shoppingButtonsLayout->addWidget(this->webButton);

    userLayout->addWidget(this->coatsListWidget);
    userLayout->addWidget(this->coatsBySizeListWidget);
    userLayout->addLayout(this->shoppingButtonsLayout);

    coatsListWidget->setVisible(false);
    coatsBySizeListWidget->setVisible(false);
    findButton->setVisible(false);
    buyButton->setVisible(false);
    webButton->setVisible(false);
    comboOptions->setVisible(false);

}

void UserGUI::allCoats() {
    this->coatsListWidget->clear();
    vector<TrenchCoat> allCoats = this->ADMController.GetAllTrenchCoats();

    for(TrenchCoat& c: allCoats)
        this->coatsListWidget->addItem(QString::fromStdString(c.GetSize()) + " | " + QString::fromStdString(c.GetColour()) + " | " + QString::fromStdString(to_string(c.GetPrice())) + "$ | " + QString::fromStdString(to_string(c.GetQuantity())) + " left");

}

void UserGUI::populateList() {
    this->basketListWidget->clear();
    vector<TrenchCoat> allCoats = this->USERController.GetShoppingBasket();

    for(TrenchCoat& c: allCoats)
        this->basketListWidget->addItem(QString::fromStdString(c.GetSize()) + " | " + QString::fromStdString(c.GetColour()) + " | " + QString::fromStdString(to_string(c.GetPrice())) + "$ ");
    this->basketListWidget->addItem("Total sum: " + QString::fromStdString(to_string(USERController.GetTotalSum())) + "$");
}

void UserGUI::connectSignalsAndSlots() {
    QObject::connect(this->seeBasketButton, &QPushButton::clicked, this, &UserGUI::seeBasket);
    QObject::connect(this->shoppingButton, &QPushButton::clicked, this, &UserGUI::goShopping);
    QObject::connect(buyButton, &QPushButton::clicked, this, &UserGUI::buyButtonPressed);
    QObject::connect(webButton, &QPushButton::clicked, this, &UserGUI::webButtonPressed);
    QObject::connect(findButton, &QPushButton::clicked, this,&UserGUI::findButtonPressed);

}

int UserGUI::getSelectedIndex() {
    QModelIndexList  selectedIndexes;
    if(ok==0)
        selectedIndexes = this->coatsListWidget->selectionModel()->selectedIndexes();
    else
        selectedIndexes = this->coatsBySizeListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.size()==0){
        this->sizeLineEdit->clear();
        this->colourLineEdit->clear();
        this->priceLineEdit->clear();
        this->quantityLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void UserGUI::seeBasket() {
    coatsListWidget->setVisible(false);
    buyButton->setVisible(false);
    webButton->setVisible(false);
    findButton->setVisible(false);
    comboOptions->setVisible(false);
    coatsBySizeListWidget->setVisible(false);
    seeBasketButton->setVisible(false);
    shoppingButton->setVisible(true);

    userLayout->addWidget(this->basketListWidget);
    basketListWidget->setVisible(true);
}

void UserGUI::goShopping() {
    basketListWidget->setVisible(false);
    shoppingButton->setVisible(false);
    coatsBySizeListWidget->setVisible(false);
    seeBasketButton->setVisible(true);
    comboOptions->setVisible(true);
    findButton->setVisible(true);
    coatsListWidget->setVisible(true);
    buyButton->setVisible(true);
    webButton->setVisible(true);
}

void UserGUI::buyButtonPressed() {
    int selectedIndex = this->getSelectedIndex();
    if(selectedIndex < 0){
        QMessageBox::critical(this, "Error", "No coat was selected!");
        return;
    }

    TrenchCoat c;
    if(ok==0)
        c = this->ADMController.GetAllTrenchCoats()[selectedIndex];
    else
        c = this->ADMController.GetAllTrenchCoatsBySize(size.toStdString())[selectedIndex];
    try {
        this->USERController.AddCoat(c);
        QMessageBox::information(this, "Ok", "Coat successfully added to your basket!");
    }
    catch(MyException &e){
        QMessageBox::critical(this, "Error", e.what());
    }

    this->populateList();
}


void UserGUI::webButtonPressed() {
    int selectedIndex = this->getSelectedIndex();
    if(selectedIndex < 0){
        QMessageBox::critical(this, "Error", "No coat was selected!");
        return;
    }

    TrenchCoat c;
    if(ok==0)
        c = this->ADMController.GetAllTrenchCoats()[selectedIndex];
    else
        c = this->ADMController.GetAllTrenchCoatsBySize(size.toStdString())[selectedIndex];

    string browser = "start ";
    browser += c.GetPhotograph();
    system(browser.c_str());

}

void UserGUI::coatsBySize() {
    this->coatsBySizeListWidget->clear();
    vector<TrenchCoat> coats = this->ADMController.GetAllTrenchCoatsBySize(size.toStdString());

    for(TrenchCoat& c: coats)
        this->coatsBySizeListWidget->addItem(QString::fromStdString(c.GetSize()) + " | " + QString::fromStdString(c.GetColour()) + " | " + QString::fromStdString(to_string(c.GetPrice())) + "$ | " + QString::fromStdString(to_string(c.GetQuantity())) + " left");

}

void UserGUI::findButtonPressed() {
    size = this->comboOptions->currentText();
    if(size!="All sizes"){
        ok = 1;
        this->coatsBySize();
        this->coatsBySizeListWidget->setVisible(true);
        coatsListWidget->setVisible(false);
    }
    else{
        ok = 0;
        this->allCoats();
        this->coatsBySizeListWidget->setVisible(false);
        coatsListWidget->setVisible(true);
    }
}
