/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "logController.hpp"
#include "logModel.hpp"

using namespace qtgit;

struct logController_t::privateData_t
{
};

logController_t::~logController_t () = default;

logController_t::logController_t(QObject *const parent_) : QObject (parent_)
{
	qRegisterMetaType<logModel_t>();
}
bool logController_t::init (cppgit2::repository const& repo_)
{
	return false;
}

void logController_t::handleUpdateLog () const
{
}

