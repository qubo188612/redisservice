@ECHO ON
set BASEDIR=%~dp0
PUSHD %BASEDIR%
conan install .  --build=missing --settings build_type=RelWithDebInfo -o *:gpu_support=False
cmake   -DCMAKE_BUILD_TYPE=RelWithDebInfo --preset conan-default 
cd build
cmake --build . --config RelWithDebInfo
RelWithDebInfo\redisservice_test.exe
pause