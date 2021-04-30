/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class mainWindow_t : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow_t(QWidget *parent = nullptr);
    ~mainWindow_t();

private:
    Ui::MainWindow *ui;
};
