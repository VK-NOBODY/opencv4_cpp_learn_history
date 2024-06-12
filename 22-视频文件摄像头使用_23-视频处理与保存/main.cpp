#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


class QuickDemo {
public:
    void colorSpace_Demo(Mat &image) {
        Mat gray, hsv;
        cvtColor(image, hsv, COLOR_BGR2HSV);
        // H 0 ~ 180, S, V
        cvtColor(image, gray, COLOR_BGR2GRAY);
        imshow("HSV", hsv);
        imshow("灰度", gray);
        // imwrite("D:/hsv.png", hsv);
        // imwrite("D:/gray.png", gray);
    }

    void video_demo(Mat &image) {
        VideoCapture capture("D:/images/video/example_dsh.mp4");
        int frame_width = capture.get(CAP_PROP_FRAME_WIDTH);
        int frame_height = capture.get(CAP_PROP_FRAME_HEIGHT);
        int count = capture.get(CAP_PROP_FRAME_COUNT);
        double fps = capture.get(CAP_PROP_FPS);
        std::cout << "frame width:" << frame_width << std::endl;
        std::cout << "frame height:" << frame_height << std::endl;
        std::cout << "FPS:" << fps << std::endl;
        std::cout << "Number of Frames:" << count << std::endl;
        VideoWriter writer("D:/test.mp4", capture.get(CAP_PROP_FOURCC), fps, Size(frame_width, frame_height), true);
        Mat frame;
        while (true) {
            capture.read(frame);
            flip(frame, frame, 1);
            if (frame.empty()) {
                break;
            }
            imshow("frame", frame);
            colorSpace_Demo(frame);
            writer.write(frame);
            // TODO: do something....
            int c = waitKey(1);
            if (c == 27) { // 退出
                break;
            }
        }

        // release
        capture.release();
        writer.release();
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
    qd.video_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
