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

#ifndef BEATEFFECTANIMATOR_H
#define BEATEFFECTANIMATOR_H

#include <QDialog>
#include <libbeat/beatcontroller.h>

#include <QAbstractButton>
#include <QTimer>
#include <stdint.h>
#include <universe.h>
#include <animator.h>
#include <cmath>

namespace Ui
{
class BeatEffectAnimator;
}

class BeatEffectAnimator : public QDialog, public Animator
{
    Q_OBJECT

public:
    explicit BeatEffectAnimator(QWidget *parent = 0);
    ~BeatEffectAnimator();
private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void renderNextFrame();
    void beatDetected();

private:
    Ui::BeatEffectAnimator *ui;
    libbeat::BeatController *m_Controller;
    QTimer *m_timer;
    QColor m_Color;
    QVector<QColor> m_Colors;
    uint16_t m_currentColor;
    bool nextFrameWhite;
};

#endif // BEATEFFECTANIMATOR_H
