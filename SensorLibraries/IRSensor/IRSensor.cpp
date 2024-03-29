// #include "tsd305.h"
// #include <Wire.h>
// #include <avr/pgmspace.h>

// // TSD305 device address
// #define TSD305_ADDR 0x1e // 0b0011110

// // TSD305 device commands
// #define TSD305_CONVERT_ADCS_COMMAND 0xaf

// #define TSD305_STATUS_BUSY_MASK 0x20
// #define TSD305_STATUS_MEMOTY_ERROR_MASK 0x04

// #define TSD305_CONVERSION_TIME 100

// #define ASSERT_STATUS(x)                                                       \
//   status = x;                                                                  \
//   if (status != tsd305_status_ok)                                              \
//     return status;

// #define LUT_AMBIENT_SIZE 22
// #define LUT_ADC_SIZE 21

// // Object temperature look up table
// static const int32_t object_temperature_lut[LUT_AMBIENT_SIZE + 1][LUT_ADC_SIZE +
//                                                                   1] PROGMEM = {
//     {0,  0,  5,  10, 15, 20, 25, 30, 35, 40, 45,
//      50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100},
//     {-20,     935975,  1202135, 1482033, 1776117, 2084843, 2408670, 2748065,
//      3103501, 3475458, 3864419, 4270880, 4695336, 5138293, 5600262, 6081756,
//      6583301, 7105426, 7648664, 8213558, 8800655, 9410506},
//     {-15,     706695,  967783,  1242348, 1530828, 1833670, 2151327, 2484255,
//      2832918, 3197786, 3579336, 3978052, 4394420, 4828936, 5282101, 5754421,
//      6246409, 6758583, 7291471, 7845600, 8421509, 9019740},
//     {-10,     474076,  730091,  999323,  1282199, 1579159, 1890644, 2217105,
//      2558995, 2916776, 3290914, 3681884, 4090164, 4516239, 4960601, 5423746,
//      5906177, 6408402, 6930938, 7474302, 8039024, 8625634},
//     {-5,      238406,  489349,  753247,  1030519, 1321597, 1626911, 1946904,
//      2282021, 2632714, 2999441, 3382665, 3782858, 4200492, 4636050, 5090020,
//      5562893, 6055169, 6567354, 7099955, 7653488, 8228477},
//     {0,       0,       245872,  504435,  776105,  1061298, 1360443, 1673967,
//      2002311, 2345917, 2705232, 3080712, 3472815, 3882009, 4308764, 4753558,
//      5216875, 5699202, 6201033, 6722870, 7265216, 7828584},
//     {5,       -240800, 0,       25323,   519295,  798606,  1091580, 1398638,
//      1720208, 2056726, 2408629, 2776363, 3160378, 3561131, 3979083, 4414703,
//      4868463, 5340840, 5832320, 6343392, 6874552, 7426298},
//     {10,      -483624, -247897, 0,       260461,  533890,  820692,  1121283,
//      1436081, 1765510, 2110002, 2469990, 2845917, 3238230, 3647379, 4073823,
//      4518025, 4980453, 5461582, 5961890, 6481861, 7021987},
//     {15,      -728077, -497420, -254857, 0,       267545,  548177,  842301,
//      1150326, 1472668, 1809746, 2161990, 2529828, 2913700, 3314047, 3731315,
//      4165961, 4618439, 5089216, 5578759, 6087544, 6616048},
//     {20,      -973729, -748144, -510916, -261662, 0,       274462,  562117,
//      863369,  1178623, 1508291, 1852789, 2212539, 2587970, 2979513, 3387607,
//      3812695, 4255225, 4715649, 5194429, 5692026, 6208909},
//     {25,      -1220128, -999615, -767719, -524070, -268291, 0,       281189,
//      575668,  883834,   1206089, 1542842, 1894504, 2261494, 2644235, 3043154,
//      3458684, 3891264,  4341338, 4809352, 5295762, 5801025},
//     {30,      -1466786, -1251346, -1024783, -786738, -536841, -274722, 0,
//      287706,  588784,   903628,   1232635,  1576210, 1934759, 2308696, 2698440,
//      3104413, 3527043,  3966766,  4424016,  4899238, 5392880},
//     {35,      -1713188, -1502819, -1281591, -1049150, -805136, -549187, -280933,
//      0,       293990,   601423,   922684,   1258170,  1608279, 1973413, 2353982,
//      2750397, 3163080,  3592449,  4038935,  4502970,  4984991},
//     {40,      -1958788, -1753491, -1537596, -1310759, -1072627,
//      -822849, -561062,  -286903,  0,        300020,   613536,
//      940935,  1282602,  1638933,  2010327,  2397185,  2799918,
//      3218936, 3654658,  4107505,  4577905},
//     {45,       -2203005, -2002779, -1792219, -1570984, -1338737,
//      -1095129, -839810,  -572423,  -292608,  0,        305772,
//      625081,   958308,   1305836,  1668054,  2045356,  2438139,
//      2846805,  3271763,  3713423,  4172201},
//     {50,       -2445228, -2250074, -2044846, -1829217, -1602853,
//      -1365415, -1116563, -855949,  -583222,  -298026,  0,
//      311221,   636007,   974733,   1327775,  1695520,  2078353,
//      2476669,  2890861,  3321334,  3768491},
//     {55,       -2684813, -2494731, -2294837, -2084811, -1864329,
//      -1633062, -1390678, -1136837, -871198,  -593414,  -303133,
//      0,        316345,   646267,   990135,   1348323,  1721207,
//      2109170,  2512599,  2931884,  3367420},
//     {60,       -2921081, -2736070, -2541511, -2337088, -2122490,
//      -1897393, -1661477, -1414409, -1155858, -885485,  -602949,
//      -307905,  0,        321119,   655812,   1004442,  1367377,
//      1744988,  2137653,  2545751,  2969666},
//     {65,       -3153319, -2973381, -2784154, -2585337, -2376620,
//      -2157696, -1928246, -1687951, -1436487, -1173526, -898737,
//      -611780,  -312316,  0,        325518,   664590,   1017576,
//      1384836,  1766736,  2163646,  2575941},
//     {70,       -3380782, -3205915, -3022022, -2828808, -2625975,
//      -2413221, -2190238, -1956716, -1712341, -1456792, -1189747,
//      -910879,  -619856,  -316343,  0,        329515,   672552,
//      1029460,  1400596,  1786318,  2186992},
//     {75,       -3602685, -3432890, -3254330, -3066721, -2869771,
//      -2663187, -2446671, -2219922, -1982635, -1734498, -1475198,
//      -1204419, -921836,  -627126,  -319958,  0,        333087,
//      679644,   1040014,  1414550,  1803603},
//     {80,       -3818210, -3653487, -3480260, -3298254, -3107188,
//      -2906774, -2696726, -2476751, -2246551, -2005826, -1754271,
//      -1491580, -1217438, -931531,  -633539,  -323137,  0,
//      336205,   685812,   1049160,  1426591},
//     {85,       -4026501, -3866849, -3698957, -3522555, -3337371,
//      -3143129, -2939548, -2726345, -2503233, -2269920, -2026111,
//      -1771507, -1505806, -1228703, -939885,  -639041,  -325853,
//      0,        338843,   691003,   1056813}};

// enum status_code {
//   STATUS_OK = 0x00,
//   STATUS_ERR_OVERFLOW = 0x01,
//   STATUS_ERR_TIMEOUT = 0x02,
// };

// tsd305::tsd305(void) {
//   tsd305_coeff_read = false;
// }

// /**
//  * \brief Perform initial configuration. Has to be called once.
//  */
// void tsd305::begin(void) {
//   Wire.begin();
// }

// /**
//  * \brief Check whether TSD305 device is connected
//  *
//  * \return bool : status of TSD305
//  *       - true : Device is present
//  *       - false : Device is not acknowledging I2C address
//   */
// bool tsd305::is_connected(void) {
//   Wire.beginTransmission((uint8_t)TSD305_ADDR);
//   return (Wire.endTransmission() == 0);
// }

// /**
//  * \brief Reads the tsd305 EEPROM coefficient stored at address provided.
//  *
//  * \param[in] uint8_t : Address of coefficient in EEPROM
//  * \param[out] uint16_t* : Value read in EEPROM
//  *
//  * \return tsd305_status : status of TSD305
//  *       - tsd305_status_ok : I2C transfer completed successfully
//  *       - tsd305_status_i2c_transfer_error : Problem with i2c transfer
//  *       - tsd305_status_busy : Sensor is busy
//  *       - tsd305_status_memory_error : Sensor EEPROM memory error
//  */
// enum tsd305_status tsd305::read_eeprom_coeff(uint8_t address, uint16_t *coeff) {
//   enum tsd305_status status;
//   enum status_code i2c_status;
//   uint8_t buffer[3];
//   uint8_t status_byte = 0;
//   uint8_t i;
//   /* Read data */
//   Wire.beginTransmission((uint8_t)TSD305_ADDR);
//   Wire.write(address);
//   // Send the conversion command
//   Wire.endTransmission();
//   delay(1);

//   Wire.requestFrom((uint8_t)TSD305_ADDR, 3U);
//   for (i = 0; i < 3; i++)
//     buffer[i] = Wire.read();

//   if (i2c_status == STATUS_ERR_OVERFLOW)
//     return tsd305_status_no_i2c_acknowledge;
//   if (i2c_status != STATUS_OK)
//     return tsd305_status_i2c_transfer_error;

//   status_byte = buffer[0];
//   if (status_byte & TSD305_STATUS_BUSY_MASK)
//     return tsd305_status_busy;
//   if (status_byte & TSD305_STATUS_MEMOTY_ERROR_MASK)
//     return tsd305_status_memory_error;

//   *coeff = (buffer[1] << 8) | buffer[2];

//   return tsd305_status_ok;
// }

// /**
//  * \brief Reads the tsd305 EEPROM coefficient stored at address provided.
//  *
//  * \param[in] uint8_t : Address of coefficient in EEPROM
//  * \param[out] float* : IEEE-745 Value read in EEPROM
//  *
//  * \return tsd305_status : status of TSD305
//  *       - tsd305_status_ok : I2C transfer completed successfully
//  *       - tsd305_status_i2c_transfer_error : Problem with i2c transfer
//  *       - tsd305_status_busy : Sensor is busy
//  *       - tsd305_status_memory_error : Sensor EEPROM memory error
//  */
// enum tsd305_status tsd305::read_eeprom_float(uint8_t address, float *value) {
//   enum tsd305_status status;
//   uint16_t h_word, l_word;
//   uint32_t word;

//   ASSERT_STATUS(read_eeprom_coeff(address, &h_word));
//   ASSERT_STATUS(read_eeprom_coeff(address + 1, &l_word));

//   word = (uint32_t)h_word << 16 | l_word;
//   *value = *(float *)&word;

//   return tsd305_status_ok;
// }

// /**
//  * \brief Reads the tsd305 EEPROM coefficients to store them for computation.
//  *
//  * \return tsd305_status : status of TSD305
//  *       - tsd305_status_ok : I2C transfer completed successfully
//  *       - tsd305_status_i2c_transfer_error : Problem with i2c transfer
//  *       - tsd305_status_no_i2c_acknowledge : I2C did not acknowledge
//  *       - tsd305_status_busy : Sensor is busy
//  *       - tsd305_status_memory_error : Sensor EEPROM memory error
//  */
// enum tsd305_status tsd305::read_eeprom(void) {
//   enum tsd305_status status = tsd305_status_ok;

//   ASSERT_STATUS(read_eeprom_coeff(0x00, &eeprom_coeff.lot_number));

//   ASSERT_STATUS(read_eeprom_coeff(0x01, &eeprom_coeff.serial_number));

//   ASSERT_STATUS(read_eeprom_coeff(
//       0x1a, (uint16_t *)&eeprom_coeff.min_ambient_temperature));
//   ASSERT_STATUS(read_eeprom_coeff(
//       0x1b, (uint16_t *)&eeprom_coeff.max_ambient_temperature));
//   ASSERT_STATUS(read_eeprom_coeff(
//       0x1c, (uint16_t *)&eeprom_coeff.min_object_temperature));
//   ASSERT_STATUS(read_eeprom_coeff(
//       0x1d, (uint16_t *)&eeprom_coeff.max_object_temperature));
//   ASSERT_STATUS(read_eeprom_coeff(
//       0x2c, (uint16_t *)&eeprom_coeff.adc_calibration_factor));

//   tsd305_coeff_read = true;

//   return status;
// }

// /**
//  * \brief Retrieve data from 2D look up table in program memory
//  *
//  * \return data at given coordinates
//  */
// int32_t tsd305::get_lut_at(uint8_t x, uint8_t y) {
//   return (int32_t)pgm_read_dword(&(object_temperature_lut[x][y]));
// }

// /**
//  * \brief Triggers conversion and read ADC value
//  *
//  * \param[in] uint8_t : Command used for conversion (will determine Temperature
//  * vs Pressure and osr)
//  * \param[out] uint32_t* : ADC value.
//  *
//  * \return tsd305_status : status of TSD305
//  *       - tsd305_status_ok : I2C transfer completed successfully
//  *       - tsd305_status_i2c_transfer_error : Problem with i2c transfer
//  *       - tsd305_status_no_i2c_acknowledge : I2C did not acknowledge
//  *       - tsd305_status_busy : Sensor is busy
//  *       - tsd305_status_memory_error : Sensor EEPROM memory error
//  */
// enum tsd305_status tsd305::conversion_and_read_adcs(uint32_t *adc_object,
//                                                     uint32_t *adc_ambient) {
//   enum tsd305_status status;
//   uint8_t i2c_status;
//   uint8_t buffer[7];
//   uint8_t status_byte = 0;
//   uint8_t i;

//   /* Read data */
//   Wire.beginTransmission((uint8_t)TSD305_ADDR);
//   Wire.write((uint8_t)TSD305_CONVERT_ADCS_COMMAND);
//   i2c_status = Wire.endTransmission();
//   delay(TSD305_CONVERSION_TIME);

//   Wire.requestFrom((uint8_t)TSD305_ADDR, 7U);
//   for (i = 0; i < 7; i++)
//     buffer[i] = Wire.read();

//   // Send the conversion command

//   if (i2c_status == STATUS_ERR_OVERFLOW)
//     return tsd305_status_no_i2c_acknowledge;
//   if (i2c_status != STATUS_OK)
//     return tsd305_status_i2c_transfer_error;

//   status_byte = buffer[0];
//   if (status_byte & TSD305_STATUS_BUSY_MASK)
//     return tsd305_status_busy;
//   if (status_byte & TSD305_STATUS_MEMOTY_ERROR_MASK)
//     return tsd305_status_memory_error;

//   *adc_object = ((uint32_t)buffer[1] << 16) | ((uint32_t)buffer[2] << 8) |
//                 (uint32_t)buffer[3];
//   *adc_ambient = ((uint32_t)buffer[4] << 16) | ((uint32_t)buffer[5] << 8) |
//                  (uint32_t)buffer[6];

//   return tsd305_status_ok;
// }

// /**
//  * \brief Reads the temperature and pressure ADC value and compute the
//  * compensated values.
//  *
//  * \param[out] float* : Celsius Degree temperature value
//  * \param[out] float* : mbar pressure value
//  *
//  * \return tsd305_status : status of TSD305
//  *       - tsd305_status_ok : I2C transfer completed successfully
//  *       - tsd305_status_i2c_transfer_error : Problem with i2c transfer
//  *       - tsd305_status_no_i2c_acknowledge : I2C did not acknowledge
//  *       - tsd305_status_busy : Sensor is busy
//  *       - tsd305_status_memory_error : Sensor EEPROM memory error
//  *       - tsd305_status_out_of_range : Sensor is out of range
//  */
// enum tsd305_status
// tsd305::read_temperature_and_object_temperature(float *temperature,
//                                                 float *object_temperature) {
//   enum tsd305_status status = tsd305_status_ok;

//   uint8_t adc_ambient_lut_temperature_index = 1;
//   uint8_t adc_ambient_lut_adc_index_min = 1;
//   uint8_t adc_ambient_lut_adc_index_max = 1;
//   int32_t adc_object, adc_ambient;
//   int32_t amb_min, amb_max;
//   int32_t adc_x1, adc_x2, adc_y1, adc_y2;
//   int32_t obj_min1, obj_max1, obj_min2, obj_max2;
//   float object_temperature_min, object_temperature_max;

//   if (tsd305_coeff_read == false)
//     ASSERT_STATUS(read_eeprom());

//   ASSERT_STATUS(conversion_and_read_adcs((uint32_t *)&adc_object,
//                                          (uint32_t *)&adc_ambient));

//   *temperature = (float)adc_ambient / 16777216.0f *
//                      ((float)eeprom_coeff.max_ambient_temperature -
//                       (float)eeprom_coeff.min_ambient_temperature) +
//                  (float)eeprom_coeff.min_ambient_temperature;

//   adc_object = (int64_t)(adc_object - 8388608) *
//                eeprom_coeff.adc_calibration_factor / 1000;

//   if (*temperature > get_lut_at(1, 0) &&
//       *temperature <= get_lut_at(LUT_AMBIENT_SIZE, 0)) {
//     // Look for closest ambient temperature in LUT
//     while (*temperature > get_lut_at(adc_ambient_lut_temperature_index, 0) &&
//            adc_ambient_lut_temperature_index <= LUT_AMBIENT_SIZE + 1)
//       adc_ambient_lut_temperature_index++;

//     // Look for closest ADC value in LUT based on min possible ambient
//     // temperature
//     while (adc_object > get_lut_at(adc_ambient_lut_temperature_index - 1,
//                                    adc_ambient_lut_adc_index_min) &&
//            adc_ambient_lut_adc_index_min <= LUT_ADC_SIZE + 1)
//       adc_ambient_lut_adc_index_min++;

//     // Look for closest ADC value in LUT based on max possible ambient
//     // temperature
//     while (adc_object > get_lut_at(adc_ambient_lut_temperature_index,
//                                    adc_ambient_lut_adc_index_max) &&
//            adc_ambient_lut_adc_index_max <= LUT_ADC_SIZE + 1)
//       adc_ambient_lut_adc_index_max++;

//     amb_min = get_lut_at(adc_ambient_lut_temperature_index - 1, 0);
//     amb_max = get_lut_at(adc_ambient_lut_temperature_index, 0);

//     adc_x1 = get_lut_at(adc_ambient_lut_temperature_index - 1,
//                         adc_ambient_lut_adc_index_min - 1);
//     adc_x2 = get_lut_at(adc_ambient_lut_temperature_index - 1,
//                         adc_ambient_lut_adc_index_min);
//     adc_y1 = get_lut_at(adc_ambient_lut_temperature_index,
//                         adc_ambient_lut_adc_index_max - 1);
//     adc_y2 = get_lut_at(adc_ambient_lut_temperature_index,
//                         adc_ambient_lut_adc_index_max);

//     obj_min1 = get_lut_at(0, adc_ambient_lut_adc_index_min - 1);
//     obj_min2 = get_lut_at(0, adc_ambient_lut_adc_index_min);
//     obj_max1 = get_lut_at(0, adc_ambient_lut_adc_index_max - 1);
//     obj_max2 = get_lut_at(0, adc_ambient_lut_adc_index_max);

//     float object_temperature_min = (float)(adc_object - adc_x1) /
//                                        (float)(adc_x2 - adc_x1) *
//                                        (float)(obj_min2 - obj_min1) +
//                                    obj_min1;
//     float object_temperature_max = (float)(adc_object - adc_y1) /
//                                        (float)(adc_y2 - adc_y1) *
//                                        (float)(obj_max2 - obj_max1) +
//                                    obj_max1;

//     *object_temperature =
//         (*temperature - amb_min) / (amb_max - amb_min) *
//             (object_temperature_max - object_temperature_min) +
//         object_temperature_min;
//   } else {
//     status = tsd305_status_out_of_range;
//   }

//   return status;
// }
