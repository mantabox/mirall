/*
 * Copyright (C) by Duncan Mac-Vicar P. <duncan@kde.org>
 * Copyright (C) by Klaas Freitag <freitag@kde.org>
 * Copyright (C) by Krzesimir Nowak <krzesimir@endocode.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#include <QNetworkAccessManager>

#include "dummycredentials.h"

namespace Mirall
{

void DummyCredentials::prepareSyncContext(CSYNC*)
{}

bool DummyCredentials::changed(AbstractCredentials* credentials) const
{
    DummyCredentials* dummy(dynamic_cast< DummyCredentials* >(credentials));

    return dummy == 0;
}

QString DummyCredentials::authType() const
{
    return QString::fromLatin1("dummy");
}

QNetworkAccessManager* DummyCredentials::getQNAM() const
{
    return new QNetworkAccessManager;
}

bool DummyCredentials::ready() const
{
    return true;
}

void DummyCredentials::fetch()
{
    Q_EMIT(fetched());
}

void DummyCredentials::persistForUrl(const QString&)
{}

} // ns Mirall
