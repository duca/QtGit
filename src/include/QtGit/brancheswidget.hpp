/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <QWidget>

namespace Ui {
class BranchesWidget;
}

class BranchesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BranchesWidget(QWidget *parent = nullptr);
    ~BranchesWidget();

private:
    Ui::BranchesWidget *ui;
};
