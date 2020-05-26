// Application that asks input file name and write result to the other file
//
// Date: 03.06.2018
// Name: Vasily Petrov

#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "BinarizerLib/Binarizer.h"

using namespace std;
// using namespace cv - I don't use it in this file. I want to understand namespace

int main(int argc, char* argv[]) {
    cv::Mat image = cv::imread("..\\image.jpg");

    Binarizer<BinarizeAlgorithm<Bernsen>, cv::Mat> binarizer(image);

    cv::Mat&& binarizedImage = binarizer.binarize();

    vector<int> params;
    params.push_back(IMWRITE_PNG_COMPRESSION);
    params.push_back(9); // make maximum compression
    cv::imwrite(cv::String("..\\image_output.jpg"), binarizedImage, params);

	return 0;
}
