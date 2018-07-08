
/*
Read sound data from audio input and write to audio output
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "portaudio.h"

#define SAMPLE_RATE         (44100)
#define FRAMES_PER_BUFFER   (1024)
#define NUM_CHANNELS        (2)
#define NUM_SECONDS         (15) //@todo: Modify this function making it infinite later on
#define DITHER_FLAG         (0) //@note: https://en.wikipedia.org/wiki/Dither


#define PA_SAMPLE_TYPE      paFloat32
#define SAMPLE_SIZE         (4)
#define SAMPLE_SILENCE      (0.0f)
#define CLEAR(a)            memset((a), 0, FRAMES_PER_BUFFER * SAMPLE_RATE * NUM_CHANNELS)
#define PRINT_S_FORMAT      "%.8f"

void read_write_wire()
{
  PaStreamParameters inputParameters, outputParameters;
  PaStream *stream = NULL;
  PaError err;
  char *sampleBlock;

  int numBytes = FRAMES_PER_BUFFER * NUM_CHANNELS * SAMPLE_SIZE;
  char *sampleBlock = (char *) malloc(numBytes); // A bloc of samples

  if(numBytes == NULL)
  {
    printf("Could not allocate memory\n");
    exit(1);
  }
  CLEAR(sampleBlock);

  err = Pa_Initialize();
  if (err != paNoError) goto Error;

  inputParameters.device = Pa_GetDefaultInputDevice();
  printf("Input device # %d.\n", inputParameters.device);
  inputParameters.channelCount = NUM_CHANNELS;
  inputParameters.sampleFormat = PA_SAMPLE_TYPE;
  inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultHighLatencyInput;
  inputParameters.hostApiSpecificStreamInfo = NULL;

  outputParameters.device = Pa_GetDefaultOutputDevice();
  printf("Input device # %d.\n", outputParameters.device);
  outputParameters.channelCount = NUM_CHANNELS;
  outputParameters.sampleFormat = PA_SAMPLE_TYPE;
  outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultHighLatencyOutput;
  outputParameters.hostApiSpecificStreamInfo = NULL;


  // WIP -------------










}
