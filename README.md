# inceptor
Defines a common interface for inceptors.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

# Description
This library abstracts away inceptor sensor specifics by defining common configuration and data sturctures and an interface class defining common methods for inceptors. This enables the designer of higher-level software to reference this class, rather than individual sensor drivers, and have a fixed interface to design against.

## Installation
CMake is used to build this library, which is exported as a library target called *inceptor*. The header is added as:

```
#include "inceptor/inceptor.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake .. -DMCU=MK66FX1M0
make
```

This will build the library. Notice that the *cmake* command includes a define specifying the microcontroller the code is being compiled for. This is required to correctly configure the code, CPU frequency, and compile/linker options. The available MCUs are:
   * MK20DX128
   * MK20DX256
   * MK64FX512
   * MK66FX1M0
   * MKL26Z64
   * IMXRT1062_T40
   * IMXRT1062_T41

These are known to work with the same packages used in Teensy products. Also switching packages is known to work well, as long as it's only a package change.

## Namespace
This library is within the namespace *bfs*.

## Class / Methods

**struct InceptorConfig** defines a structure used to configure the sensor. The data fields are:

| Name | Description |
| --- | --- |
| int32_t sampling_period_ms | The sampling period, ms |
| Inceptor throttle_en | Throttle enable configuration |
| Inceptor mode0 | Mode0 configuration |
| Inceptor mode1 | Mode1 configuration |
| Inceptor mode2 | Mode2 configuration |
| Inceptor throttle | Throttle configuration |
| Inceptor pitch | Pitch configuration |
| Inceptor roll | Roll configuration |
| Inceptor yaw | Yaw configuration |

The sampling period is how often the inceptor should provide new data. The configuration for each inceptor is a struct consisting of:

| Name | Description |
| --- | --- |
| int8_t ch | The channel number |
| std::vector<float> poly_coeff | Polyval coefficients to convert the raw input to a scaled input |


**struct InceptorData** defines a structure of data returned from the sensor. The data fields are:

| Name | Description |
| --- | --- |
| bool new_data | Whether new data was received |
| bool healthy | Whether the sensor is healthy |
| bool throttle_en | Whether throttle is enabled |
| int8_t mode0 | Mode0 switch |
| int8_t mode1 | Mode1 switch |
| int8_t mode2 | Mode2 switch |
| float throttle | Throttle input |
| float pitch | Pitch input |
| float roll | Roll input |
| float yaw | Yaw input |

**Inceptor** The *Inceptor* class defines a common interface to inceptors. It is templated with the object implementing this interface for the desired sensor. For example, the uBlox implementation may be:

```C++
bfs::Inceptor<bfs::SbusRx> inceptor(&Serial1);
```

Similar to how a pure virtual class can be used to define an interface using dynamic polymorphism, this approach uses static polymorphism.

**Inceptor(HardwareSerial &ast;bus)** creates an Inceptor object; a pointer to the Serial bus object is passed.

**bool Init(const InceptorConfig &ref)** initializes communication with the sensor and configures it. Returns true if communication is established and configuration was successful.

**bool Read(InceptorData &ast; const ptr)** reads data from the sensor. Returns true if new data was received.



