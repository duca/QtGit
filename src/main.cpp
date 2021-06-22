/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "QtGit/mainWindow.hpp"
#include "logController.hpp"
#include "logModel.hpp"
#include <QApplication>
#include <QStringLiteral>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	QStringList selectors;
	if (app.arguments().contains("-touch"))
		selectors += "touch";

    qtgit::mainWindow_t win(QStringLiteral("qrc:/qml/main.qml"));
    win.init ();

	return app.exec();
}
