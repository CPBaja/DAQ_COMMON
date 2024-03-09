// #ifndef __IRSENS__
// #define __IRSENS__

// #include "Arduino.h"

// enum tsd305_status {
//   tsd305_status_ok,
//   tsd305_status_no_i2c_acknowledge,
//   tsd305_status_i2c_transfer_error,
//   tsd305_status_busy,
//   tsd305_status_memory_error,
//   tsd305_status_out_of_range
// };

// class tsd305 {
// public:
//   // Functions
//   tsd305();

//   /**
//    * \brief Perform initial configuration. Has to be called once.
//    */
//   void begin();

//   /**
//   * \brief Check whether TSD305 device is connected
//   *
//   * \return bool : status of TSD305
//   *       - true : Device is present
//   *       - false : Device is not acknowledging I2C address
//   */
//   bool is_connected(void);

//   /**
//    * \brief Reads the temperature and pressure ADC value and compute the
//    * compensated values.
//    *
//    * \param[out] float* : Celsius Degree temperature value
//    * \param[out] float* : mbar pressure value
//    *
//    * \return tsd305_status : status of TSD305
//    *       - tsd305_status_ok : I2C transfer completed successfully
//    *       - tsd305_status_i2c_transfer_error : Problem with i2c transfer
//    *       - tsd305_status_no_i2c_acknowledge : I2C did not acknowledge
//    *       - tsd305_status_busy : Sensor is busy
//    *       - tsd305_status_memory_error : Sensor EEPROM memory error
//    */
//   enum tsd305_status
//   read_temperature_and_object_temperature(float *temperature,
//                                           float *object_temperature);

// private:
//   /**
//    * \brief Reads the tsd305 EEPROM coefficient stored at address provided.
//    *
//    * \param[in] uint8_t : Address of coefficient in EEPROM
//    * \param[out] uint16_t* : Value read in EEPROM
//    *
//    * \return tsd305_status : status of TSD305
//    *       - tsd305_status_ok : I2C transfer completed successfully
//    *       - tsd305_status_i2c_transfer_error : Problem with i2c transfer
//    *       - tsd305_status_busy : Sensor is busy
//    *       - tsd305_status_memory_error : Sensor EEPROM memory error
//    */

//   enum tsd305_status read_eeprom_coeff(uint8_t address, uint16_t *coeff);
//   /**
//    * \brief Reads the tsd305 EEPROM coefficient stored at address provided.
//    *
//    * \param[in] uint8_t : Address of coefficient in EEPROM
//    * \param[out] float* : IEEE-745 Value read in EEPROM
//    *
//    * \return tsd305_status : status of TSD305
//    *       - tsd305_status_ok : I2C transfer completed successfully
//    *       - tsd305_status_i2c_transfer_error : Problem with i2c transfer
//    *       - tsd305_status_busy : Sensor is busy
//    *       - tsd305_status_memory_error : Sensor EEPROM memory error
//    */

//   enum tsd305_status read_eeprom_float(uint8_t address, float *value);
//   /**
//    * \brief Triggers conversion and read ADC value
//    *
//    * \param[in] uint8_t : Command used for conversion (will determine
//    * Temperature vs Pressure and osr)
//    * \param[out] uint32_t* : ADC value.
//    *
//    * \return tsd305_status : status of TSD305
//    *       - tsd305_status_ok : I2C transfer completed successfully
//    *       - tsd305_status_i2c_transfer_error : Problem with i2c transfer
//    *       - tsd305_status_no_i2c_acknowledge : I2C did not acknowledge
//    *       - tsd305_status_busy : Sensor is busy
//    *       - tsd305_status_memory_error : Sensor EEPROM memory error
//    */

//   enum tsd305_status conversion_and_read_adcs(uint32_t *adc_object,
//                                               uint32_t *adc_ambient);
//   /**
//    * \brief Reads the tsd305 EEPROM coefficients to store them for computation.
//    *
//    * \return tsd305_status : status of TSD305
//    *       - tsd305_status_ok : I2C transfer completed successfully
//    *       - tsd305_status_i2c_transfer_error : Problem with i2c transfer
//    *       - tsd305_status_no_i2c_acknowledge : I2C did not acknowledge
//    *       - tsd305_status_busy : Sensor is busy
//    *       - tsd305_status_memory_error : Sensor EEPROM memory error
//    */
//   enum tsd305_status read_eeprom(void);

//   /**
//    * \brief Retrieve data from 2D look up table in program memory
//    *
//    * \return data at given coordinates
//    */
//   int32_t get_lut_at(uint8_t x, uint8_t y);

//   bool tsd305_coeff_read;
//   struct {
//     uint16_t lot_number;
//     uint16_t serial_number;

//     int16_t min_ambient_temperature;
//     int16_t max_ambient_temperature;
//     int16_t min_object_temperature;
//     int16_t max_object_temperature;

//     int16_t adc_calibration_factor;

//   } eeprom_coeff;
// };
