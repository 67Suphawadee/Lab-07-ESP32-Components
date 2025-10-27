#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "sensor.h"
#include "display.h" // <-- Include the new component

static const char *TAG = "LAB7-1-CHALLENGE";

void app_main(void)
{
    ESP_LOGI(TAG, "🚀 Lab 7-1 Challenge: Local Components Demo Started");
    
    // Initialize both components
    sensor_init();
    display_init();
    
    while(1) {
        // Call functions from both components
        sensor_read_data();
        sensor_check_status();
        display_update();
        
        ESP_LOGI(TAG, "----------------------------");
        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}