from conan import ConanFile
from conan.tools.cmake import cmake_layout

class SortingAlgorithms(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def configure(self) -> None:
        """"Configuration"""
        self.options["*"].shared = False
        self.options["*"].header_only = True
        self.options["boost*"].header_only = False

    def requirements(self):
        self.requires("sfml/2.6.2")
        self.requires("boost/1.84.0")

    def layout(self):
        cmake_layout(self)