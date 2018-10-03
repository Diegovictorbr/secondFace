#include <jni.h>
#include "Detector.h"

Detector::Detector(jbyte *data) {
//    dlib::deserialize("dg") >> spredictor;
}

Detector::~Detector() {
    faces.clear();
    shapes.clear();
}

void Detector::detectFacesAndShapes() {
    shapes.clear();
    faces = faceDetector(dlibFrame);

    if (faces.size() < 2)
        return;

    for (int i = 0; i < 2; i++)
        shapes.push_back(spredictor(dlibFrame, faces[i]));
}

//Retorna os pontos faciais dos dois primeiros rostos da imagem
vector<vector<Point2f>> Detector::getFacialLandmarks() {
    detectFacesAndShapes();

    vector<vector<Point2f>> facialLandmarks(2);

    if (!shapes.size())
        return facialLandmarks;

    Mat aux = originalFrame.clone();

    for (int i = 0; i < 2; i++)
        for (int j = 27; j < 36; j++)
            facialLandmarks[i].push_back(Point2f(shapes[i].part(j).x(), shapes[i].part(j).y()));

    for (int i = 0; i < 2; i++)
        for (int j = 27; j < 29; j++)
            facialLandmarks[i].push_back(Point2f(shapes[i].part(21).x(), shapes[i].part(j).y()));

    for (int i = 0; i < 2; i++)
        for (int j = 27; j < 29; j++)
            facialLandmarks[i].push_back(Point2f(shapes[i].part(22).x(), shapes[i].part(j).y()));

    for (int j = 0; j < facialLandmarks.size(); j++)
        facialLandmarks[j].push_back(Point2f(shapes[j].part(31).x(), shapes[j].part(29).y()));

    for (int j = 0; j < facialLandmarks.size(); j++)
        facialLandmarks[j].push_back(Point2f(shapes[j].part(35).x(), shapes[j].part(29).y()));

    for (int j = 0; j < facialLandmarks.size(); j++)
        facialLandmarks[j].push_back(Point2f(shapes[j].part(40).x(), shapes[j].part(30).y()));

    for (int j = 0; j < facialLandmarks.size(); j++)
        facialLandmarks[j].push_back(Point2f(shapes[j].part(47).x(), shapes[j].part(30).y()));

    for (int j = 0; j < facialLandmarks.size(); j++)
        facialLandmarks[j].push_back(Point2f(shapes[j].part(39).x(), shapes[j].part(33).y()));

    for (int j = 0; j < facialLandmarks.size(); j++)
        facialLandmarks[j].push_back(Point2f(shapes[j].part(42).x(), shapes[j].part(33).y()));

    for (int i = 27; i < 36; i++)
        for (int j = 0; j < facialLandmarks.size(); j++)
            circle(aux, Point2f(shapes[j].part(i).x(), shapes[j].part(i).y()), 1,
                   Scalar(200, 50, 10), 2);

    for (int i = 27; i < 29; i++)
        for (int j = 0; j < facialLandmarks.size(); j++)
            circle(aux, Point2f(shapes[j].part(21).x(), shapes[j].part(i).y()), 1,
                   Scalar(200, 50, 10), 2);

    for (int i = 27; i < 29; i++)
        for (int j = 0; j < facialLandmarks.size(); j++)
            circle(aux, Point2f(shapes[j].part(22).x(), shapes[j].part(i).y()), 1,
                   Scalar(200, 50, 10), 2);

    for (int j = 0; j < facialLandmarks.size(); j++)
        circle(aux, Point2f(shapes[j].part(31).x(), shapes[j].part(29).y()), 1, Scalar(200, 50, 10),
               2);

    for (int j = 0; j < facialLandmarks.size(); j++)
        circle(aux, Point2f(shapes[j].part(35).x(), shapes[j].part(29).y()), 1, Scalar(200, 50, 10),
               2);

    for (int j = 0; j < facialLandmarks.size(); j++)
        circle(aux, Point2f(shapes[j].part(39).x(), shapes[j].part(33).y()), 1, Scalar(200, 50, 10),
               2);

    for (int j = 0; j < facialLandmarks.size(); j++)
        circle(aux, Point2f(shapes[j].part(42).x(), shapes[j].part(33).y()), 1, Scalar(200, 50, 10),
               2);

    for (int j = 0; j < facialLandmarks.size(); j++)
        circle(aux, Point2f(shapes[j].part(40).x(), shapes[j].part(30).y()), 1, Scalar(200, 50, 10),
               2);

    for (int j = 0; j < facialLandmarks.size(); j++)
        circle(aux, Point2f(shapes[j].part(47).x(), shapes[j].part(30).y()), 1, Scalar(200, 50, 10),
               2);

    namedWindow("AUX", WINDOW_FREERATIO);
    imshow("AUX", aux);
    waitKey();

    return facialLandmarks;
}

Mat Detector::getOriginalFrame() {
    return originalFrame;
}

void Detector::setOriginalFrame(Mat of) {
    originalFrame = of.clone();
    dlibFrame = originalFrame;
}