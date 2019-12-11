/**
 *@diodesDriver.c
 *@Created on: 24.04.2018
 *@Author: KamilM
 *
 *@brief Source code of diodes driver working at STM32F407
 */
#include "stm32f4xx.h"
#include <GPIODriver.h>
#include "defGPIO.h"
#include "diodesDriver.h"

static void setDiode1(uint8_t state);
static void setDiode2(uint8_t state);
static void setDiode3(uint8_t state);
static void setDiode4(uint8_t state);
static void setDiode5(uint8_t state);
static void setDiode6(uint8_t state);

static void setDiode1(uint8_t state)
{
  gpioPinSetState(Diode1_port, Diode1_pin, state);
}

static void setDiode2(uint8_t state)
{
  gpioPinSetState(Diode2_port, Diode2_pin, state);
}

static void setDiode3(uint8_t state)
{
  gpioPinSetState(Diode3_port, Diode3_pin, state);
}

static void setDiode4(uint8_t state)
{
  gpioPinSetState(Diode4_port, Diode4_pin, state);
}

static void setDiode5(uint8_t state)
{
  gpioPinSetState(Diode5_port, Diode5_pin, state);
}

static void setDiode6(uint8_t state)
{
  gpioPinSetState(Diode6_port, Diode6_pin, state);
}

void setDiodes(uint8_t numOfDiodes)
{
  switch(numOfDiodes)
  {
    case 0:
    {
      setDiode1(0);
      setDiode2(0);
      setDiode3(0);
      setDiode4(0);
      setDiode5(0);
      setDiode6(0);
      break;
    }
    case 1:
    {
      setDiode1(1);
      setDiode2(0);
      setDiode3(0);
      setDiode4(0);
      setDiode5(0);
      setDiode6(0);
      break;
    }
    case 2:
    {
      setDiode1(1);
      setDiode2(1);
      setDiode3(0);
      setDiode4(0);
      setDiode5(0);
      setDiode6(0);
      break;
    }
    case 3:
    {
      setDiode1(1);
      setDiode2(1);
      setDiode3(1);
      setDiode4(0);
      setDiode5(0);
      setDiode6(0);
      break;
    }
    case 4:
    {
      setDiode1(1);
      setDiode2(1);
      setDiode3(1);
      setDiode4(1);
      setDiode5(0);
      setDiode6(0);
      break;
    }
    case 5:
    {
      setDiode1(1);
      setDiode2(1);
      setDiode3(1);
      setDiode4(1);
      setDiode5(1);
      setDiode6(0);
      break;
    }
    case 6:
    {
      setDiode1(1);
      setDiode2(1);
      setDiode3(1);
      setDiode4(1);
      setDiode5(1);
      setDiode6(1);
      break;
    }
  }
}
