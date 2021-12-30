# MochaPayload - a simple custom firmware
This a lite version of the [original mocha](https://github.com/dimok789/mocha) to be used with the [EnvironmentLoader](https://github.com/wiiu-env/EnvironmentLoader).

## Usage
Place the `00_mocha.rpx` in the `[ENVIRONMENT]/modules/setup` folder and run the [EnvironmentLoader](https://github.com/wiiu-env/EnvironmentLoader).
Requires [PayloadFromRPX](https://github.com/wiiu-env/PayloadFromRPX) as `sd:/wiiu/root.rpx` to support returning from the system settings.

## Patches
- You can also place a RPX as `men.rpx` in the `sd:/wiiu` folder which will replace the Wii U Menu.
- RPX redirection
- overall sd access
- wupserver and own IPC which can be used with [libiosuhax](https://github.com/wiiu-env/libiosuhax).

## Building

For building you just need [wut](https://github.com/devkitPro/wut/) installed, then use the `make` command.


## Building using the Dockerfile

It's possible to use a docker image for building. This way you don't need anything installed on your host system.

```
# Build docker image (only needed once)
docker build . -t mochapayload-builder

# make 
docker run -it --rm -v ${PWD}:/project mochapayload-builder make

# make clean
docker run -it --rm -v ${PWD}:/project mochapayload-builder make clean
```



## Credits
dimok
Maschell
orboditilt
QuarkTheAwesome