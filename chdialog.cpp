/*
 *  This file is part of Check Hash software program
 *	name of file: chdialog.cpp
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

#include "chdialog.h"
#include "ui_chdialog.h"

// constructor
CHDialog::CHDialog(QWidget *parent) : QDialog(parent), ui(new Ui::CHDialog)
{
    ui->setupUi(this);

    pro = new QProcess(this);

    // readyRead() update itself automatically - a kind of recursion
    connect(pro,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(pro, SIGNAL(started()), this, SLOT(processStarted()));

    this->setMaximumSize(590, 461);
    this->setMinimumSize(590, 461);

    this->setWindowIcon(QIcon(":/icons/ch24.png"));

    this->setWindowTitle("Check Hash");

    ui->label->setText(tr("txt file: "));
    ui->pushButton->setText(tr("Choose &file"));

    ui->label_2->setText(tr("The txt hashs file needs to be in a folder with the iso file to be checked!"));
    ui->pushButton_2->setText(tr("Check &Hash!"));

    ui->textEdit->setReadOnly(true);
    ui->label_3->setText(tr("Check above the output and if you read: 'OK' in the output, congratulations!"));

    ui->pushButton_3->setText(tr("&About"));
    ui->pushButton_4->setText(tr("&Close"));
}

// destructor
CHDialog::~CHDialog()
{
    delete ui;
}

// About button
void CHDialog::on_pushButton_3_clicked()
{
    CHCreditsDialog *chd = new CHCreditsDialog;
    chd->setModal(true);
    chd->exec();
}

// Close button
void CHDialog::on_pushButton_4_clicked()
{
    exit(0);
}

// Choose file button
void CHDialog::on_pushButton_clicked()
{
    // the path need to change
    // currently the program only checks,
    // if the iso file, the txt file and program executable are in same folder
    QString txtfile = QFileDialog::getOpenFileName(this, tr("Open txt file"),"/$HOME/$PATH","*.txt");
    if (!txtfile.isEmpty())
    {
        ui->lineEdit->setText(txtfile);
    }
}

// readyRead method
void CHDialog::readyRead()
{
    /*
     *  QByteArray QProcess::readAllStandardOutput()
     *  Regardless of the current read channel,
     *  this function returns all data available from
     *  the standard output of the process as a QByteArray.
    */
    string_output.append(pro->readAllStandardOutput());
    ui->textEdit->setText(string_output);

    // sets a vertical scroll bar in the textEdit
    ui->textEdit->verticalScrollBar()->setSliderPosition(ui->textEdit->verticalScrollBar()->maximum());
}

// Debuging
void CHDialog::processStarted()
{
    qDebug() << "on_pushButton_2_clicked()";
}

// Check Hash! button
void CHDialog::on_pushButton_2_clicked()
{
    QString program = "sha1sum";
    QStringList arguments;
    QString inp = ui->lineEdit->text();
    if(inp.isEmpty())
    {
        // Debugging
        qDebug() << "No input txt file!";
        QMessageBox::warning(this, tr("No input txt file!"), tr("Please insert a txt file containning hashs!"));
        return;
    }

    arguments << "-c" << inp;

    // Debugging
    qDebug() << arguments;

    /*
     * QProcess merges the output of the running process into the standard output channel (stdout).
     * The standard error channel (stderr) will not receive any data.
     * The standard output and standard error data of the running process are interleaved.
    */
    pro->setProcessChannelMode(QProcess::MergedChannels);
    pro->start(program, arguments);
}
