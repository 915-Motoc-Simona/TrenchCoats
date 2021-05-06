//
// Created by Simona on 29.04.2021.
//

#ifndef A67_915_MOTOC_SIMONA_GUI_H
#define A67_915_MOTOC_SIMONA_GUI_H
#pragma once
#include <qwidget.h>
#include "../Business/AdministratorController.h"
#include "../Business/UserController.h"
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include "AdminGUI.h"
#include "UserGUI.h"

class GUI : public QWidget {
private:
    AdminGUI& admin;
    UserGUI& user;

    //graphical elements
    QPushButton* userButton,* adminButton;

    void initGUI();
    void connectSignalsAndSlots();
    void openAdminWindow();
    void openUserWindow();
public:
    GUI(AdminGUI& adminGui, UserGUI& userGui);
};


#endif //A67_915_MOTOC_SIMONA_GUI_H
