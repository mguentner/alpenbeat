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

#ifndef ALPENBEATGLRECEIVER_H
#define ALPENBEATGLRECEIVER_H

#include <QGLWidget>
#include <stdint.h>
#include <receiver.h>

class AlpenbeatGLReceiver : public QGLWidget, public Receiver
{
    Q_OBJECT
public:
    explicit AlpenbeatGLReceiver(QWidget *parent = 0);
private:
    void drawCube(QVector3D translate, QVector3D scale, QColor color);
    void initProjection();

signals:
public slots:
    void updateReceiver();
    bool start();
    bool stop();
protected slots:
    void resizeGL();
    void paintGL();
    void initializeGL();
private:
    QVector<QColor> m_Colors;
};

#endif // ALPENBEATGLRECEIVER_H
