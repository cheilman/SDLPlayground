workspace(name = "dev_cheilman_sdl_playground")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# abseil
http_archive(
    name = "absl",
    strip_prefix = "abseil-cpp-master",
    urls = ["https://github.com/abseil/abseil-cpp/archive/master.zip"],
)

# Google Test
http_archive(
    name = "gtest",
    strip_prefix = "googletest-master",
    urls = ["https://github.com/google/googletest/archive/master.zip"],
)

# sdl2
http_archive(
    name = "sdl2",
    strip_prefix = "sdl2-master",
    urls = ["https://github.com/bazelregistry/sdl2/archive/master.zip"],
)
