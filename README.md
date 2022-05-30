[![Pipeline](https://gitlab.com/bolderflight/software/inceptor/badges/main/pipeline.svg)](https://gitlab.com/bolderflight/software/inceptor/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

![Bolder Flight Systems Logo](img/logo-words_75.png)

# Inceptor
Defines a common interface for inceptors.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

# Description
This library defines what an *Inceptor* interface should look like, enabling higher level code to abstract out sensor specifics and design against this interface.

## Installation
CMake is used to build this library, which is exported as a library target called *inceptor*. The header is added as:

```
#include "inceptor/inceptor.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library and an example called *example*, which has source code located in *examples/example.cc*.

## Namespace
This library is within the namespace *bfs*.

## Class / Methods

**inline constexpr int8_t MAX_NUM_INCEPTOR_CH** defines the maximum number of inceptor channels from any one interface, currently set to 32.

**struct InceptorData** defines a structure of data returned from the sensor. The data fields are:

| Name | Description |
| --- | --- |
| bool new_data | Whether new data was received |
| bool healthy | Whether the inceptor is healthy |
| int8_t num_ch | Number of channels of data available |
| float ch[MAX_NUM_INCEPTOR_CH] | Channel data, normalized to +/-1 |

Health is determined by whether the sensor fails to read 5 times in a row at the expected sampling rate.

**Inceptors** Concepts are used to defined what an *Inceptor* compliant object looks like and provide a means to templating against an *Inceptor* interface. The required methods are:

**InceptorData inceptor_data()** This method returns the InceptorData from the last successful Read.
