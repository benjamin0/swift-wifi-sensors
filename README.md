## Swift SF Office Sensors

Setup for Swift Navigation SF office environmental sensors.

See the
[dashboard](https://app.datadoghq.com/dash/266669/photon-temperature-dashboard?live=true).

## Usage

To setup your environment, run `make setup`. This probably requires that you
have the Particle CLI installed and the right credentials.

## Temperature

To build an image and perform an OTA update for the available devices, run `make
temperature`. The current BOM uses only a few components:

- [Particle Photon](https://www.sparkfun.com/products/13774)
- [SparkFun Photon Battery Shield](https://www.sparkfun.com/products/13626)
- [2 A-Hr LiPo Battery](https://www.sparkfun.com/products/8483)
- [One Wire Digital Temperature Sensor - DS18B20](https://www.sparkfun.com/products/245)

## Webhooks

For internal dashboarding, a Photon webhook posts to DataDog using JSON Mustache
templates (ugh) . This was setup manually through the Photon webhooks
[UI](https://console.particle.io/integrations/webhooks/58d879a16e9661161490edfd),
but you can find the template in the webhooks directory.

To add new dashboard values, you will need to add a new structured payload to
the firmware image (there's currently only a "temperature" channel), a new
[webhook](https://console.particle.io/integrations/webhooks) materializing calls
out to DataDog, and a new DataDog
[dashboard](https://app.datadoghq.com/dash/list) consuming those values.
