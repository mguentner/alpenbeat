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
#include "olareceiver.h"

OlaReceiver::OlaReceiver() : Receiver()
{
    m_olaThread = NULL;
}
OlaReceiver::~OlaReceiver()
{
    if (m_olaThread != NULL) {
        m_olaThread->stop();
        delete m_olaThread;
    }
}
bool OlaReceiver::start()
{
    if (m_olaThread != NULL) {
        m_olaThread->stop();
        delete m_olaThread;
    }
    m_olaThread = new OlaEmbeddedServer();
    m_olaThread->start();
    return true;
}
bool OlaReceiver::stop()
{
    if (m_olaThread != NULL) {
        m_olaThread->stop();
        delete m_olaThread;
        m_olaThread = NULL;
    }
    return true;
}
void OlaReceiver::setUniverse(uint8_t universe)
{
    m_universe=universe;
}

void OlaReceiver::updateReceiver()
{
    m_olaThread->write_dmx(m_universe, m_connectedUniverse->getArray());
}
