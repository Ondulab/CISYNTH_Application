/* config.h */

#ifndef __CONFIG_H__
#define __CONFIG_H__

/**************************************************************************************
 * QSPI FLASH Definitions
 **************************************************************************************/
// (No QSPI FLASH definitions provided)

/**************************************************************************************
 * Debug Definitions
 **************************************************************************************/
//#define PRINT_IFFT_FREQUENCY
//#define PRINT_IFFT_FREQUENCY_FULL
//#define PRINT_CIS_CALIBRATION

/**************************************************************************************
 * CV Mode Definitions
 **************************************************************************************/
#define IMAGE_WEIGHT                            (25)

/**************************************************************************************
 * DAC Definitions
 **************************************************************************************/
#define SAMPLING_FREQUENCY                      (44100)
#define AUDIO_CHANNEL                           (2)
#define AUDIO_BUFFER_SIZE                       (512)

/**************************************************************************************
 * CIS Definitions
 **************************************************************************************/
#define CIS_400DPI_PIXELS_NB                    (3456)
#define CIS_200DPI_PIXELS_NB                    (1728)

// NOTE: The macro CIS_400DPI_PIXELS_PER_LANE is undefined.
// Uncomment and define it if needed:
// #define CIS_MAX_PIXELS_PER_LANE                (CIS_400DPI_PIXELS_PER_LANE)

#define UDP_MAX_NB_PACKET_PER_LINE              (12)
#define CIS_MAX_PIXELS_NB                       (CIS_400DPI_PIXELS_NB)

// Ensure UDP_LINE_FRAGMENT_SIZE is an integer
#if (CIS_MAX_PIXELS_NB % UDP_MAX_NB_PACKET_PER_LINE) != 0
    #error "CIS_MAX_PIXELS_NB must be divisible by UDP_MAX_NB_PACKET_PER_LINE."
#endif

// Size of each UDP line fragment (number of pixels per packet)
#define UDP_LINE_FRAGMENT_SIZE                  (CIS_MAX_PIXELS_NB / UDP_MAX_NB_PACKET_PER_LINE)

#define PORT                                    (55151)    // Port for incoming data
#define DEFAULT_MULTI                           "192.168.0.1"
#define DEFAULT_PORT                            PORT

/**************************************************************************************
 * DMX Definitions
 **************************************************************************************/
#define DMX_PORT                                "/dev/tty.usbserial-AD0JUL0N"
#define DMX_BAUD                                (250000)
#define DMX_CHANNELS                            (512)
#define FRAME_SIZE                              (DMX_CHANNELS + 1)

/**************************************************************************************
 * Synth Definitions
 **************************************************************************************/
// Define waveform type (options: SIN, SAW, SQR)
#define SIN

// Enable gap limiter
#define GAP_LIMITER

// Optional definitions (uncomment if needed)
//#define STEREO_1
//#define RELATIVE_MODE

#define PI                                      (3.14159265358979323846)

/**************************************************************************************
 * Wave Generation Definitions
 **************************************************************************************/
#define WAVE_AMP_RESOLUTION                     (16777215)        // Decimal value
#define VOLUME_AMP_RESOLUTION                   (65535)           // Decimal value
#define START_FREQUENCY                         (20)
#define MAX_OCTAVE_NUMBER                       (20)
#define SEMITONE_PER_OCTAVE                     (12)
#define COMMA_PER_SEMITONE                      (40)

#define VOLUME_INCREMENT                        (20)
#define VOLUME_DECREMENT                        (20)

#define PIXELS_PER_NOTE                         (1)
#define NUMBER_OF_NOTES                         (CIS_MAX_PIXELS_NB / PIXELS_PER_NOTE)

/**************************************************************************************
 * Display Definitions
 **************************************************************************************/
#define WINDOWS_WIDTH                           (CIS_MAX_PIXELS_NB)
#define WINDOWS_HEIGHT                          (1160)

#endif // __CONFIG_H__
