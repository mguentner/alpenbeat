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
#include "beateffectanimator.h"
#include "ui_beateffectanimator.h"

BeatEffectAnimator::BeatEffectAnimator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BeatEffectAnimator)
{
    ui->setupUi(this);
    m_Controller = new libbeat::BeatController(0,4096,44100,192);
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(renderNextFrame()));
    m_Color = QColor(255,0,0);
    connect(m_Controller,SIGNAL(beatDrum()),this,SLOT(beatDetected()));
    nextFrameWhite = false;
    m_currentColor = 0;
    m_Colors.append(Qt::red);
    m_Colors.append(Qt::blue);
    m_Colors.append(Qt::green);
}

BeatEffectAnimator::~BeatEffectAnimator()
{
    m_Controller->stop();
    delete m_Controller;
    delete ui;
}

void BeatEffectAnimator::renderNextFrame()
{
    QColor *displayColor = &m_Color;
    if (nextFrameWhite == true) {
        double v=log(m_Controller->getBuffer()->average_pwr())/log(65536);
        nextFrameWhite=false;
        //fmod(m_Color.hueF()+0.05,1)
        m_Color.setHsvF(m_Colors[m_currentColor].hueF(),m_Color.saturationF(),v);
        m_currentColor++;
        if (m_currentColor >= m_Colors.size())
            m_currentColor=0;
    } else {
        m_Color.setHsvF(m_Color.hueF(),m_Color.saturationF(),log(m_Controller->getBuffer()->average_pwr()+1)/log(65537));
    }
    for (uint8_t n=0; n<ui->devicesBox->value(); n++) {
        targetUniverse->setChannel(0+n*3,displayColor->red());
        targetUniverse->setChannel(1+n*3,displayColor->green());
        targetUniverse->setChannel(2+n*3,displayColor->blue());
    }
    targetUniverse->sync();
}

void BeatEffectAnimator::beatDetected()
{
    nextFrameWhite=true;
}

void BeatEffectAnimator::on_startButton_clicked()
{
    //One Frame == 40ms
    m_timer->start(40);
    m_Controller->start();

}

void BeatEffectAnimator::on_stopButton_clicked()
{
    m_timer->stop();
    m_Controller->stop();
}
