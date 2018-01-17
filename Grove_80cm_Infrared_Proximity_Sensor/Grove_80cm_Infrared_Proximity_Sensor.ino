// demo of Grove - Starter V2.0
// Loovee  2013-3-10
// this demo will show you how to use Grove - Grove_80cm_Infrared_Proximity_Sensor
// Grove - 80cm_Infrared_Proximity_Sensor connect to A1
// This popular sensor made by Sharp produces an analog output that varies from 3.1V at 10cm to 0.3V at 80cm

#define IR_PROXIMITY_SENSOR A1  // Analog input pin that  is attached to the sensor
#define ADC_REF 3.3             //reference voltage of ADC is 5v.If the Vcc switch on the Seeeduino
                                //board switches to 3V3, the ADC_REF should be 3.3
float voltage;  //the sensor voltage, you can calculate or find the distance
                // to the reflective object according to the figures
                //on page 4 or page 5 of the datasheet of the GP2Y0A21YK.

void setup()
{
    // initialise serial communications at 9600 bps:
    Serial.begin(9600);
}

void loop()
{
    voltage = getVoltage();
    Serial.print("sensor voltage  = " );
    Serial.print(voltage);
    // wait 500 milliseconds before the next loop
    delay(500);
}
/****************************************************************************/
/*Function: Get voltage from the sensor pin that is connected with analog pin*/
/*Parameter:-void                                                       */
/*Return:   -float,the voltage of the analog pin                        */
float getVoltage()
{
    int sensor_value;
    int sum;
    // read the analog in value:
    for (int i = 0;i < 20;i ++)//Continuous sampling 20 times
    {
        sensor_value = analogRead(IR_PROXIMITY_SENSOR);
        sum += sensor_value;
    }
    sensor_value = sum / 20;
    float voltage;
    voltage = (float)sensor_value*ADC_REF/1024;
    return voltage;
}
