#include <cstdlib>
#include <thread>
#include "esp_log.h"
#include "driver/gpio.h"
#include <iostream>
#include <vector>
using namespace std;

extern "C" void app_main(void)
{
	std::vector<int> LED = { 23, 22, 1, 3, 21, 19, 18, 5 };

	for (std::vector<int>::iterator it = LED.begin(); it != LED.end(); ++it)
	{
		gpio_reset_pin((gpio_num_t) *it);
		gpio_set_direction((gpio_num_t) *it, GPIO_MODE_OUTPUT);
	}

	while (true)
	{
		for (std::vector<int>::iterator it = LED.begin(); it != LED.end(); ++it)
		{
			gpio_set_level((gpio_num_t) *it, 1);
			usleep(50000);
			gpio_set_level((gpio_num_t) *it, 0);
		}
		for (std::vector<int>::reverse_iterator rit = LED.rbegin(); rit != LED.rend(); ++rit)
		{
			gpio_set_level((gpio_num_t) *rit, 1);
			usleep(50000);
			gpio_set_level((gpio_num_t) *rit, 0);
		}
	}
}
