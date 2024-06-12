#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


class QuickDemo {
public:
    void histogram_2d_demo(Mat &image) {
        // 2D 直方图
        Mat hsv, hs_hist;
        cvtColor(image, hsv, COLOR_BGR2HSV);
        int hbins = 30, sbins = 32;
        int hist_bins[] = { hbins, sbins };
        float h_range[] = { 0, 180 };
        float s_range[] = { 0, 256 };
        const float* hs_ranges[] = { h_range, s_range };
        int hs_channels[] = { 0, 1 };
        calcHist(&hsv, 1, hs_channels, Mat(), hs_hist, 2, hist_bins, hs_ranges, true, false);
        double maxVal = 0;
        minMaxLoc(hs_hist, 0, &maxVal, 0, 0);
        int scale = 10;
        Mat hist2d_image = Mat::zeros(sbins*scale, hbins * scale, CV_8UC3);
        for (int h = 0; h < hbins; h++) {
            for (int s = 0; s < sbins; s++)
            {
                float binVal = hs_hist.at<float>(h, s);
                int intensity = cvRound(binVal * 255 / maxVal);
                rectangle(hist2d_image, Point(h*scale, s*scale),
                          Point((h + 1)*scale - 1, (s + 1)*scale - 1),
                          Scalar::all(intensity),
                          -1);
            }
        }
        applyColorMap(hist2d_image, hist2d_image, COLORMAP_JET);
        imshow("H-S Histogram", hist2d_image);
        imwrite("D:/hist_2d.png", hist2d_image);
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
    qd.histogram_2d_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
