load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


cc_library(
    name = "circular_linked_list",
    srcs = ["circular_linked_list.cpp"],
    hdrs = ["circular_linked_list.h"],
)
cc_library(
    name = "linked_list",
    srcs = ["linked_list.cpp"],
    hdrs = ["linked_list.h"],
)
cc_library(
    name = "doubly_linked_list",
    srcs = ["doubly_linked_list.cpp"],
    hdrs = ["doubly_linked_list.h"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//linkedlist:circular_linked_list",
        "//linkedlist:linked_list",
        "//linkedlist:doubly_linked_list"
    ],
)
