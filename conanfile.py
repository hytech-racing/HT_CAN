from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout

class HTCan(ConanFile):
    name = "ht_can"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    exports_sources = "CMakeLists.txt", "proto/**"

    def requirements(self):
        self.requires("protobuf/5.29.3", transitive_headers=True)

    def build_requirements(self):
        self.tool_requires("protobuf/5.29.3")

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.includedirs = ["include"]
        self.cpp_info.libs = ["hytech_can_msgs_cpp_lib"]
        self.cpp_info.set_property(
            "cmake_target_name",
            "ht_can::hytech_can_msgs_cpp_lib"
        )
