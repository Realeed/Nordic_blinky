/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

 /* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   100

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)

#if DT_NODE_HAS_STATUS(LED0_NODE, okay)
#define LED0	DT_GPIO_LABEL(LED0_NODE, gpios)
#define PIN	DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS	DT_GPIO_FLAGS(LED0_NODE, gpios)
#else
/* A build error here means your board isn't set up to blink an LED. */
#error "Unsupported board: led0 devicetree alias is not defined"
#define LED0	""
#define PIN	0
#define FLAGS	0
#endif
/* The devicetree node identifier for the "led1" alias. */
#define LED1_NODE DT_ALIAS(led1)

#if DT_NODE_HAS_STATUS(LED1_NODE, okay)
#define LED1	DT_GPIO_LABEL(LED1_NODE, gpios)
#define PIN1	DT_GPIO_PIN(LED1_NODE, gpios)
#define FLAGS1	DT_GPIO_FLAGS(LED1_NODE, gpios)
#else
/* A build error here means your board isn't set up to blink an LED. */
#error "Unsupported board: led1 devicetree alias is not defined"
#define LED1	""
#define PIN1	0
#define FLAGS1	0
#endif
/* The devicetree node identifier for the "led2" alias. */
#define LED2_NODE DT_ALIAS(led2)

#if DT_NODE_HAS_STATUS(LED2_NODE, okay)
#define LED2	DT_GPIO_LABEL(LED2_NODE, gpios)
#define PIN2	DT_GPIO_PIN(LED2_NODE, gpios)
#define FLAGS2	DT_GPIO_FLAGS(LED2_NODE, gpios)
#else
/* A build error here means your board isn't set up to blink an LED. */
#error "Unsupported board: led2 devicetree alias is not defined"
#define LED2	""
#define PIN2	0
#define FLAGS2	0
#endif
/* The devicetree node identifier for the "led3" alias. */
#define LED3_NODE DT_ALIAS(led3)

#if DT_NODE_HAS_STATUS(LED3_NODE, okay)
#define LED3	DT_GPIO_LABEL(LED3_NODE, gpios)
#define PIN3	DT_GPIO_PIN(LED3_NODE, gpios)
#define FLAGS3	DT_GPIO_FLAGS(LED3_NODE, gpios)
#else
/* A build error here means your board isn't set up to blink an LED. */
#error "Unsupported board: led2 devicetree alias is not defined"
#define LED3	""
#define PIN3	0
#define FLAGS3	0
#endif


void main(void)

{       //LED1
	const struct device* dev;
	bool led_is_on = true;
	int ret;

	dev = device_get_binding(LED0);
	if (dev == NULL) {
		return;
	}

	ret = gpio_pin_configure(dev, PIN, GPIO_OUTPUT_ACTIVE | FLAGS);
	if (ret < 0) {
		return;
	}

	//LED2
	const struct device* dev1;
	bool led_is_on1 = true;
	int ret1;

	dev1 = device_get_binding(LED1);
	if (dev1 == NULL) {
		return;
	}

	ret1 = gpio_pin_configure(dev1, PIN1, GPIO_OUTPUT_ACTIVE | FLAGS1);
	if (ret1 < 0) {
		return;
	}

	//LED3
	const struct device* dev2;
	bool led_is_on2 = true;
	int ret2;

	dev2 = device_get_binding(LED2);
	if (dev2 == NULL) {
		return;
	}

	ret2 = gpio_pin_configure(dev2, PIN2, GPIO_OUTPUT_ACTIVE | FLAGS2);
	if (ret2 < 0) {
		return;
	}

	//LED4
	const struct device* dev3;
	bool led_is_on3 = true;
	int ret3;

	dev3 = device_get_binding(LED3);
	if (dev3 == NULL) {
		return;
	}

	ret3 = gpio_pin_configure(dev3, PIN3, GPIO_OUTPUT_ACTIVE | FLAGS3);
	if (ret3 < 0) {
		return;
	}

	while (1) {
		gpio_pin_set(dev, PIN, (int)led_is_on);
		led_is_on = !led_is_on;
		gpio_pin_set(dev1, PIN1, (int)led_is_on1);
		led_is_on1 = !led_is_on1;
		gpio_pin_set(dev2, PIN2, (int)led_is_on2);
		led_is_on2 = !led_is_on2;
		gpio_pin_set(dev3, PIN3, (int)led_is_on3);
		led_is_on3 = !led_is_on3;
		k_msleep(SLEEP_TIME_MS);

	}
}