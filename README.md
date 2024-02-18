# DoggyFood

* [image converter for monochrome displays](https://javl.github.io/image2cpp/) and [instructions here](https://docs.splitkb.com/hc/en-us/articles/360013811280-How-do-I-convert-an-image-for-use-on-an-OLED-display)
* [convert images for e-ink display](https://learn.adafruit.com/preparing-graphics-for-e-ink-displays?view=all)

convert "Garfield Fat.bmp" -dither FloydSteinberg -define dither:diffusion-amount=85% -remap eink___epaper_eink-3color.png -type truecolor test_tc.bmp