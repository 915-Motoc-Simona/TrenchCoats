//
// Created by Simona on 01.05.2021.
//

#ifndef A89_915_MOTOC_SIMONA_ADMINGUI_H
#define A89_915_MOTOC_SIMONA_ADMINGUI_H

#pragma once
#include <qwidget.h>
#include "../Business/AdministratorController.h"
#include "../Business/UserController.h"
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>

class AdminGUI: public QWidget {
private:
    AdministratorController& ADMController;

    //graphical elements
    QListWidget* coatsListWidget;
    QLineEdit* sizeLineEdit, * colourLineEdit, * priceLineEdit, * quantityLineEdit, * linkLineEdit;
    QPushButton* addButton, * deleteButton,* updateButton;

    void populateList();
    void connectSignalsAndSlots();
    int getSelectedIndex();
    void addCoat();
    void deleteCoat();
    void updateCoat();
public:
    AdminGUI(AdministratorController& admController);
    void initAdminGUI();
};


#endif //A89_915_MOTOC_SIMONA_ADMINGUI_H
