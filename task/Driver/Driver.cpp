#include "Driver.h"


Driver::Driver() 
{
}

//	Start Reading Threads
void Driver::startReading(Reader * reader) 
{
	reader->readFile();
}

void Driver::Start(string path)
{

	string gpsFile = path + "gps.csv";
	string brakeFile = path + "brake.csv";
	string speedFile = path + "speed.csv";
	string steeringFile = path + "steering.csv";
	string throttleFile = path + "throttle.csv";
	vector <Reader*> files;
	
	//	Images
	for(int i = 0; i < 4; i++){
		string imagePath = path + "3d_images/"+ to_string(i);
		files.push_back(new ImageReader(imagePath));
	}
	
	//	Floats
	files.push_back(new OneValueReader(brakeFile));
	files.push_back(new OneValueReader(speedFile));
	files.push_back(new OneValueReader(steeringFile));
	files.push_back(new OneValueReader(throttleFile));
	
	//	GPS
	files.push_back(new GpsReader(gpsFile));

	// Readers Starter
	vector<thread> readingThreads;
	for(int i = 0; i < (int) files.size(); i++){
		readingThreads.push_back(thread(&Driver::startReading, this, files[i]));	
	}
	
	// Readers Starter
	for(int i = 0; i < (int) files.size(); i++){
		readingThreads[i].join();
	}
}
