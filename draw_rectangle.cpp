#include"iostream"

#include"opencv2/opencv.hpp"
#include"vector"
#include<math.h>

using namespace cv;
int main()
{
	Mat url, gray, detected;
	vector<Rect> ladysfingers;
	Point pt1, pt2;
	
	CascadeClassifier ladysfinger("cascade.xml");
	if (!ladysfinger.load("cascade.xml"))
	{
		printf("Error loading cascade file for face");
		return 1;
	}
	
	while (1)
	{
		VideoCapture cap("http://192.168.0.102:8080/shot.jpg");
	
		cap >> url;
		cvtColor(url, gray, COLOR_BGR2GRAY);
		ladysfinger.detectMultiScale(gray, ladysfingers,1.1,3);
		for (int i = 0; i < ladysfingers.size(); i++)
		{
			Point pt1(ladysfingers[i].x, ladysfingers[i].y);
			Point pt2(ladysfingers[i].x + ladysfingers[i].width, ladysfingers[i].y + ladysfingers[i].height);
			rectangle(url, ladysfingers[i], cvScalar(0, 255, 0),2);
		}
		
		imshow("webimage", url);
		waitKey(1);
	
	}

	return 0;

}

