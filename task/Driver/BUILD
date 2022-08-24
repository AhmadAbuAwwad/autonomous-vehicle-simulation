load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Driver",
    srcs = ["Driver.cpp"],
    hdrs = ["Driver.h"],
    deps = [      
        "//task/GpsReader:GpsReader",       
        "//task/ImageReader:ImageReader",     
        "//task/OneValueReader:OneValueReader",   
        "//task/main:local",              
        "//task/main:opencv", 
    ],
    visibility = ["//visibility:public"],    
)