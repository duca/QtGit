/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "QtGit/mainwindow.hpp"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlFileSelector>
#include <QUrl>
#include <QStringLiteral>
#include "logModel.hpp"
#include "QtQuick/QQuickView"

int main(int argc, char *argv[])
{   QApplication app(argc, argv);

	QStringList selectors;
	if (app.arguments().contains("-touch"))
		selectors += "touch";

	qtgit::logModel_t model;

    qtgit::logModel_t::logItem_t item;
    item.id = "1weqwsadsa4wr423r2sadfcsdf";
    item.description = "teste";
    item.userEmail = "duca@github.com";
    item.userName = "duca";
    item.date = "12/12/12";
    model.appendCommit (item);
    model.appendCommit (item);
    model.appendCommit (item);
    model.appendCommit (item);

//	QQmlApplicationEngine engine;
//	QQmlFileSelector::get(&engine)->setExtraSelectors(selectors);
//    engine.setInitialProperties ({{"GitLogView.GitLogModel", QVariant::fromValue(&model)}});
//	engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

//	if (engine.rootObjects().isEmpty())
//		return -1;

//    auto objs = engine.rootObjects ();

    QQuickView view;
    view.rootContext ()->setContextProperty ("GitLogModel", &model);
    view.setSource (QUrl("qrc:/qml/GitLogView.qml"));
    view.show ();

	return app.exec();
}
