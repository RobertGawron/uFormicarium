#include <stdio.h>
#include <stdint.h>

#include "gm_display_updater.h"
#include "gm_measurement_calculator.h"
#include "gm_logger.h"

__declspec(dllexport) void Lib_Simulation_Init()
{
    GMDisplayUpdater_Init();
    GMMeasurementCalculator_Init();
    GMLogger_Init();
}

__declspec(dllexport) void Lib_GMMeasurementCalculator_OnGMPulseObserved()
{
    GMMeasurementCalculator_OnGMPulseObserved();

    // dummy hack
    GMMeasurementCalculator_OnGMPulseObserved();
    GMMeasurementCalculator_OnSamplingDone();
    GMLogger_LogMeasurement();
}


__declspec(dllexport) void Lib_GMLoggerSIM_GetLoggedData(uint8_t** buffer, uint16_t* size)
{
    GMLoggerSIM_GetLoggedData(buffer, size);
}