// Binarize class is a template class. Template's params are 'a used binarization algorithnm' and 'data format'
// When an instance of the class is being constructed cv::Mat structure for an image is being created
// Then method 'binorize' makes binarization using corresponding algorithn
//
// Date: 06.06.2018
// Name: Vasily Petrov

#include <vector>
#include <utility>
#include <opencv2/core/mat.hpp>
#include "BinarizeAlgorithm.h"


template <class BinarizeAlgorithm, typename T /*data format*/>
class Binarizer {
    Binarizer() = delete;
    Binarizer(const Binarizer&) = delete;
    Binarizer(Binarizer&&) = delete;
    operator = (const Binarizer&) = delete;
    operator = (Binarizer&&) = delete;

    T&& binarize(){}
};

// implementations of different partial specializations for different types of data
template <class BinarizeAlgorithm>
class Binarizer<BinarizeAlgorithm, char*> {
    cv::Mat mImage;

public:
    Binarizer (const char* image) : mImage() {} // TODO: construct cv::Mat from image. Not implemented yet.
    cv::Mat&& binarize() {
        return BinarizeAlgorithm::binarize(mImage); 
    }
};

template <class BinarizeAlgorithm>
class Binarizer<BinarizeAlgorithm, std::vector<char>> {
    cv::Mat mImage;

public:
    Binarizer (const std::vector<char>& image) : mImage() {} // TODO: constrict Mat from image. Not implemented yet.
    std::vector<char>&& binarize() {
        return BinarizeAlgorithm::binarize(mImage);
    }
};

template <class BinarizeAlgorithm>
class Binarizer<BinarizeAlgorithm, cv::Mat> {
    const cv::Mat& mImage;

public:
    Binarizer (const cv::Mat& image) : mImage(image) {}
    cv::Mat&& binarize() {
        return BinarizeAlgorithm::binarize(mImage);
    }
};