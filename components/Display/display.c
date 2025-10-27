#include <stdio.h>
#include "esp_log.h"
#include "display.h"

static const char *TAG = "DISPLAY";
static int update_count = 0;

void display_init(void)
{
    ESP_LOGI(TAG, "🖥️ Display component initialized");
}

void display_update(void)
{
    update_count++;
    ESP_LOGI(TAG, "🔄 Display updated (count: %d)", update_count);
}
