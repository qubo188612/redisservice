from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class semi_Recipe(ConanFile):
    name = "redisservice"
    version = "1.0.0"
    package_type = "library"

    # Optional metadata
    license = "<Put the package license here>"
    author = ""
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of redisservice package here>"
    topics = (" redisservice", "...")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False], "gpu_support": [True, False]}
    default_options = {"shared": False, "fPIC": True, "gpu_support": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def package_id(self):
        #忽略编译器信息
        self.info.settings.rm_safe("compiler.version")

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def layout(self):
        cmake_layout(self)
    
    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        # 根据 Conan 选项设置 CMake 变量
        if self.options.gpu_support:
            tc.variables["GPU_SUPPORT"] = "ON"
        else:
            tc.variables["GPU_SUPPORT"] = "OFF"
        tc.generate()

    def build(self):
        cmake = CMake(self)
        #用于在CMakeLists区分是实时调试还是打包发布
        cmake.configure(cli_args=["-DCONAN_CREATE_BUILD=1"])
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["redisservice"]
        
    def requirements(self):
        self.requires("alg_base_common/[^1.2.10]")
        self.requires("syopencv/4.6.0")
        self.requires("hiredis/[^1.0.0]")
        self.requires("redis_plus_plus/[^1.0.0]")
        if self.options.gpu_support:
            self.requires("sycuda/11.0.0")

