#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void polyline_drawing_demo() {
        Mat canvas = Mat::zeros(Size(512, 512), CV_8UC3);
        int w = canvas.cols;
        int h = canvas.rows;
        Point p1(100, 100);
        Point p2(300, 150);
        Point p3(300, 350);
        Point p4(250, 450);
        Point p5(50, 450);
        std::vector<Point> pts;
        pts.push_back(p1);
        pts.push_back(p2);
        pts.push_back(p3);
        pts.push_back(p3);
        pts.push_back(p4);
        pts.push_back(p5);
        // polylines(canvas, pts, true, Scalar(0, 255, 0), -1, 8, 0);
        std::vector<std::vector<Point>> contours;
        contours.push_back(pts);
        drawContours(canvas, contours, 0, Scalar(0, 0, 255), -1, 8);
        imshow("绘制多边形", canvas);
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
    qd.polyline_drawing_demo();

    waitKey(0);
    destroyAllWindows();
    return 0;
}
