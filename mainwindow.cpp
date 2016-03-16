#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputBrowse_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    QString(),
                                                    "Images (*.png *.jpg)");
    if (fileName.isNull())
        return;

    ui->inputFile->setText(fileName);
}

void MainWindow::on_outputBrowse_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    QString(),
                                                    "PNG Image (*.png)");

    if (fileName.isNull())
        return;

    ui->outputFile->setText(fileName);
}

void MainWindow::on_outputTemplate_toggled(bool checked)
{
    ui->outputFile->setEnabled(!checked);
    ui->outputBrowse->setEnabled(!checked);
}

void MainWindow::on_scaleCustom_toggled(bool checked)
{
    ui->scaleValue->setEnabled(checked);
}

void MainWindow::on_noise_toggled(bool checked)
{
    ui->noiseValue->setEnabled(checked);
}

void MainWindow::on_modelBrowse_clicked()
{
    QString folderName = QFileDialog::getExistingDirectory(
                this, tr("Model Folder"), QString(), "PNG Image (*.png)");

    if (folderName.isNull())
        return;

    ui->modelFolder->setText(folderName);
}
