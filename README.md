# ```Qbit++```

Yet another simulator for quantum computing

* [Dependencies](#dependencies)
* [Installation](#nstallation)
* [Documentation](#documentation)
* [Examples Map](#examples_map)
    
## <a name="dependencies"></a> Dependencies

- A C++17 compatible compiler
- <a href="https://www.boost.org/">Boost C++</a> libraries
- <a href="https://bitbucket.org/blaze-lib/blaze/wiki/browse/">Blaze</a> library for linear algebra
- <a href="https://github.com/google/googletest">GTest</a> if testing is enabled
- <a href="https://github.com/Neargye/magic_enum">```magic_enum```</a> only used if ```__GNUC__ >7 ```
- <a href="https://github.com/nlohmann/json">Nlohmann JSON</a> used for JSON support

## <a name="nstallation"></a> Installation

Currently you need to tweak the supplied ```CMakeLists.txt```. Specifically, you will have to
set the following variables:

- The ```BLAZE_INCL_DIR``` variable
- ```ENABLE_TESTING``` by default is set to ```ON``` and in this case you need to specify
    - ```GTEST_INC_DIR```
    - ```GTEST_LIB_DIR```
- The compilation mode ```Debug``` or ```Release```. Default is ```Debug```
- ```USE_OPENMP``` by default is ```ON``` meaning use OpenMP specification
- ```USE_LOG``` by default is ```ON``` meaning use logging
- ```MAGIC_ENUM_INCL_DIR``` if ```magic_enum``` can be supported by the compiler (```__GNUC__ >7 ```)
- The ```NLOHMANN_JSON_INCL_DIR``` variable for the ```json.hpp``` header

```
mkdir build
cd build
cmake ..
make
make install
```

## <a name="documentation"></a> Documentation

TODO


## <a name="examples_map"></a> Examples Map

TODO
