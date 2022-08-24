#include "task/mainwindow/mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  ui.setupUi(this);
 
  qTimer = new QTimer(this);
  connect(qTimer,SIGNAL(timeout()),this,SLOT(changeFrame()));
  qTimer->start(0);
}

void MainWindow::changeFrame(){
  Mat frontImage;
  Mat backImage;
  Mat rightImage;
  Mat leftImage;

  DataStore * dataStore = DataStore::getInstance();

  // Get Images
  Types allData; 
  frontImage = dataStore->getAllData().getFrontImage();
  backImage = dataStore->getAllData().getBackImage();
  rightImage = dataStore->getAllData().getRightImage();
  leftImage = dataStore->getAllData().getLeftImage();
  

  // Set Images to be displayed
  QImage front(frontImage.data, frontImage.cols, frontImage.rows, frontImage.step,  QImage::Format_RGB888);
  QImage back(backImage.data, backImage.cols, backImage.rows, backImage.step, QImage::Format_RGB888);
  QImage left(leftImage.data, leftImage.cols, leftImage.rows, leftImage.step, QImage::Format_RGB888);
  QImage right(rightImage.data, rightImage.cols, rightImage.rows, rightImage.step, QImage::Format_RGB888);
  
  ui.FrontCamera->setPixmap(QPixmap::fromImage(front));
  ui.FrontCamera->setScaledContents( true );
  ui.FrontCamera->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored);

  ui.BackCamera->setPixmap(QPixmap::fromImage(back));
  ui.BackCamera->setScaledContents( true );
  ui.BackCamera->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored);

  ui.LeftCamera->setPixmap(QPixmap::fromImage(left));
  ui.LeftCamera->setScaledContents( true );
  ui.LeftCamera->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored);

  ui.RightCamera->setPixmap(QPixmap::fromImage(right));
  ui.RightCamera->setScaledContents( true );
  ui.RightCamera->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored);

  // Set float Data to be displayed
  ui.Speed->setDigitCount(8);
  ui.Speed->display(QString::number(dataStore->getAllData().getSpeed()).mid(0,5));

  ui.Brake->setDigitCount(8);  
  ui.Brake->display(QString::number(dataStore->getAllData().getBrake()).mid(0,5));
  
  ui.Throttle->setDigitCount(8);
  ui.Throttle->display(QString::number(dataStore->getAllData().getThrottle()).mid(0,5));
  
  ui.Steering->setDigitCount(8);
  ui.Steering->display(QString::number(dataStore->getAllData().getSteering()).mid(0,4));

  QString first = QString::number(dataStore->getAllData().getLocation().first,'g',8);
  QString second = QString::number(dataStore->getAllData().getLocation().second,'g',8);
  ui.Location->setText("   Location is = \n   " + first + " , " + second );
}