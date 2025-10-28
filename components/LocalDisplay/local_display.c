#include <stdio.h>
#include "esp_log.h"
#include "local_display.h" // Changed header

static const char *TAG = "LOCAL_DISPLAY"; // Changed TAG
static int update_count = 0;

void local_display_init(void) // Renamed function
{
    ESP_LOGI(TAG, "🖥️ Local Display component initialized");
}

void local_display_update(void) // Renamed function
{
    update_count++;
    ESP_LOGI(TAG, "🔄 Local Display updated (count: %d)", update_count);
}