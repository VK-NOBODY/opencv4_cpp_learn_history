#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


class QuickDemo {
public:
    void histogram_demo(Mat &image) {
        // ��ͨ������
        std::vector<Mat> bgr_plane;
        split(image, bgr_plane);
        // �����������
        const int channels[1] = { 0 };
        const int bins[1] = { 256 };
        float hranges[2] = { 0,255 };
        const float* ranges[1] = { hranges };
        Mat b_hist;
        Mat g_hist;
        Mat r_hist;
        // ����Blue, Green, Redͨ����ֱ��ͼ
        calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
        calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
        calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);

        // ��ʾֱ��ͼ
        int hist_w = 512;
        int hist_h = 400;
        int bin_w = cvRound((double)hist_w / bins[0]);
        Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
        // ��һ��ֱ��ͼ����
        normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
        normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
        normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
        // ����ֱ��ͼ����
        for (int i = 1; i < bins[0]; i++) {
            line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
                 Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
            line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
                 Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, 8, 0);
            line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
                 Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
        }
        // ��ʾֱ��ͼ
        namedWindow("Histogram Demo", WINDOW_AUTOSIZE);
        imshow("Histogram Demo", histImage);
    }
};

int main(int argc, char **argv) {
    Mat src = imread(
            "H:\\Applications\\JetBrains\\JetBrains_Documents\\JetBrains_CLionProjects\\git_opencv_report\\xQc.jpg"); //  B, G, R
    if (src.empty()) {
        printf("could not load image....\n");
        return -1;
    }
    // namedWindow("���봰��", WINDOW_FREERATIO);
    imshow("���봰��", src);

    QuickDemo qd;
    qd.histogram_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
