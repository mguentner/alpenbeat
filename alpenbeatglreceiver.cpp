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
#include "alpenbeatglreceiver.h"
#include <QtOpenGL>
#include <GL/glu.h>
AlpenbeatGLReceiver::AlpenbeatGLReceiver(QWidget *parent) :
    QGLWidget(parent), Receiver()
{
    m_Colors.resize(4);
}

void AlpenbeatGLReceiver::updateReceiver()
{
    for (uint8_t i=0; i<4; i++) {
        m_Colors.replace(i,QColor(m_connectedUniverse->getChannel(0+3*i),
                                  m_connectedUniverse->getChannel(1+3*i),
                                  m_connectedUniverse->getChannel(2+3*i)));
    }
    updateGL();
}

bool AlpenbeatGLReceiver::start()
{
    return true;
}
bool AlpenbeatGLReceiver::stop()
{
    return true;
}
void AlpenbeatGLReceiver::initProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, (GLfloat) width()/(GLfloat) height(), 0.1, 500.0);
    glMatrixMode(GL_MODELVIEW);
}
void AlpenbeatGLReceiver::resizeGL()
{
    initProjection();
}
void AlpenbeatGLReceiver::drawCube(QVector3D translate, QVector3D scale, QColor color)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(translate.x(),translate.y(),translate.z());
    glScalef(scale.x(),scale.y(),scale.z());
    glBegin(GL_QUADS);
    {
        glColor3f(color.redF(),color.greenF(),color.blueF());
        glVertex3f( 1.0f, 1.0f,-1.0f);
        glVertex3f(-1.0f, 1.0f,-1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f, 1.0f, 1.0f);
        //
        glVertex3f( 1.0f,-1.0f, 1.0f);
        glVertex3f(-1.0f,-1.0f, 1.0f);
        glVertex3f(-1.0f,-1.0f,-1.0f);
        glVertex3f( 1.0f,-1.0f,-1.0f);
        //
        glVertex3f( 1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f,-1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f, 1.0f);
        //
        glVertex3f( 1.0f,-1.0f,-1.0f);
        glVertex3f(-1.0f,-1.0f,-1.0f);
        glVertex3f(-1.0f, 1.0f,-1.0f);
        glVertex3f( 1.0f, 1.0f,-1.0f);
        //
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f,-1.0f);
        glVertex3f(-1.0f,-1.0f,-1.0f);
        glVertex3f(-1.0f,-1.0f, 1.0f);
        //
        glVertex3f( 1.0f, 1.0f,-1.0f);
        glVertex3f( 1.0f, 1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f, 1.0f);
        glVertex3f( 1.0f,-1.0f,-1.0f);
    }
    glEnd();
    glPopMatrix();

}
#define EXPEDIT_SMALLCUBE_X 33.5
#define EXPEDIT_SMALLCUBE_Y 33.5
#define EXPEDIT_SMALLCUBE_Z 39
#define EXPEDIT_SMALLCUBE_MARGIN 0.75
#define EXPEDIT_BIGCUBE_MARGIN 5

#define EXPEDIT_WIDTH (EXPEDIT_SMALLCUBE_X+EXPEDIT_SMALLCUBE_MARGIN+EXPEDIT_BIGCUBE_MARGIN)*2

void AlpenbeatGLReceiver::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(15,1,0,0);
    glRotatef(40,0,1,0);
    glTranslated(120,-40,-150);
    //Cube 1, upper left
    drawCube(QVector3D(-EXPEDIT_SMALLCUBE_X-EXPEDIT_SMALLCUBE_MARGIN,EXPEDIT_SMALLCUBE_Y+EXPEDIT_SMALLCUBE_MARGIN,0),
             QVector3D(EXPEDIT_SMALLCUBE_X,EXPEDIT_SMALLCUBE_Y,EXPEDIT_SMALLCUBE_Z),m_Colors[0]);
    //Cube 2, upper right
    drawCube(QVector3D(EXPEDIT_SMALLCUBE_X+EXPEDIT_SMALLCUBE_MARGIN,EXPEDIT_SMALLCUBE_Y+EXPEDIT_SMALLCUBE_MARGIN,0),
             QVector3D(EXPEDIT_SMALLCUBE_X,EXPEDIT_SMALLCUBE_Y,EXPEDIT_SMALLCUBE_Z),m_Colors[1]);
    //Cube 3, lower right
    drawCube(QVector3D(EXPEDIT_SMALLCUBE_X+EXPEDIT_SMALLCUBE_MARGIN,-EXPEDIT_SMALLCUBE_Y-EXPEDIT_SMALLCUBE_MARGIN,0),
             QVector3D(EXPEDIT_SMALLCUBE_X,EXPEDIT_SMALLCUBE_Y,EXPEDIT_SMALLCUBE_Z),m_Colors[2]);
    //Cube 4, lower left
    drawCube(QVector3D(-EXPEDIT_SMALLCUBE_X-EXPEDIT_SMALLCUBE_MARGIN,-EXPEDIT_SMALLCUBE_Y-EXPEDIT_SMALLCUBE_MARGIN,0),
             QVector3D(EXPEDIT_SMALLCUBE_X,EXPEDIT_SMALLCUBE_Y,EXPEDIT_SMALLCUBE_Z),m_Colors[3]);
    //Cube 5, horizontal margin
    drawCube(QVector3D(0,0,0),
             QVector3D(EXPEDIT_SMALLCUBE_MARGIN+EXPEDIT_SMALLCUBE_X*2,EXPEDIT_SMALLCUBE_MARGIN,EXPEDIT_SMALLCUBE_Z),Qt::white);
    //Cube 6, vertical margin
    drawCube(QVector3D(0,0,0),
             QVector3D(EXPEDIT_SMALLCUBE_MARGIN,EXPEDIT_SMALLCUBE_MARGIN+EXPEDIT_SMALLCUBE_Y*2,EXPEDIT_SMALLCUBE_Z),Qt::white);
    //Cube 7, upper body
    drawCube(QVector3D(0,(EXPEDIT_SMALLCUBE_Y+EXPEDIT_SMALLCUBE_MARGIN)*2+EXPEDIT_BIGCUBE_MARGIN,0),
             QVector3D(EXPEDIT_WIDTH,EXPEDIT_BIGCUBE_MARGIN,EXPEDIT_SMALLCUBE_Z),Qt::white);
    //Cube 8, lower body
    drawCube(QVector3D(0,-(EXPEDIT_SMALLCUBE_Y+EXPEDIT_SMALLCUBE_MARGIN)*2-EXPEDIT_BIGCUBE_MARGIN,0),
             QVector3D(EXPEDIT_WIDTH,EXPEDIT_BIGCUBE_MARGIN,EXPEDIT_SMALLCUBE_Z),Qt::white);
    //Cube 9, right body
    drawCube(QVector3D((EXPEDIT_SMALLCUBE_X+EXPEDIT_SMALLCUBE_MARGIN)*2+EXPEDIT_BIGCUBE_MARGIN,0,0),
             QVector3D(EXPEDIT_BIGCUBE_MARGIN,(EXPEDIT_SMALLCUBE_Y+EXPEDIT_SMALLCUBE_MARGIN)*2,EXPEDIT_SMALLCUBE_Z),Qt::white);
    //Cube 10, left body
    drawCube(QVector3D(-(EXPEDIT_SMALLCUBE_X+EXPEDIT_SMALLCUBE_MARGIN)*2-EXPEDIT_BIGCUBE_MARGIN,0,0),
             QVector3D(EXPEDIT_BIGCUBE_MARGIN,(EXPEDIT_SMALLCUBE_Y+EXPEDIT_SMALLCUBE_MARGIN)*2,EXPEDIT_SMALLCUBE_Z),Qt::white);
    glFlush();
}

void AlpenbeatGLReceiver::initializeGL()
{
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.1,0.1,0.1,0.3);
    glCullFace(GL_FRONT);
    initProjection();
}

