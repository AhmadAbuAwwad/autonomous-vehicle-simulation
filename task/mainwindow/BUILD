load("//tools/build_rules:qt.bzl", "qt_cc_library")

qt_cc_library(
    name = "mainwindow",
    src = "mainwindow.cpp",
    hdr = "mainwindow.h",
    copts = [
        '-fpic',
    ],
    deps = [
        "@qt//:qt_core",
        "@qt//:qt_widgets",
        "@qt//:qt_gui",
        "//task/DataStore:DataStore",               
        "//task/main:opencv",                       
    ],
    ui = "mainwindow.ui",
    ui_deps = [
        "@qt//:qt_widgets",
    ],
    visibility = ["//visibility:public"],
)
