# Arduino RFpainter - Abusing FMCW to Paint on Your Spectrogram
A few years ago, a guy who own github username [drmpeg](https://github.com/drmpeg) wrote a nice gnuradio block which is called [gr-painter](https://github.com/drmpeg/gr-paint). This block works very well and I had some fun with it. Now, I don't have SDR which can transmit anymore, only receive (an el-cheapo RTL SDR dongle) and I want to have do that again, so, I can't. I have some AD9851 DDS modules lying araund, so I decided to implement FMCW version of gr-painter (because I can't figure out how to implement OFDM on DDS module, yet). It won't be as good as gr-painter (which is using OFDM) but i good enough for me. Sure enough the DDS module is controlled using Arduino UNO and some rather simple code.

## Requirements
* Arduino UNO
* AD9851 DDS module
* RTL-SDR dongle (to see your RF output)
* GQRX [GitHub repo](https://github.com/csete/gqrx/)
* Breadboard and some jumper wires

## Precaution
**This project will emits Radio waves**. If you don't have any proper radio license, please do this at very low power, don't put any RF power amplifier with it, and do at your own risk!

