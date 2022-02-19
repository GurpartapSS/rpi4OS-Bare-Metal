#pragma once

#if RPI_VERSION == 4
#define PBASE 0xFE000000

#else
#define PBASE 0
#error RPI_VERSION_NOT_SUPPORTED

#endif

#define CORE_CLOCK_SPEED 1500000000
