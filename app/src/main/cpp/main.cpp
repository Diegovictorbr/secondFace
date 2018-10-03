#include "Detector.h"
#include "Swapper.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	Mat faces = imread("C:\\Users\\Administrador\\Desktop\\Dev\\�reas de conhecimento\\C++\\OpenCV\\Atletas\\DM5_4403.JPG");
	Detector d;
	Swapper s;

	d.setOriginalFrame(faces);
	vector<vector<cv::Point2f>> facialPoints = d.getFacialLandmarks();

	//Checa se existem pontos faciais nos dois vetores de facialPoints
	if (!(facialPoints[0].size() && facialPoints[1].size()))
		system("pause");

	s.setFacialLandmarks(facialPoints);
	s.setOriginalFrame(d.getOriginalFrame());
	s.testes();

	namedWindow("RESULT", WINDOW_FREERATIO);
	imshow("RESULT", s.getSwappedFrame());
	waitKey();

	return 0;
}