#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    static void on_lightness(int b, void* userdata) {
        Mat image = *((Mat*)userdata);
        Mat dst = Mat::zeros(image.size(), image.type());
        Mat m = Mat::zeros(image.size(), image.type());
        addWeighted(image, 1.0, m, 0, b, dst);
        imshow("亮度与对比度调整", dst);
    }

    static void on_contrast(int b, void* userdata) {
        Mat image = *((Mat*)userdata);
        Mat dst = Mat::zeros(image.size(), image.type());
        Mat m = Mat::zeros(image.size(), image.type());
        double contrast = b / 100.0;
        addWeighted(image, contrast, m, 0.0, 0, dst);
        imshow("亮度与对比度调整", dst);
    }

    void tracking_bar_demo(Mat &image) {
        namedWindow("亮度与对比度调整", WINDOW_AUTOSIZE);
        int lightness = 50;
        int max_value = 100;
        int contrast_value = 100;
        createTrackbar("Value Bar:", "亮度与对比度调整", &lightness, max_value, on_lightness, (void*) (&image));
        createTrackbar("Contrast Bar:", "亮度与对比度调整", &contrast_value, 200, on_contrast, (void*)(&image));
        on_lightness(50, &image);
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
    qd.tracking_bar_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
