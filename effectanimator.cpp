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
#include "effectanimator.h"
#include "ui_effectanimator.h"

EffectAnimator::EffectAnimator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EffectAnimator)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(renderNextFrame()));
    m_Color = QColor(255,0,0);
}

EffectAnimator::~EffectAnimator()
{
    delete ui;
}

void EffectAnimator::on_buttonBox_clicked(QAbstractButton *button)
{
    QPushButton  *b = qobject_cast<QPushButton*>(button);
    if (b == ui->buttonBox->button(QDialogButtonBox::Close)) {
        m_timer->stop();
        this->close();
    }
}
void EffectAnimator::renderNextFrame()
{
    float tmp = (float)ui->speedDial->value()/ui->speedDial->maximum();
    m_Color.setHsvF(fmod(m_Color.hueF()+tmp,1),m_Color.saturationF(),m_Color.valueF());
    for (uint8_t n=0; n<ui->devicesBox->value(); n++) {
        targetUniverse->setChannel(0+n*3,m_Color.red());
        targetUniverse->setChannel(1+n*3,m_Color.green());
        targetUniverse->setChannel(2+n*3,m_Color.blue());
    }
    targetUniverse->sync();
}
void EffectAnimator::on_startButton_clicked()
{
    //One Frame == 40ms
    m_timer->start(40);
}

void EffectAnimator::on_stopButton_clicked()
{
    m_timer->stop();
}
