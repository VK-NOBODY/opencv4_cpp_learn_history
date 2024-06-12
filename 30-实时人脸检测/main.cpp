#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


class QuickDemo {
public:
    void face_detection_demo() {
        std::string root_dir = "H:\\Applications\\JetBrains\\JetBrains_Documents\\JetBrains_CLionProjects\\git_opencv_report\\opencv_tutorial_data\\models\\face_detector\\";
        dnn::Net net = dnn::readNetFromTensorflow(root_dir+ "opencv_face_detector_uint8.pb", root_dir+"opencv_face_detector.pbtxt");
        VideoCapture capture("H:\\Applications\\JetBrains\\JetBrains_Documents\\JetBrains_CLionProjects\\git_opencv_report\\example_dsh.mp4");
        Mat frame;
        while (true) {
            capture.read(frame);
            if (frame.empty()) {
                break;
            }
            Mat blob = dnn::blobFromImage(frame, 1.0, Size(300, 300), Scalar(104, 177, 123), false, false);
            net.setInput(blob);// NCHW
            Mat probs = net.forward(); //
            Mat detectionMat(probs.size[2], probs.size[3], CV_32F, probs.ptr<float>());
            // 解析结果
            for (int i = 0; i < detectionMat.rows; i++) {
                float confidence = detectionMat.at<float>(i, 2);
                if (confidence > 0.5) {
                    int x1 = static_cast<int>(detectionMat.at<float>(i, 3)*frame.cols);
                    int y1 = static_cast<int>(detectionMat.at<float>(i, 4)*frame.rows);
                    int x2 = static_cast<int>(detectionMat.at<float>(i, 5)*frame.cols);
                    int y2 = static_cast<int>(detectionMat.at<float>(i, 6)*frame.rows);
                    Rect box(x1, y1, x2 - x1, y2 - y1);
                    rectangle(frame, box, Scalar(0, 0, 255), 2, 8, 0);
                }
            }
            imshow("人脸检测演示", frame);
            int c = waitKey(1);
            if (c == 27) { // 退出
                break;
            }
        }
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
    qd.face_detection_demo();

    waitKey(0);
    destroyAllWindows();
    return 0;
}
