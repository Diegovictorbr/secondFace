#include <jni.h>
#include <dlib\image_processing.h>
#include <dlib\image_processing\frontal_face_detector.h>
#include <dlib\image_processing\render_face_detections.h>
#include <dlib\image_processing\generic_image.h>
#include <dlib\image_processing\full_object_detection.h>
#include <dlib\opencv.h>
#include <dlib\geometry.h>
#include <dlib\image_transforms.h>
#include <dlib\serialize.h>
#include <dlib\gui_widgets.h>
#include <dlib\image_io.h>

extern "C" {
struct membuf : std::streambuf
{
    membuf(char* begin, char* end) {
        this->setg(begin, begin, end);
    }
};


JNIEXPORT jstring JNICALL
Java_br_edu_infnet_test16_MainActivity_stringFromJNI(JNIEnv *env, jobject daobj,
                                                     jbyteArray fileBytes,
                                                     jint fileSize) {
    dlib::shape_predictor spredictor;

    jboolean isCopy = true;
    jbyte * a = env->GetByteArrayElements(fileBytes, &isCopy);
    char* teste = (char *) a;

    std::ifstream in;
    in.read(teste, fileSize);

    try {
        dlib::deserialize(spredictor, in);
    } catch (dlib::serialization_error &serializationError) {
        //Error deserializing object of type int
        std::cout << "ERROR: " << serializationError.what();
    }

    in.close();
    env->ReleaseByteArrayElements(fileBytes, a, JNI_ABORT);

    const char *cppString = "Diego";
    jstring javaString = env->NewStringUTF(cppString);
    return javaString;


    //    char *convertedFileBytes = (char *) malloc(fileSize);
//    env->SetByteArrayRegion(fileBytes, 0, fileSize, reinterpret_cast<jbyte *>(convertedFileBytes));

    //    char* teste = reinterpret_cast<char *>(malloc(fileSize));
//    memcpy(teste, a, strlen((const char*)a));

//    membuf sbuf(teste, teste + fileSize);
//    std::istream in(&sbuf);

//    env->ReleaseByteArrayElements(fileBytes, input_buf, 0);
//    jbyte * copiedData = env->GetByteArrayElements(jArray, &shouldCopy);
//    Detector d;
//    Swapper s;
//    const char *nativeFileName = env->GetStringUTFChars(fileName, JNI_FALSE);
//    env->ReleaseByteArrayElements(jArray, copiedData, JNI_ABORT);
//    env->ReleaseStringUTFChars(fileName, nativeFileName);
//    cv::Mat *mat = new cv::Mat();
//    dlib::frontal_face_detector faceDetector = dlib::get_frontal_face_detector();
//    dlib::cv_image<dlib::bgr_pixel> dlibFrame;

//    const char *name = (*env).GetStringUTFChars(env, SUAJSTRING, NULL);
//    char msg[60] = "Hello ";
//    jstring result;
//
//    strcat(msg, name);
//    (*env).ReleaseStringUTFChars(env,SUAJSTRING, name);
//    puts(msg);
//    result = (*env).NewStringUTF(env,msg);

//    PRINTAR MSG NO CONSOLE
//    const char *nativeString = (*env)->GetStringUTFChars(env, javaString, 0);
//    printf("%s", nativeString);
//    (*env)->ReleaseStringUTFChars(env, javaString, nativeString);

}
}