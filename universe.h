/*
 * This file is part of alpenbeat, a small lighting controller
 *
 * Copyright (C) 2012 Maximilian Güntner <maximilian.guentner@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <QObject>
#include <QByteArray>
#include <QDebug>
#include <stdint.h>

class Universe : public QObject
{
    Q_OBJECT
public:
    explicit Universe(QObject *parent = 0);
    void setChannel(uint16_t channel, uint8_t value);
    uint8_t getChannel(uint16_t channel);
    QByteArray getArray();
    void sync();
signals:
    void universeUpdated(void);
public slots:

private:
    QByteArray channels;
};

#endif // UNIVERSE_H
