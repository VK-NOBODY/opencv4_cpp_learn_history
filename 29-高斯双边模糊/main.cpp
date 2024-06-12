#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


class QuickDemo {
public:
    void bifilter_demo(Mat &image) {
        Mat dst;
        bilateralFilter(image, dst, 0, 100, 10);
        imshow("双边模糊", dst);
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
    qd.bifilter_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
