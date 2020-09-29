#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPConsole;
class pyWrapper;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
  void handleCommand(QString);

private:
  QPConsole *textEdit;
  pyWrapper* console;
};
#endif // MAINWINDOW_H
