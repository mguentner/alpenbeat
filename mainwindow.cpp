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
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialoganimator.h"
#include "effectanimator.h"
#include "beateffectanimator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alpenbeat)
{
    ui->setupUi(this);
    m_OlaReceiver.setUniverse(1);
    m_OlaReceiver.connectToUniverse(&m_Universe);
    ui->AlpenBeatGLWidget->connectToUniverse(&m_Universe);
    connect(&m_Universe,SIGNAL(universeUpdated()),&m_OlaReceiver,SLOT(updateReceiver()));
    connect(&m_Universe,SIGNAL(universeUpdated()),ui->AlpenBeatGLWidget,SLOT(updateReceiver()));

    m_OlaReceiver.start();
}

MainWindow::~MainWindow()
{
    m_OlaReceiver.stop();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    DialogAnimator *newDialog = new DialogAnimator(this);
    newDialog->setTargetUniverse(&m_Universe);
    newDialog->deleteLater();
    newDialog->exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    EffectAnimator *newDialog = new EffectAnimator(this);
    newDialog->setTargetUniverse(&m_Universe);
    newDialog->deleteLater();
    newDialog->exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    BeatEffectAnimator *newDialog = new BeatEffectAnimator(this);
    newDialog->setTargetUniverse(&m_Universe);
    newDialog->deleteLater();
    newDialog->exec();
}
