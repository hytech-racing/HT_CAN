from conan import ConanFile
import os
from shutil import which

from conan.tools.cmake import CMake, cmake_layout

class HTCan(ConanFile):
    name = "ht_can"
    version = "1.0.0"
    CANTOOLS_VERSION = "40.2.2"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    exports_sources = "CMakeLists.txt", "PCAN_project/**", "dbc_to_proto/**"

    def requirements(self):
        self.requires("protobuf/5.29.3", transitive_headers=True)

    def build_requirements(self):
        self.tool_requires("protobuf/5.29.3")

    def layout(self):
        cmake_layout(self)
        
    def build(self):
        venv_dir = os.path.join(self.build_folder, "venv")
        venv_python = os.path.join(
            venv_dir,
            "Scripts" if self.settings.os == "Windows" else "bin",
            "python",
        )
        bootstrap_python = which("python3")
        if bootstrap_python is None:
            raise RuntimeError("HT_CAN requires python3 to create its build virtualenv")

        self.run(f'"{bootstrap_python}" -m venv "{venv_dir}"')
        self.run(
            f'"{venv_python}" -m pip install --disable-pip-version-check '
            f'"cantools=={self.CANTOOLS_VERSION}"'
        )

        cmake = CMake(self)
        cmake.configure(variables={"Python3_EXECUTABLE": venv_python})
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
