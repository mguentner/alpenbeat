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

#ifndef OLARECEIVER_H
#define OLARECEIVER_H

#include <receiver.h>
#include <olaoutthread.h>

class OlaReceiver : public QObject, public Receiver
{
    Q_OBJECT
public:
    OlaReceiver();
    void setUniverse(uint8_t universe);
    ~OlaReceiver();
    bool stop();
    bool start();
public slots:
    void updateReceiver();

private:
    uint8_t m_universe;
    OlaOutThread *m_olaThread;
};

#endif // OLARECEIVER_H
