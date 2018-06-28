/*
  Read sound data from line-in and write to line-out
 */

#include <stdio.h>
#include "portaudio.h"

#define SAMPLE_RATE    (44100)
#define NUM_CHANNELS   (2)


static int recordCallBack() {
  /*
   * Record audio
  */
  return 0;
}


static int playCallBack() {
  /*
   * Play audio
   */
  return 0;
}
