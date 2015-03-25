/*
 *  This file is part of Check Hash software program
 *	name of file: chcreditsdialog.cpp
 *
 *	Copyright (C) 2014 2015 Filipe Marques <eagle.software3@gmail.com>
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

#include "inc/chcreditsdialog.h"
#include "ui_chcreditsdialog.h"

// constructor
CHCreditsDialog::CHCreditsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::CHCreditsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("About Check Hash");

    this->setMaximumSize(487, 296);
    this->setMinimumSize(487, 296);

    this->setWindowIcon(QIcon(":/icons/ch24.png"));

    ui->label_5->setPixmap(QPixmap(":/icons/ch128.png"));

    ui->label->setText("Check Hash version 1.0.2");
    ui->label_2->setText("Copyright (C) 2014 2015 - Filipe Marques");

    ui->label_4->setOpenExternalLinks(true);
    ui->label_4->setTextFormat(Qt::RichText);
    ui->label_4->setText(trUtf8("This software program is licensed under <a href=\"http://www.gnu.org/licenses/gpl-3.0.html\">GNU GPL version 3</a>"));

    ui->label_3->setOpenExternalLinks(true);
    ui->label_3->setTextFormat(Qt::RichText);
    ui->label_3->setText("The project site is in <a href=\"https://www.github.com/filipe-marques/check-hash\">https://www.github.com/filipe-marques/check-hash</a>");

    ui->pushButton->setText(trUtf8("&Close"));
}

// destructor
CHCreditsDialog::~CHCreditsDialog()
{
    delete ui;
}

// Close button
void CHCreditsDialog::on_pushButton_clicked()
{
    this->close();
}
