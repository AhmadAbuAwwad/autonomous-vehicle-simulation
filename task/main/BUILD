load("@rules_cc//cc:defs.bzl", "cc_binary" ,"cc_library")
cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = [
        '-fpic',
    ],
    deps = [
        "//task/mainwindow:mainwindow",       
        "//task/Driver:Driver",    
        "//task/DataStore:DataStore",       
        "//task/ClockManger:ClockManger",           
        "@qt//:qt_widgets",
        "@qt//:qt_core",
    ],
)

cc_library(
    name = "local",
    srcs = ["local.h"],
    deps = [],
    visibility = ["//visibility:public"],    
)

cc_library(
  name = "opencv",
  linkopts = [
    "-lopencv_core",
    "-lopencv_calib3d",
    "-lopencv_features2d",
    "-lopencv_highgui",
    "-lopencv_imgcodecs",
    "-lopencv_imgproc",
    "-lopencv_video",
    "-lopencv_videoio",
  ],
  visibility = ["//visibility:public"],

)

