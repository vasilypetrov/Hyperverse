// Algorithms of binarization (I don't want to implement some special algorithms like Bernsen. I have no time.
// I implement some simple algorithm like Bernsen's algo)
//
//
// Date: 06.06.2018
// Name: Vasily Petrov

#include <opencv/highgui.h>
#include <opencv2/core/mat.hpp>


// ALGORITHMS
#define Bernsen 0
// For this task I implement only one algorithm

using namespace cv;

template <int ALGORITHM>
class BinarizeAlgorithm {
public:
    static cv::Mat&& binarize(const cv::Mat& image);
};

#include <iostream>
using namespace std;
template <>
class BinarizeAlgorithm<Bernsen> {
public:
    static cv::Mat&& binarize(const cv::Mat& image) {
        // Of course it's not readl Bernsen algorithm. It's very simple approach to it
        cv::Mat binarizedImage(image.rows, image.cols, image.type());
        for (auto x = 0; x < image.rows; ++x)
            for (auto y = 0; y < image.cols; ++y) {
                const Vec3b color = image.at<Vec3b>(x, y); 
                const uchar blue = color.val[0];
                const uchar green = color.val[1];
                const uchar red = color.val[2];
                binarizedImage.at<uchar>(x, y) = (blue + green + red > 0xFF*3/2)? 1 : 0;
            }
        return std::move(binarizedImage);
    }
};