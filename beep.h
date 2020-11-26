#ifndef BEEP_H
#define BEEP_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
/* On Windows use the built-in Beep() function from <utilapiset.h> */
int beep(int freq, int ms) { return Beep(freq, ms); }
#elif __linux__
/* On Linux use alsa in synchronous mode, open "default" device in signed 8-bit
 * mode at 8kHz, mono, request for 20ms latency. Device is opened on first call
 * and never closed. */
#include <unistd.h>
int beep(int freq, int ms) {
  static void *pcm = NULL;
  if (pcm == NULL) {
    if (snd_pcm_open(&pcm, "default", 0, 0)) {
      return -1;
    }
    snd_pcm_set_params(pcm, 1, 3, 1, 8000, 1, 20000);
  }
  unsigned char buf[2400];
  long frames;
  long phase;
  for (int i = 0; i < ms / 50; i++) {
    snd_pcm_prepare(pcm);
    for (int j = 0; j < sizeof(buf); j++) {
      buf[j] = freq > 0 ? (255 * j * freq / 8000) : 0;
    }
    int r = snd_pcm_writei(pcm, buf, sizeof(buf));
    if (r < 0) {
      snd_pcm_recover(pcm, r, 0);
    }
  }
  return 0;
}
#elif __APPLE__
/* TODO */
#else
#error "unknown platform"
#endif

#endif /* BEEP_H */
