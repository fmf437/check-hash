/*
 *  This file is part of Check Hash software program
 *	name of file: chdialog.h
 *
 *	Copyright (C) 2014 Filipe Marques <eagle.software3@gmail.com>
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 3 of the License, or
 *	any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You received a copy of the GNU General Public License
 *	along with this program in License folder; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *	MA 02110-1301, USA.
 *
*/

#ifndef CHDIALOG_H
#define CHDIALOG_H

#include <QDialog>

#include <QProcess>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QScrollBar>

#include <QDebug>

#include "chcreditsdialog.h"

namespace Ui {
class CHDialog;
}

class CHDialog : public QDialog
{
    Q_OBJECT

public:
    // constructor
    explicit CHDialog(QWidget *parent = 0);

    // destructor
    ~CHDialog();

private slots:
    // Close button
    void on_pushButton_3_clicked();
    // Credits button
    void on_pushButton_4_clicked();
    // Choose file button
    void on_pushButton_clicked();

    // readyRead method
    void readyRead();

    // Debuging
    void processStarted();

    // Checked Hash! button
    void on_pushButton_2_clicked();

private:
    Ui::CHDialog *ui;

    QProcess *pro;
    QString string_output;
};

#endif // CHDIALOG_H
