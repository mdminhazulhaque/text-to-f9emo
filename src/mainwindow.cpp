/*****************************************************************************
text-to-f9emo, Converts text to facebook emoticons
Copyright (C) 2012 MD: Minhazul Haque;
mdminhazulhaque@gmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cctype>
#include <QDesktopServices>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clipboard = QApplication::clipboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_convert_clicked()
{
    QString *facebook = new QString();
    for(int i=0; ui->input->toPlainText().toAscii()[i]; i++)
        if(isalpha(ui->input->toPlainText().toAscii()[i]))
            facebook->append(QString("[[f9.ch%1]] ").arg(ui->input->toPlainText()[i]));
        else if(isspace(ui->input->toPlainText().toAscii()[i]))
            facebook->append("\n");
        else
            facebook->append(ui->input->toPlainText()[i]);
    ui->output->setPlainText(facebook->toAscii());
    clipboard->setText(facebook->toAscii());
    delete facebook;
}

void MainWindow::on_linkfb_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.facebook.com"));
}

void MainWindow::on_linkfam_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.famoticons.com"));
}

void MainWindow::on_about_clicked()
{
    QMessageBox::information(this, "Version 1.0", "Created by Minhazul Haq, 2012\n<minhazul.haq@gmail.com>\nLicensed under GPLv3");
}
