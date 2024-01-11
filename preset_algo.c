#include <stdio.h>
#include "stdint.h"

#define ICPZ_ONE_REVOLUTION_COUNT 262144
uint32_t SingleTurn_6001_0 = 262144;
uint32_t TotalRange_6002_0 = 0x40000000; //2^30 = 1073741824

uint32_t total_range_if_scaled(uint8_t scaling_state)
{
  uint32_t ret;
  if(scaling_state)
  {
    ret = TotalRange_6002_0;
  }
  else 
  {
    ret =  ICPZ_ONE_REVOLUTION_COUNT * 4096;
  }
  return ret;
}

int8_t preset_done_when_scaling = -1;//ADD
uint32_t offset_val = 0;

uint32_t preset_yap(uint32_t position_val,uint32_t preset_degeri, uint8_t scaling_state , uint8_t* is_preset_changed)
{
  if(*is_preset_changed)
  {
    offset_val = position_val - preset_degeri;
    printf("offset: \t\t\t%d\n",offset_val);

    *is_preset_changed = 0;

    preset_done_when_scaling = scaling_state;//ADD
  }

  uint32_t rectifier = total_range_if_scaled(scaling_state);

  uint32_t ret;
  if( (int32_t)(position_val-offset_val) < 0)
  {
    ret = position_val - offset_val + rectifier;
  }
  else
  {
    ret = position_val - offset_val;
  }

  ret = ret % rectifier;

  return ret;
}

uint32_t scale_val(uint32_t raw_val,uint8_t scaling_state)
{
  uint32_t ret;
  if(scaling_state == 1)
  {
    if(preset_done_when_scaling == 1 || preset_done_when_scaling == -1)//ADD
    {
      ret = (uint64_t)SingleTurn_6001_0 * raw_val / ICPZ_ONE_REVOLUTION_COUNT;
      ret %= TotalRange_6002_0;
    }
    else if(preset_done_when_scaling == 0)
    {
      ret = (uint64_t)ICPZ_ONE_REVOLUTION_COUNT * raw_val / ICPZ_ONE_REVOLUTION_COUNT;
      ret %= ICPZ_ONE_REVOLUTION_COUNT * 4096;
    }
  }
  else
  {
    ret = (uint64_t)ICPZ_ONE_REVOLUTION_COUNT * raw_val / ICPZ_ONE_REVOLUTION_COUNT;
    ret %= ICPZ_ONE_REVOLUTION_COUNT * 4096;
  }

  return ret;
}

#define SCALING_ENB         1
#define SCALING_DIS         0
uint32_t sensor_position = 4000;
uint32_t Position_6004_0 = 0;
uint32_t Preset_6003_0 = 100;
uint8_t scaling_status = 0;
uint8_t preset_changed = 0;


/*
Tum sorun once preset sonra scaling yapilmasindan kaynaklanmis.
Once scaling sonra preset olunca sorun ortadan kalkiyor.
*/

int main() 
{
    while(1)
    {
      printf("enter values for scaling_status(0/1) and preset_changed (0/1)");
      scanf("%d %d",&scaling_status,&preset_changed);

      printf("scaling_status: %d\n",scaling_status);
      printf("preset_changed: %d\n",preset_changed);

      printf("sensor_position : \t%d\n",sensor_position);

      if(scaling_status == 1)
      {
        SingleTurn_6001_0 = 65536;
      }
      else
      {
        SingleTurn_6001_0 = 262144;
      }

      uint32_t g1_xist1 = 0;
      g1_xist1 = scale_val(sensor_position,scaling_status);  //ST degismesiyle olceklendirme yapilir
      printf("g1_xist1 : \t\t\t%d\n",g1_xist1);

      Position_6004_0 = preset_yap(g1_xist1,Preset_6003_0,scaling_status,&preset_changed);  //preset islemleri
      printf("Position_6004_0 : \t%d\n",Position_6004_0);
    }
    

// ///////////////////////////////////////

//     printf("\nSCALING ENABLED. ST changed 16 bits instead of 18 bits\n");

//     sensor_position = 4000;
//     printf("sensor_position : \t%d\n",sensor_position);

//     preset_changed = 1;
//     scaling_status = SCALING_ENB;

//     
//     g1_xist1 = 0;
//     g1_xist1 = scale_val(sensor_position,SCALING_ENB);
//     printf("g1_xist1 : \t\t\t%d\n",g1_xist1);

//     printf("PRESET TO 1234\n");
//     Preset_6003_0 = 1234;
//     Position_6004_0 = preset_yap(g1_xist1,Preset_6003_0,scaling_status,&preset_changed);
//     printf("Position_6004_0 : \t%d\n",Position_6004_0);

    

// ///////////////////////////////////////

//     printf("\nSCALING ENABLED. ST fixed to 16 bits\n");

//     //sensor_position = 4000;
//     printf("sensor_position : \t%d\n",sensor_position);

//     preset_changed = 0;
//     scaling_status = SCALING_ENB;

//     SingleTurn_6001_0 = 65536;
//     g1_xist1 = 0;
//     g1_xist1 = scale_val(sensor_position,SCALING_ENB);
//     printf("g1_xist1 : \t\t\t%d\n",g1_xist1);

//     printf("PRESET TO 1234\n");
//     Preset_6003_0 = 1234;
//     Position_6004_0 = preset_yap(g1_xist1,Preset_6003_0,scaling_status,&preset_changed);
//     printf("Position_6004_0 : \t%d\n",Position_6004_0);

    
    return 0;
}

// int main() 
// {
    
//     printf("SCALING DISABLED.\n");

//     sensor_position = 4000;
//     printf("sensor_position : \t%d\n",sensor_position);

//     uint32_t g1_xist1 = 0;
//     g1_xist1 = scale_val(sensor_position,SCALING_DIS);  //ST degismesiyle olceklendirme yapilir
//     printf("g1_xist1 : \t\t\t%d\n",g1_xist1);

//     scaling_status = SCALING_DIS;
//     Position_6004_0 = preset_yap(g1_xist1,Preset_6003_0,scaling_status,&preset_changed);  //preset islemleri
//     printf("Position_6004_0 : \t%d\n",Position_6004_0);

// ///////////////////////////////////////

//     printf("\nSCALING ENABLED. ST changed 16 bits instead of 18 bits\n");

//     sensor_position = 4000;
//     printf("sensor_position : \t%d\n",sensor_position);

//     preset_changed = 1;
//     scaling_status = SCALING_ENB;

//     SingleTurn_6001_0 = 65536;
//     g1_xist1 = 0;
//     g1_xist1 = scale_val(sensor_position,SCALING_ENB);
//     printf("g1_xist1 : \t\t\t%d\n",g1_xist1);

//     printf("PRESET TO 1234\n");
//     Preset_6003_0 = 1234;
//     Position_6004_0 = preset_yap(g1_xist1,Preset_6003_0,scaling_status,&preset_changed);
//     printf("Position_6004_0 : \t%d\n",Position_6004_0);

    

// ///////////////////////////////////////

//     printf("\nSCALING ENABLED. ST fixed to 16 bits\n");

//     //sensor_position = 4000;
//     printf("sensor_position : \t%d\n",sensor_position);

//     preset_changed = 0;
//     scaling_status = SCALING_ENB;

//     SingleTurn_6001_0 = 65536;
//     g1_xist1 = 0;
//     g1_xist1 = scale_val(sensor_position,SCALING_ENB);
//     printf("g1_xist1 : \t\t\t%d\n",g1_xist1);

//     printf("PRESET TO 1234\n");
//     Preset_6003_0 = 1234;
//     Position_6004_0 = preset_yap(g1_xist1,Preset_6003_0,scaling_status,&preset_changed);
//     printf("Position_6004_0 : \t%d\n",Position_6004_0);

    
//     return 0;
// }
