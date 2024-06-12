#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void pixel_statistic_demo(Mat &image) {
        double minv, maxv;
        Point minLoc, maxLoc;
        std::vector<Mat> mv;
        split(image, mv);
        for (int i = 0; i < mv.size(); i++) {
            minMaxLoc(mv[i], &minv, &maxv, &minLoc, &maxLoc, Mat());
            std::cout <<"No. channels:"<< i << " min value:" << minv << " max value:" << maxv << std::endl;
        }
        Mat mean, stddev;
        Mat redback = Mat::zeros(image.size(), image.type());
        redback = Scalar(40, 40, 200);
        meanStdDev(redback, mean, stddev);
        imshow("redback", redback);
        std::cout << "means:" << mean << std::endl;
        std::cout<< " stddev:" << stddev << std::endl;
    }
};

int main(int argc, char **argv) {
    Mat src = imread("H:\\Applications\\JetBrains\\JetBrains_Documents\\JetBrains_CLionProjects\\git_opencv_report\\xQc.jpg"); //  B, G, R
    if (src.empty()) {
        printf("could not load image....\n");
        return -1;
    }
    // namedWindow("输入窗口", WINDOW_FREERATIO);
    imshow("输入窗口", src);

    QuickDemo qd;
    qd.pixel_statistic_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
