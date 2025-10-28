idf_component_register(SRCS "sensor.c"
                       INCLUDE_DIRS "include"
                       REQUIRES "log" PRIV_REQUIRES "esp_driver_gpio")