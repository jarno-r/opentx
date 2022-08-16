## OpenTX 2.3 fork for various fixes for Turnigy 9XR Pro

### Fixed issues

* RTC not working. [#7421](https://github.com/opentx/opentx/issues/7421)
* 4-in-1 multimodule menu not working. [#8946](https://github.com/opentx/opentx/pull/8946)
* 4-in-1 multimodule telemetry not working due to missing inversion. [#8954](https://github.com/opentx/opentx/issues/8954).
* FlySky AFHDS2A frequent "telemetry lost" & "telemetry recovered" warnings on Moblite7 when disarmed. (Too small `TELEMETRY_TIMEOUT10ms`.)

### To be fixed issues

* Audio playback often fails and requires restart to recover.
  * There might be some issues with SD card reading.
  * This does not appear to be due to WD crash.
* Occasional crash when changing models. [#7772](https://github.com/opentx/opentx/issues/7772).
  * Changing to and from a model that has External RF MULTI enabled causes this. Models with external RF OFF do not crash.
  * Crashes often when turning radio on and changing from one MULTI model to another MULTI model. 
  * Longer watchdog timeout does not prevent crashes,
    even with 5s WD timeout.
  * Crashes seem to happen in EEPROM code.
  * Crashes seem to happen during eepromWaitTransferComplete(). The IRQ never fires.
  * Unable to get it to crash on 2.3.7
  * Bisection:
    * Last non-crashing commit: 860b50faa (2.3.11)
    * First crashing commit: 78dd51606 (2.3.12)
    * Inbetween commits don't build.
* Sometimes the radio crashes on startup and there's no splash screen and no audio.
* Radio hangs on startup splash screen occasionally.
* Radio hangs on shutdown splash screen occasionally.
* Companion shuts down when closing a model editor window. (Not 9XR Pro specific.)
* Companion messes up input channel sources.
  * Input sources change to ???. Switches change to P1, P2 or P3. MAX might change to CYC1.

*NOTE:* On an unexpected shutdown, sdInit() is not called. Then audio does not work. This is expected behaviour. (Although maybe it should fallback to tone generator?).

### Build instructions

There are complete build instructions for OpenTX here: [Step-by-step-guide-to-building-%28custom%29-OpenTX-firmware-under-Ubuntu-Linux](https://www.rcgroups.com/forums/showthread.php?3824801-Blog-1-Step-by-step-guide-to-building-%28custom%29-OpenTX-firmware-under-Ubuntu-Linux).

For building just the firmware under either plain Linux (Ubuntu) or WSL in windows, first install the build tools by running the following commands:
````
# Install necessary tools and libraries
sudo apt install build-essential cmake gcc lib32z1

# Install the correct ARM GCC tools. 
wget https://launchpad.net/gcc-arm-embedded/4.7/4.7-2013-q3-update/+download/gcc-arm-none-eabi-4_7-2013q3-20130916-linux.tar.bz2
tar xjf gcc-arm-none-eabi-4_7-2013q3-20130916-linux.tar.bz2
rm gcc-arm-none-eabi-4_7-2013q3-20130916-linux.tar.bz2
sudo mv gcc-arm-none-eabi-4_7-2013q3 /opt/gcc-arm-none-eabi
````

Then run the rebuild.sh script from this repo to build 9XRPRO firmware under `build-stuff` directory.

### Docker builds

* [pfeerick's fork](https://github.com/pfeerick/opentx-fw-build)
* [Original docker build project](https://github.com/vitas/opentx-docker-build)
