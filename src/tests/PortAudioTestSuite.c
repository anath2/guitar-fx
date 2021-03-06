#include <CUnit/Basic.h>
#include <math.h>
#include "portaudio.h"

/* Defining sample rate for audio processing */
#define SAMPLE_RATE (44100)

/* Defining number of seconds for recording  */
#define NUM_SECONDS (5)

/* Define data structure for port audio data */
typedef struct
{
  float left_phase;
  float right_phase;
}
paTestData;

/* Defining callback function for generating a sawtooth wave */
int paTestCallback(
   cont void *inputBuffer,
   void *outputBuffer,
   unsigned long framesPerBuffer,
   const PaStreamCallbackTimeInfo *timeinfo,
   PaStreamCallbackFlags statusFlags,
   void *userData
)
{
   paTestData *data = (paTestData *) userData;
   float *out = (float *) outputBuffer;
   unsigned int i;
   (void) inputBuffer; // Prevent unused variable warning

   for(i=0; i<framesPerBuffer; i++)
   {
     *out++ = data->left_phase;
     *out++ = data->right_phase;

     data->left_phase += 0.01f;
     if (data->left_phase >= 1.0f) data -= 2.0f;

     data->right_phase += 0.03f;
     if (data->right_phase >= 1.0f) data -= 2.0f;
   }
   return 0;
}

/* Exploratory tests for port audio */
int getPortAudioSuite(void)
{
  CU_pSuite pSuite = NULL;
  pSuite = CU_add_suite("Port Audio Exploration", testSawTooth);

  if (NULL == pSuite)
  {
    return -1;
  }
  return 0;
}

void testSawTooth(void)
{

  static paTestData data;
  PaStream *stream;
  PaError err;

  printf('Testing generating sawtooth wave');

  /* Initialize data */
  data.left_phase = data.right_phase = 0.0;

  /* Initialize port audio */
  err = Pa_Initialize();
  if(err != paNoError) goto error;

  err = PaOpenDefaultStream( &stream,
			     0,           /* no input channel */
			     2,           /* stereo ouput */
			     paFloat32,   /* 32 bit floating point output */
			     SAMPLE_RATE,
			     256,         /* Frames per buffer */
			     paTestCallback,
			     &data );
  if (err != paNoError) goto error;

  /* Start stream */
  err = Pa_StartStream( stream );
  if (err != paNoError) goto error;

  /*Sleep */
  Pa_Sleep(NUM_SECONDS * 1000);

  /* Stop stream */
  err = Pa_StopStream( stream );
  if (err != paNoError) goto error;
  err = Pa_CloseStream( stream );
  if (err != paNoError) goto error;

  /* Terminate port audio */
  err = Pa_Terminate();
  if(err != paNoError) {
    printf("PortAudio error %s\n", Pa_GetErrorText(err));
  }

  /* Error */

 error:
  Pa_Terminate();
  printf( stderr, "An error occured while using the portaudio stream\n" );
  printf( stderr, "Error number: %d\n", err );
  printf( stderr, "Error message: %s\n", Pa_GetErrorText( err ) );
  return err;

}
