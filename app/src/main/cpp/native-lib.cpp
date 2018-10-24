#include <jni.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <android/asset_manager_jni.h>

using namespace cv;
using namespace std;

extern "C" {

JNIEXPORT void JNICALL
Java_com_example_coldbrew_opencvex_MainActivity_loadImage(
        JNIEnv *env,
        jobject,
        jstring imageFileName,
        jlong addrImage) {

    Mat &img_input = *(Mat *) addrImage;

    const char *nativeFileNameString = env->GetStringUTFChars(imageFileName, JNI_FALSE);

    string baseDir("/storage/emulated/0/");
    baseDir.append(nativeFileNameString);
    const char *pathDir = baseDir.c_str();

    img_input = imread(pathDir, IMREAD_COLOR);

}

JNIEXPORT void JNICALL
Java_com_example_coldbrew_opencvex_MainActivity_imageprocessing(
        JNIEnv *env,
        jobject,
        jlong addrInputImage,
        jlong addrOutputImage) {

    Mat &img_input = *(Mat *) addrInputImage;
    Mat &img_output = *(Mat *) addrOutputImage;

    cvtColor( img_input, img_input, CV_BGR2RGB);
    //cvtColor( img_input, img_output, CV_RGB2GRAY);
    //blur( img_output, img_output, Size(4,4) );//내가 무슨 헤더파일 날렸는지 이거 주석 풀면 실행안됨.
    Canny( img_input, img_output, 150, 170, 3);

}

}