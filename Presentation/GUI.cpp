//
// Created by Simona on 29.04.2021.
//

#include <Qlayout.h>
#include <QFormLayout>
#include "GUI.h"
#include <QGridLayout>
#include <QObject>


GUI::GUI(AdminGUI& adminGui, UserGUI& userGui):
        admin{adminGui}, user{userGui}
        {
    this->initGUI();
    this->connectSignalsAndSlots();
}

void GUI::initGUI() {

    this->setStyleSheet("background-color: #B0E0E6;");

    QLabel *label = new QLabel(this);
    label->setFixedSize(QSize(400,80));
    label->setText("Welcome to Proper Trench Coats");
    label->setFont(QFont("Times", 16));

    this->userButton = new QPushButton{"User"};
    this->adminButton = new QPushButton{"Admin"};

    this->userButton->setFixedSize(QSize(200,80));
    this->adminButton->setFixedSize(QSize(200,80));

    this->userButton->setFont(QFont("Times", 16));
    this->adminButton->setFont(QFont("Times", 16));

    QVBoxLayout* mainLayout = new QVBoxLayout{ this};

    QGridLayout* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->userButton);
    buttonsLayout->addWidget(this->adminButton);

    mainLayout->addLayout(buttonsLayout);

}


void GUI::connectSignalsAndSlots() {
    QObject::connect(this->adminButton, &QPushButton::clicked, this, &GUI::openAdminWindow);
    QObject::connect(this->userButton, &QPushButton::clicked, this, &GUI::openUserWindow);
}

void GUI::openAdminWindow() {
    admin.resize(400, 300);
    admin.setWindowTitle("Admin mode");
    this->admin.show();

}

void GUI::openUserWindow() {
    user.resize(400, 300);
    user.setWindowTitle("User mode");
    this->user.show();

}
