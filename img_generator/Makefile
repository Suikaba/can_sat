
INCLUDES=-I"D:/lib/boost_1_53_0" -I"D:/lib/opencv/include" -I"D:/lib/opencv/include/opencv" -I"D:/lib/opencv/modules/core/include"
INCLUDES+=-I"D:/lib/opencv/modules/highgui/include" -I"D:/lib/opencv/modules/imgproc/include" -I"D:/lib/opencv/modules/video/include"
INCLUDES+=-I"D:/lib/opencv/modules/calib3d/include" -I"D:/lib/opencv/modules/contrib/include" -I"D:/lib/opencv/modules/python/include"
INCLUDES+=-I"D:/lib/opencv/modules/features2d/include" -I"D:/lib/opencv/modules/flann/include" -I"D:/lib/opencv/modules/ml/include"
INCLUDES+=-I"D:/lib/opencv/modules/nonfree/include" -I"D:/lib/opencv/modules/photo/include" -I"D:/lib/opencv/modules/legacy/include"
INCLUDES+=-I"D:/lib/opencv/modules/objdetect/include" -I"D:/lib/opencv/modules/ocl/include" -I"D:/lib/opencv/modules/stitching/include"
INCLUDES+=-I"D:/lib/opencv/modules/superres/include" -I"D:/lib/opencv/modules/ts/include" -I"D:/lib/opencv/modules/videostab/include"
INCLUDES+=-I"D:/lib/opencv/modules/world/include"
LIBS=-L"D:/lib/opencv/build/x86/mingw/lib"
BUILD_OPT=-l"libopencv_core245" -l"libopencv_highgui245" -l"libopencv_calib3d245" -l"libopencv_contrib245" -l"libopencv_features2d245"
BUILD_OPT+=-l"libopencv_flann245" -l"libopencv_gpu245" -l"libopencv_imgproc245" -l"libopencv_legacy245" -l"libopencv_ml245"
CXX_BUILD_OPT=-std=c++0x


img_gen: main.o
	g++  -Wall -O3 -o img_gen.exe main.o $(LIBS) $(BUILD_OPT)

main.o: main.cc
	g++ -c -Wall -O3 main.cc $(INCLUDES) $(CXX_BUILD_OPT)

.PHONY: clean
clean:
	rm -r main.o img_gen.exe
