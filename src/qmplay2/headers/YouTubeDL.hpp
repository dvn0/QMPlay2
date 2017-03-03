/*
	QMPlay2 is a video and audio player.
	Copyright (C) 2010-2017  Błażej Szczygieł

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published
	by the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <IOController.hpp>

#include <QCoreApplication>
#include <QProcess>

class NetworkReply;

class YouTubeDL : public BasicIO
{
	Q_DECLARE_TR_FUNCTIONS(YouTubeDL)
	Q_DISABLE_COPY(YouTubeDL)

public:
	YouTubeDL();
	~YouTubeDL();

	void addr(const QString &url, const QString &param, QString *streamUrl, QString *name, QString *extension, QString *err = nullptr);

	QStringList exec(const QString &url, const QStringList &args, QString *silentErr = nullptr, bool canUpdate = true);

private:
	void abort() override final;

	IOController<NetworkReply> m_reply;
	QProcess m_process;
	bool m_aborted;
};