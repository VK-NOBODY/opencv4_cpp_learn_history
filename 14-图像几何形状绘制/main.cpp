#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void drawing_demo(Mat &image) {
        Rect rect;
        rect.x = 100;
        rect.y = 100;
        rect.width = 250;
        rect.height = 300;
        Mat bg = Mat::zeros(image.size(), image.type());
        rectangle(bg, rect, Scalar(0, 0, 255), -1, 8, 0);
        circle(bg, Point(350, 400), 15, Scalar(255, 0, 0), -1, 8, 0);
        line(bg, Point(100, 100), Point(350, 400), Scalar(0, 255, 0), 4, LINE_AA, 0);
        RotatedRect rrt;
        rrt.center = Point(200, 200);
        rrt.size = Size(100, 200);
        rrt.angle = 90.0;
        ellipse(bg, rrt, Scalar(0, 255, 255), 2, 8);
        Mat dst;
        addWeighted(image, 0.7, bg, 0.3, 0, dst);
        imshow("绘制演示", bg);
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
    qd.drawing_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
