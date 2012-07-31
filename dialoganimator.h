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

#ifndef DIALOGANIMATOR_H
#define DIALOGANIMATOR_H

#include <QDialog>
#include <animator.h>
#include <QAbstractButton>
#include <QPushButton>
namespace Ui
{
class DialogAnimator;
}

class DialogAnimator :public QDialog, public Animator
{
    Q_OBJECT

public:
    explicit DialogAnimator(QWidget *parent = 0);
    ~DialogAnimator();
    void updateDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_previousButton_clicked();

    void on_nextButton_clicked();

    void sliderChanged();

    void paintEvent(QPaintEvent *event);

private:
    Ui::DialogAnimator *ui;
    uint16_t startChannel;
    uint16_t stopChannel;
};

#endif // DIALOGANIMATOR_H
