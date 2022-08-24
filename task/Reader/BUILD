load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "Reader",
    srcs = ["Reader.cpp"],
    hdrs = ["Reader.h"],
    deps = [
        "//task/main:opencv",        
        "//task/main:local",        
        "//task/DataStore:DataStore",       
        "//task/ClockManger:ClockManger",     
        "//task/Types:Types",     
    ],
    visibility = ["//visibility:public"],
)