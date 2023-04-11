#include "cmsis_os.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include "radioenge_modem.h"
#include "uartRingBufDMA.h"

extern osTimerId_t PeriodicSendTimerHandle;
extern osThreadId_t AppSendTaskHandle;
extern ADC_HandleTypeDef hadc1;
extern osEventFlagsId_t ModemStatusFlagsHandle;
extern osMessageQueueId_t TemperatureQueueHandle;
char msg[256];
char strrr[50] = "GeeksforGeeks";

void LoRaWAN_RxEventCallback(uint8_t *data, uint32_t length, uint32_t port, int32_t rssi, int32_t snr){
}

void AppSendTaskCode(void *argument){
    //uint32_t read;
    //TEMPERATURE_OBJ_t data;
    TEMPERATURE_OBJ_t rcv_data;
    //data.seq_no = 0;
    //int32_t temp_oCx100;
    osStatus_t status;
    
    while (1){
        status = osMessageQueueGet(TemperatureQueueHandle, &rcv_data, NULL, osWaitForever); // Wait msg
        if (status == osOK){
            sprintf(msg,"Breno [%d]: %d.%d oC\n",rcv_data.seq_no,rcv_data.temp_oCx100/100,rcv_data.temp_oCx100%100);
            LoRaSend(1,msg);
        }
    }
}

void ReadFromADCTaskCode(void *argument)
{
    uint32_t read;
    int32_t temp_oCx100;
    TEMPERATURE_OBJ_t data;
    data.seq_no = 0;
    while (1){
        // read LM35 Temperature
        HAL_ADC_Start(&hadc1);
        HAL_ADC_PollForConversion(&hadc1, 100);
        read = HAL_ADC_GetValue(&hadc1);
        data.seq_no ++;
        data.temp_oCx100 = (int32_t)(33000 * ((float)read / 4096));
        // Send Message
        osMessageQueuePut(TemperatureQueueHandle, &data, 0U, osWaitForever);
        osDelay(10000);
    }
}