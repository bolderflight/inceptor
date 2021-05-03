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
| HardwareSerial *hw | A pointer to the serial port for SBUS |
| int32_t sampling_period_ms | The sampling period, ms |
| InceptorChannel throttle_en | Throttle enable configuration |
| InceptorChannel mode0 | Mode0 configuration |
| InceptorChannel mode1 | Mode1 configuration |
| InceptorChannel mode2 | Mode2 configuration |
| InceptorChannel throttle | Throttle configuration |
| InceptorChannel pitch | Pitch configuration |
| InceptorChannel roll | Roll configuration |
| InceptorChannel yaw | Yaw configuration |

The sampling period is how often the inceptor should provide new data, used for health monitoring. The configuration for each inceptor is a struct consisting of:

| Name | Description |
| --- | --- |
| int8_t ch | The channel number |
| int8_t num_coef | The number of polynomial coefficients |
| float poly_coeff[MAX_POLY_COEF_SIZE] | Polyval coefficients to convert the raw input to a scaled input |


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

**Inceptors** Concepts are used to defined what an *Inceptor* compliant object looks like and provide a means to templating against an *Inceptor* interface. The required methods are:

**bool Init(const InceptorConfig &ref)** Initializes communication with the sensor and configures it. Returns true if communication is established and configuration was successful.

**bool Read(InceptorData &ast; const ptr)** Reads data from the sensor. Returns true if new data was received.
