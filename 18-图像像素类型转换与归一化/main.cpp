#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


class QuickDemo {
public:
    void norm_demo(Mat &image) {
        Mat dst;
        std::cout << image.type() << std::endl;
        image.convertTo(image, CV_32F);
        std::cout << image.type() << std::endl;
        normalize(image, dst, 1.0, 0, NORM_MINMAX);
        std::cout << dst.type() << std::endl;
        imshow("图像数据归一化", dst);
        // CV_8UC3, CV_32FC3
    }
};

int main(int argc, char **argv) {
    Mat src = imread(
            "H:\\Applications\\JetBrains\\JetBrains_Documents\\JetBrains_CLionProjects\\git_opencv_report\\xQc.jpg"); //  B, G, R
    if (src.empty()) {
        printf("could not load image....\n");
        return -1;
    }
    // namedWindow("输入窗口", WINDOW_FREERATIO);
    imshow("输入窗口", src);

    QuickDemo qd;
    qd.norm_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
