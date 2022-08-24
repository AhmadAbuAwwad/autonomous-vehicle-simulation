#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qt5/QtCore/QObject>
#include <qt5/QtWidgets/QMainWindow>

#include "task/mainwindow/ui_mainwindow.h"

#include "task/DataStore/DataStore.h"

#include <qt5/QtCore/QTimer>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  QTimer * qTimer;

public slots:
  void changeFrame();

private:
  Ui::MainWindow ui;
};

#endif // MAINWINDOW_H
