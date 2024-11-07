/*
 * ThermoModel.cpp
 *
 *  Created on: 1 May 2021
 *      Author: Ralim
 */
#include "TipThermoModel.h"
#include "Utils.h"
#include "configuration.h"

#ifdef TEMP_uV_LOOKUP_HAKKO
const int32_t uVtoDegC[] = {
    //
    // uv -> temp in C
    0,     0,   //
    2369,   1, //
    4739,   2, //
    7108,   3, //
    9478,   4, //
    11847,  5, //
    14217,  6, //

};
#endif

const int uVtoDegCItems = sizeof(uVtoDegC) / (2 * sizeof(int32_t));

TemperatureType_t TipThermoModel::convertuVToDegC(uint32_t tipuVDelta) { return Utils::InterpolateLookupTable(uVtoDegC, uVtoDegCItems, tipuVDelta); }
