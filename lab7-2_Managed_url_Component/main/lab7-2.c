#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "sensor.h"
#include "local_display.h" // <-- Changed include

static const char *TAG = "LAB7-2-CHALLENGE";

void app_main(void)
{
    ESP_LOGI(TAG, "🚀 Lab 7-2 Challenge: Managed (URL) + Local Components Demo");
    ESP_LOGI(TAG, "📥 Using 'Sensors' component from GitHub");
    ESP_LOGI(TAG, "🖥️ Using 'LocalDisplay' component from local '../components' folder");

    // Initialize both components
    sensor_init();
    local_display_init(); // <-- Changed function call
    
    int reading_count = 0;
    
    while(1) {
        reading_count++;
        ESP_LOGI(TAG, "📋 Reading #%d", reading_count);
        
        // Call functions from both components
        sensor_read_data();
        sensor_check_status();
        local_display_update(); // <-- Changed function call
        
        ESP_LOGI(TAG, "==========================================");
        vTaskDelay(pdMS_TO_TICKS(4000));
    }
}
