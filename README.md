## OpenTX 2.3 fork for various fixes for Turnigy 9XR Pro

**NOTE:** There's active development on this branch and it shouldn't be used at the moment.


### Fixed issues

* RTC not working. [#7421](https://github.com/opentx/opentx/issues/7421)
* 4-in-1 multimodule menu not working. [#8946](https://github.com/opentx/opentx/pull/8946)

### Fixing issues

* 4-in-1 multimodule telemetry not working due to missing inversion. [#8954](https://github.com/opentx/opentx/issues/8954).
* FlySky AFHDS2A frequent "telemetry lost" & "telemetry recovered" warnings on Moblite7 when disarmed. (Too small `TELEMETRY_TIMEOUT10ms`.)

### To be fixed issues

* Audio playback often fails and requires restart to recover.
  * There might be some issues with SD card reading.
  * Alternatively, opentx crashes.
* Occasional crash when changing models. [#7772](https://github.com/opentx/opentx/issues/7772).
  * Changing to and from a model that has External RF MULTI enabled causes this.
  * Crashes always when turning radio on and changing from one MULTI model to another MULTI model. 
  * Does not crash after unexpected reboot from the first crash.
  * Longer watchdog timeout appears to reduce crashes somewhat, but sometimes it hangs and crashes
    even with 5s WD timeout.
  * Crashes seem to happen in EEPROM code.
  * Crashes seem to happen during eepromWaitTransferComplete(). The IRQ never fires.
  * Unable to get it to crash on 2.3.7
* Sometimes the radio crashes on startup and there's no splash screen and no audio.
* Radio hangs on startup splash screen occasionally.
* Radio hangs on shutdown splash screen occasionally.
* Companion shuts down when closing a model editor window. (Not 9XR Pro specific.)
* Companion messes up input channel sources.
  * Input sources change to ???. Switches change to P1, P2 or P3. MAX might change to CYC1.

*NOTE:* On an unexpected shutdown, sdInit() is not called. Then audio does not work. This is expected behaviour. (Although maybe it should fallback to tone generator?).

### Building
````
cmake -DDISABLE_COMPANION=ON -DSIMU_TARGET=OFF -DPCB=9XRPRO -DDEFAULT_MODE=2 -DGVARS=YES -DPPM_UNIT=US -DHELI=NO -DLUA=NO -DCMAKE_BUILD_TYPE=Release ../ && make -j`nproc` firmware
````
