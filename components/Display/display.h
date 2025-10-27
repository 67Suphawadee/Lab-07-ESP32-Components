#ifndef DISPLAY_H
#define DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize display component
 */
void display_init(void);

/**
 * @brief Update display with new information
 */
void display_update(void);

#ifdef __cplusplus
}
#endif

#endif // DISPLAY_H
