/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "QtGit/brancheswidget.hpp"

#include "ui_brancheswidget.h"

BranchesWidget::BranchesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BranchesWidget)
{
    ui->setupUi(this);
}

BranchesWidget::~BranchesWidget()
{
    delete ui;
}
