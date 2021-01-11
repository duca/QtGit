/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "QtGit/branchitem.hpp"

#include "ui_branchitem.h"

BranchItem::BranchItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BranchItem)
{
    ui->setupUi(this);
}

BranchItem::~BranchItem()
{
    delete ui;
}
