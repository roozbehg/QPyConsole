#include "mainwindow.h"
#include "qpconsole.h"
#include <QDebug>
#include "pywrapper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->setWindowTitle("QPyConsole By Roozbeh Geraili Mikola");

    textEdit = new QPConsole();
    console = new pyWrapper();

    setCentralWidget(textEdit);

    connect(textEdit, SIGNAL(command(QString)), this, SLOT(handleCommand(QString)));
}

MainWindow::~MainWindow() {
}

void MainWindow::handleCommand(QString cmd) {
    //qDebug() << "Current cmd is: " << cmd;

    QString output = console->pyRun(cmd);
    if (output!="")
    {
        textEdit->print(output);
    }

    //textEdit->print(cmd);

    textEdit->prepareCommandLine();
}

