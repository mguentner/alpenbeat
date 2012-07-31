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

#ifndef EFFECTANIMATOR_H
#define EFFECTANIMATOR_H

#include <QDialog>
#include <QAbstractButton>
#include <QTimer>
#include <stdint.h>
#include <universe.h>
#include <animator.h>
#include <cmath>

namespace Ui
{
class EffectAnimator;
}

class EffectAnimator : public QDialog, public Animator
{
    Q_OBJECT

public:
    explicit EffectAnimator(QWidget *parent = 0);
    ~EffectAnimator();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void renderNextFrame();
    void on_startButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::EffectAnimator *ui;
    QTimer *m_timer;
    QColor m_Color;
};

#endif // EFFECTANIMATOR_H