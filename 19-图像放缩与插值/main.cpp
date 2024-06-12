#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


class QuickDemo {
public:
    void resize_demo(Mat &image) {
        Mat zoomin, zoomout;
        int h = image.rows;
        int w = image.cols;
        resize(image, zoomin, Size(w / 2, h / 2), 0, 0, INTER_LINEAR);
        imshow("zoomin", zoomin);
        resize(image, zoomout, Size(w * 1.5, h * 1.5), 0, 0, INTER_LINEAR);
        imshow("zoomout", zoomout);
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
    qd.resize_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
