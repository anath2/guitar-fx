
/*
Read sound data from audio input and write to audio output
*/

#include <stdio.h>
#include "portaudio.h"

#define SAMPLE_RATE    (44100)
#define NUM_CHANNELS   (2)


typedef struct
{
  float left_phase;
  float right_phase;
}
paTestData

static int patestCallback(const void *inputBuffer, const *outputBuffer,
			  unsigned long framesPerBuffer,
			  const PaStreamCallbackTimeInfo* timeinfo,
			  paStreamCallbackFlags statusFlags,
			  void *userData)
{
  // Cast user defined data to our paTestData structure
  paTestData *data = (paTestData*) userData;
  float *out = (float*) outputBuffer;

  (void) inputBuffer; /* Prevent unused variable warning */

  for(unsigned int i=0; i<framesPerBuffer; i++) {
    *out++ = data->left_phase; /* Left phase */
    *out++ = data->right_phase; /* Right phase */

    // Generate a simple sawtooth phaser between the range -1.0 to 1.0
    data->left_phase += 0.01f;
    // When the signal reaches the top, drop back down
    if(data->left_phase >= 1.0f) {
      data->left_phase -= 2.0f;
    }
    // Higher pitch so we can distinguish left and right
    data->right_phase += 0.3f;
    if(data->right_phase >= 1.0f) {
      data->right_phase -= 2.0f;
    }
  }
  return 0;
}
