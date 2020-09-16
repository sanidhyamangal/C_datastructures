load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "linked_list",
    srcs = ["linked_list.cpp"],
    hdrs = ["linked_list.h"],
    visibility = ["//:__pkg__"],
)
cc_library(
    name = "circular_linked_list",
    srcs = ["circular_linked_list.cpp"],
    hdrs = ["circular_linked_list.h"],
    deps = [":linked_list"],
    visibility = ["//:__pkg__"],
)
cc_library(
    name = "doubly_linked_list",
    srcs = ["doubly_linked_list.cpp"],
    hdrs = ["doubly_linked_list.h"],
    deps = [":linked_list"],
    visibility = ["//:__pkg__"],
)