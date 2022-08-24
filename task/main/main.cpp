#include "task/mainwindow/mainwindow.h"
#include <qt5/QtWidgets/QApplication>
#include "task/Driver/Driver.h"

#include "task/DataStore/DataStore.h"
#include "task/ClockManger/ClockManger.h"

DataStore *
  DataStore::dataStore_ = nullptr;

ClockManger *
  ClockManger::clockManger_ = nullptr;  


void StartDriver(){
}

int main(int argc, char** argv)
{
	Driver * driver = new Driver();
	string path;
	cout << "Data Path: ";
	cin >> path;
	
	// My path:
	//	/home/ahmad/Desktop/sample_trip/

	thread driverTH(&Driver::Start,driver,path);

	//	UI Starter
	QApplication a(argc, argv);
	MainWindow w;	
	w.show();
	a.exec();
	abort();
	driverTH.join();
	return 0;
}
