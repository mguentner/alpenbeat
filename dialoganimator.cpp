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
#include "dialoganimator.h"
#include "ui_dialoganimator.h"

DialogAnimator::DialogAnimator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAnimator)
{
    ui->setupUi(this);
    startChannel=0;
    stopChannel=15;
    connect(ui->verticalSlider_1,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_2,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_3,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_4,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_5,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_6,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_7,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_8,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_9,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_10,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_11,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_12,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_13,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_14,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_15,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
    connect(ui->verticalSlider_16,SIGNAL(valueChanged(int)),this, SLOT(sliderChanged()));
}

DialogAnimator::~DialogAnimator()
{
    delete ui;
}

void DialogAnimator::on_buttonBox_clicked(QAbstractButton *button)
{
    QPushButton  *b = qobject_cast<QPushButton*>(button);
    if (b == ui->buttonBox->button(QDialogButtonBox::Close))
        this->close();
}
void DialogAnimator::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    updateDialog();
}
void DialogAnimator::updateDialog()
{
    ui->label_1->setText(QString::number((startChannel)%512+1));
    ui->label_2->setText(QString::number((startChannel+1)%512+1));
    ui->label_3->setText(QString::number((startChannel+2)%512+1));
    ui->label_4->setText(QString::number((startChannel+3)%512+1));
    ui->label_5->setText(QString::number((startChannel+4)%512+1));
    ui->label_6->setText(QString::number((startChannel+5)%512+1));
    ui->label_7->setText(QString::number((startChannel+6)%512+1));
    ui->label_8->setText(QString::number((startChannel+7)%512+1));
    ui->label_9->setText(QString::number((startChannel+8)%512+1));
    ui->label_10->setText(QString::number((startChannel+9)%512+1));
    ui->label_11->setText(QString::number((startChannel+10)%512+1));
    ui->label_12->setText(QString::number((startChannel+11)%512+1));
    ui->label_13->setText(QString::number((startChannel+12)%512+1));
    ui->label_14->setText(QString::number((startChannel+13)%512+1));
    ui->label_15->setText(QString::number((startChannel+14)%512+1));
    ui->label_16->setText(QString::number((startChannel+15)%512+1));

    ui->verticalSlider_1->setValue(targetUniverse->getChannel((startChannel)%512));
    ui->verticalSlider_2->setValue(targetUniverse->getChannel((startChannel+1)%512));
    ui->verticalSlider_3->setValue(targetUniverse->getChannel((startChannel+2)%512));
    ui->verticalSlider_4->setValue(targetUniverse->getChannel((startChannel+3)%512));
    ui->verticalSlider_5->setValue(targetUniverse->getChannel((startChannel+4)%512));
    ui->verticalSlider_6->setValue(targetUniverse->getChannel((startChannel+5)%512));
    ui->verticalSlider_7->setValue(targetUniverse->getChannel((startChannel+6)%512));
    ui->verticalSlider_8->setValue(targetUniverse->getChannel((startChannel+7)%512));
    ui->verticalSlider_9->setValue(targetUniverse->getChannel((startChannel+8)%512));
    ui->verticalSlider_10->setValue(targetUniverse->getChannel((startChannel+9)%512));
    ui->verticalSlider_11->setValue(targetUniverse->getChannel((startChannel+10)%512));
    ui->verticalSlider_12->setValue(targetUniverse->getChannel((startChannel+11)%512));
    ui->verticalSlider_13->setValue(targetUniverse->getChannel((startChannel+12)%512));
    ui->verticalSlider_14->setValue(targetUniverse->getChannel((startChannel+13)%512));
    ui->verticalSlider_15->setValue(targetUniverse->getChannel((startChannel+14)%512));
    ui->verticalSlider_16->setValue(targetUniverse->getChannel((startChannel+15)%512));

}

void DialogAnimator::on_previousButton_clicked()
{
    int32_t tmpChannel = startChannel;
    tmpChannel-=16;
    if (tmpChannel < 0) {
        startChannel=511+tmpChannel;
    } else
        startChannel=tmpChannel;

}

void DialogAnimator::on_nextButton_clicked()
{
    startChannel+=16;
    startChannel%=511;
}

void DialogAnimator::sliderChanged()
{
    if (targetUniverse == NULL)
        return;
    if (QObject::sender() == ui->verticalSlider_1)
        targetUniverse->setChannel((startChannel)%512,ui->verticalSlider_1->value());
    if (QObject::sender() == ui->verticalSlider_2)
        targetUniverse->setChannel((startChannel+1)%512,ui->verticalSlider_2->value());
    if (QObject::sender() == ui->verticalSlider_3)
        targetUniverse->setChannel((startChannel+2)%512,ui->verticalSlider_3->value());
    if (QObject::sender() == ui->verticalSlider_4)
        targetUniverse->setChannel((startChannel+3)%512,ui->verticalSlider_4->value());
    if (QObject::sender() == ui->verticalSlider_5)
        targetUniverse->setChannel((startChannel+4)%512,ui->verticalSlider_5->value());
    if (QObject::sender() == ui->verticalSlider_6)
        targetUniverse->setChannel((startChannel+5)%512,ui->verticalSlider_6->value());
    if (QObject::sender() == ui->verticalSlider_7)
        targetUniverse->setChannel((startChannel+6)%512,ui->verticalSlider_7->value());
    if (QObject::sender() == ui->verticalSlider_8)
        targetUniverse->setChannel((startChannel+7)%512,ui->verticalSlider_8->value());
    if (QObject::sender() == ui->verticalSlider_9)
        targetUniverse->setChannel((startChannel+8)%512,ui->verticalSlider_9->value());
    if (QObject::sender() == ui->verticalSlider_10)
        targetUniverse->setChannel((startChannel+9)%512,ui->verticalSlider_10->value());
    if (QObject::sender() == ui->verticalSlider_11)
        targetUniverse->setChannel((startChannel+10)%512,ui->verticalSlider_11->value());
    if (QObject::sender() == ui->verticalSlider_12)
        targetUniverse->setChannel((startChannel+11)%512,ui->verticalSlider_12->value());
    if (QObject::sender() == ui->verticalSlider_13)
        targetUniverse->setChannel((startChannel+12)%512,ui->verticalSlider_13->value());
    if (QObject::sender() == ui->verticalSlider_14)
        targetUniverse->setChannel((startChannel+13)%512,ui->verticalSlider_14->value());
    if (QObject::sender() == ui->verticalSlider_15)
        targetUniverse->setChannel((startChannel+14)%512,ui->verticalSlider_15->value());
    if (QObject::sender() == ui->verticalSlider_16)
        targetUniverse->setChannel((startChannel+15)%512,ui->verticalSlider_16->value());
    targetUniverse->sync();
}
