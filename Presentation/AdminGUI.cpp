//
// Created by Simona on 01.05.2021.
//

#include "AdminGUI.h"
#include <Qlayout.h>
#include <QFormLayout>
#include "GUI.h"
#include <QGridLayout>
#include <QObject>
#include <QMessageBox>

AdminGUI::AdminGUI(AdministratorController &admController):
        ADMController{admController}
{
    this->initAdminGUI();
    this->populateList();
    this->connectSignalsAndSlots();
}

void AdminGUI::initAdminGUI() {
    this->setStyleSheet("background-color: #F0FFF0;");

    this->coatsListWidget = new QListWidget{};
    this->sizeLineEdit = new QLineEdit{};
    this->colourLineEdit = new QLineEdit{};
    this->priceLineEdit = new QLineEdit{};
    this->quantityLineEdit = new QLineEdit{};
    this->linkLineEdit = new QLineEdit{};

    this->addButton = new QPushButton{"Add"};
    this->deleteButton = new QPushButton{"Delete"};
    this->updateButton = new QPushButton{"Update"};

    QVBoxLayout* adminLayout = new QVBoxLayout{ this};

    adminLayout->addWidget(this->coatsListWidget);

    QFormLayout* coatDetailsLayout = new QFormLayout{};
    coatDetailsLayout->addRow("Size", this->sizeLineEdit);
    coatDetailsLayout->addRow("Colour", this->colourLineEdit);
    coatDetailsLayout->addRow("Price", this->priceLineEdit);
    coatDetailsLayout->addRow("Quantity", this->quantityLineEdit);
    coatDetailsLayout->addRow("Link", this->linkLineEdit);

    adminLayout->addLayout(coatDetailsLayout);

    QGridLayout* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->addButton);
    buttonsLayout->addWidget(this->deleteButton);
    buttonsLayout->addWidget(this->updateButton);

    adminLayout->addLayout(buttonsLayout);

}

void AdminGUI::populateList() {
    this->coatsListWidget->clear();
    vector<TrenchCoat> allCoats = this->ADMController.GetAllTrenchCoats();

    for(TrenchCoat& c: allCoats)
        this->coatsListWidget->addItem(QString::fromStdString(c.GetSize()) + " | " + QString::fromStdString(c.GetColour()) + " | " + QString::fromStdString(to_string(c.GetPrice())) + "$ | " + QString::fromStdString(to_string(c.GetQuantity())) + " left");

}

void AdminGUI::connectSignalsAndSlots() {
    QObject::connect(this->coatsListWidget, &QListWidget::itemSelectionChanged, [this](){
        int selectedIndex = this->getSelectedIndex();

        if(selectedIndex < 0)
            return;

        TrenchCoat C = this->ADMController.GetAllTrenchCoats()[selectedIndex];
        this->sizeLineEdit->setText(QString::fromStdString(C.GetSize()));
        this->colourLineEdit->setText(QString::fromStdString(C.GetColour()));
        this->priceLineEdit->setText(QString::fromStdString(to_string(C.GetPrice())));
        this->quantityLineEdit->setText(QString::fromStdString(to_string(C.GetQuantity())));
        this->linkLineEdit->setText(QString::fromStdString(C.GetPhotograph()));

    });

    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminGUI::addCoat);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminGUI::deleteCoat);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &AdminGUI::updateCoat);

}

int AdminGUI::getSelectedIndex() {
    QModelIndexList  selectedIndexes = this->coatsListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.size()==0){
        this->sizeLineEdit->clear();
        this->colourLineEdit->clear();
        this->priceLineEdit->clear();
        this->quantityLineEdit->clear();
        this->linkLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void AdminGUI::addCoat() {
    string size = this->sizeLineEdit->text().toStdString();
    string colour = this->colourLineEdit->text().toStdString();
    int price = this->priceLineEdit->text().toInt();
    int quantity = this->quantityLineEdit->text().toInt();
    string link = this->linkLineEdit->text().toStdString();

    try{
        this->ADMController.AddCoat(size, colour, price, quantity, link);
    }
    catch(MyException &e){
        QMessageBox::critical(this, "Error", e.what());
    }

    this->populateList();

    int lastElement = this->ADMController.GetAllTrenchCoats().size() - 1;
    this->coatsListWidget->setCurrentRow(lastElement);
}

void AdminGUI::deleteCoat() {
    int selectedIndex = this->getSelectedIndex();
    if(selectedIndex < 0){
        QMessageBox::critical(this, "Error", "No coat was selected!");
    }

    TrenchCoat c = this->ADMController.GetAllTrenchCoats()[selectedIndex];
    try {
        this->ADMController.DeleteCoat(c.GetSize(), c.GetColour());
    }
    catch(MyException &e){
        QMessageBox::critical(this, "Error", e.what());
    }

    this->populateList();
}

void AdminGUI::updateCoat() {
    string size = this->sizeLineEdit->text().toStdString();
    string colour = this->colourLineEdit->text().toStdString();
    int price = this->priceLineEdit->text().toInt();
    int quantity = this->quantityLineEdit->text().toInt();

    try{
        this->ADMController.UpdateCoat(size, colour, price, quantity);
    }
    catch(MyException &e){
        QMessageBox::critical(this, "Error", e.what());
    }

    this->populateList();

}

